#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "inc/reader.h"
#include "inc/buffer.h"
#include "inc/analyzer.h"

uint8_t systemNumberOfCores = 0;
circular_buffer cb;

void * Reader(void* arg)
{

    cpu_stats *rawdata = GetCpuTimeMemoryPool();
    if(rawdata == NULL)
    {
        printf("Msg: Error during MemoryPool allocation!\n");
        return arg;
    }
    while(1)
    {
    read_cpu_stats(rawdata, systemNumberOfCores);
    print_cpu_stats(rawdata, systemNumberOfCores);
    add_to_buffer(&cb, rawdata); 
    sleep(1);
    }
    DeallocateCpuTimeMemoryPool(rawdata);
    return arg;
}


int main()
{
   pthread_t reader_thread, analyzer_thread;
   systemNumberOfCores = sysconf(_SC_NPROCESSORS_ONLN);

   cb_init(&cb);

   pthread_create(&reader_thread, NULL, Reader, &cb);
   pthread_create(&analyzer_thread, NULL, analyzer, &cb);

   pthread_join(reader_thread, NULL);
   pthread_join(analyzer_thread, NULL);

   free(cb.buffer_raw_data);
   
  return 0;
}

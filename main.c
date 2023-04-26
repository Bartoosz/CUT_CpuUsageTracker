#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "inc/reader.h"
#include "inc/buffer.h"
circular_buffer cb;

int main()
{
   pthread_t reader_thread, analyzer_thread;
   systemNumberOfCores = sysconf(_SC_NPROCESSORS_ONLN);
   pthread_t reader_thread;
   pthread_create(&reader_thread, NULL, Reader, NULL);
   cb_init(&cb);
   pthread_create(&reader_thread, NULL, Reader, &cb);
   pthread_join(reader_thread, NULL);
  return 0;
}

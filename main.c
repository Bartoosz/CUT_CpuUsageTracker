#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "inc/reader.h"

int main (void)
{
   pthread_t reader_thread;
   pthread_create(&reader_thread, NULL, Reader, (void *) reader_thread);
   pthread_join(reader_thread, NULL);
  return 0;
}

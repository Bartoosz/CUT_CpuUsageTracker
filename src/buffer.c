#include <pthread.h>
#include "../inc/buffer.h"


void cb_init(circular_buffer *cb) 
{
    cb->buffer_raw_data = malloc(sizeof(cpu_stats) * BUF_SIZE);
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    pthread_mutex_init(&cb->mutex, NULL);
    pthread_cond_init(&cb->not_empty, NULL);
    pthread_cond_init(&cb->not_full, NULL);
    printf("buffer initialyzed\n");
}

void add_to_buffer(circular_buffer *cb, cpu_stats *rawdata) 
{
    printf("adding raw data to buffer\n");
    pthread_mutex_lock(&cb->mutex);
    while (cb->count == BUF_SIZE) {
        printf("bufsize 10, used: %d\n", cb->count);
        pthread_cond_wait(&cb->not_full, &cb->mutex);
    }
    cb->buffer_raw_data[cb->tail] = *rawdata;
    cb->tail = (cb->tail + 1) % BUF_SIZE;
    cb->count++;
    pthread_cond_signal(&cb->not_empty);
    pthread_mutex_unlock(&cb->mutex);

}

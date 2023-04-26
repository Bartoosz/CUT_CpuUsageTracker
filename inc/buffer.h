#ifndef BUFFER_H
#define BUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "reader.h"

#define BUF_SIZE 10

typedef struct {
    cpu_stats *buffer_raw_data; // tablica przechowująca dane
    int head;                   // indeks pierwszego elementu w buforze
    int tail;                   // indeks ostatniego elementu w buforze
    int count;                  // liczba elementów w buforze
    pthread_mutex_t mutex;      // mutex do synchronizacji dostępu do bufora
    pthread_cond_t not_full;    // warunek niepełnego bufora
    pthread_cond_t not_empty;   // warunek niepustego bufora
} circular_buffer;

void cb_init(circular_buffer *cb); 
void add_to_buffer(circular_buffer *cb, cpu_stats *rawdata);

#endif
#ifndef READER_H
#define READER_H

#include <stdint.h>

#define MAX_NUMBER_OF_CORES 32

//typedef unsigned long long cputime_t;

typedef struct cpuTimes_s
{
    uint64_t user;
    uint64_t nice;
    uint64_t system;
    uint64_t idle;
    uint64_t iowait;
    uint64_t irq;
    uint64_t softirq;
    uint64_t steal;
    uint64_t guest;
    uint64_t guest_nice;
} cpu_stats;

void * Reader(void *tid);

#endif
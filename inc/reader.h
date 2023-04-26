#ifndef READER_H
#define READER_H

#include <stdint.h>

#define MAX_NUMBER_OF_CORES 32
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

void * Reader(void* arg);
void print_cpu_stats(cpu_stats *rawdata, uint8_t systemNumberOfCores);
void read_cpu_stats(cpu_stats *rawdata, uint8_t systemNumberOfCores);
void DeallocateCpuTimeMemoryPool(cpu_stats *rawdata);
cpu_stats* GetCpuTimeMemoryPool();
#endif
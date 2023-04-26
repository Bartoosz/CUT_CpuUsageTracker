#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../inc/reader.h"

#define MAX_LINE_LENGTH 100

//allocate memory for store raw data from file
cpu_stats* GetCpuTimeMemoryPool()
{
    uint8_t systemNumberOfCores = sysconf(_SC_NPROCESSORS_ONLN);
    cpu_stats* cpuTimesArr = malloc(sizeof(cpu_stats) * systemNumberOfCores);
    if(cpuTimesArr == NULL)
    {
        return NULL;
    }
    memset(cpuTimesArr, 0, sizeof(cpu_stats) * systemNumberOfCores);
    return cpuTimesArr;
}

//free memory buffer
void DeallocateCpuTimeMemoryPool(cpu_stats *rawdata)
{
    free(rawdata);
    rawdata = NULL;
    if (rawdata == NULL) 
    {
        printf("The memory has been released correctly.\n");
        
    }
    else 
    {
        printf("Memory release error.\n");
        
    }
}

void read_cpu_stats(cpu_stats *rawdata, uint8_t systemNumberOfCores) 
{
    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen("/proc/stat", "r");
    if (file == NULL) 
    {
        printf("Could not open file");
        exit(EXIT_FAILURE);
    }

    //skip first line
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) 
    {
        printf("Failed to read line from file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < systemNumberOfCores; i++) 
    {
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            printf("Failed to read line from file");
            exit(EXIT_FAILURE);
        }

        sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &rawdata[i].user, &rawdata[i].nice, &rawdata[i].system, &rawdata[i].idle, &rawdata[i].iowait,
               &rawdata[i].irq, &rawdata[i].softirq, &rawdata[i].steal, &rawdata[i].guest, &rawdata[i].guest_nice);
    }
    fclose(file);
}

void print_cpu_stats(cpu_stats *rawdata, uint8_t systemNumberOfCores) 
{
    for (int i = 0; i < systemNumberOfCores; i++) 
    {
        printf("cpu%d: %ld %ld %ld %ld %ld %ld "
               "%ld %ld %ld %ld\n",
               i, rawdata[i].user, rawdata[i].nice, rawdata[i].system, rawdata[i].idle, rawdata[i].iowait,
               rawdata[i].irq, rawdata[i].softirq, rawdata[i].steal, rawdata[i].guest, rawdata[i].guest_nice);
    }
}



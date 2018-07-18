
#ifndef _LIBOS_MEASURE_H_
#define _LIOOS_MEASURE_H_

#include <stdint.h>
#include <stdio.h>

/**
 * Note: to make sure this measurement could be used in .c files (e.g., rte_XXX), no cpp things used here
 **/

/* redis/src/server.c */
#define _LIBOS_MEASURE_REDIS_SERVER_ID_BASE_ 0

/* redis/src/networking.c */
#define _LIBOS_MEASURE_REDIS_NETWORKING_ID_BASE_     10
#define _LIBOS_MEASURE_REDIS_NETWORKING_READ_ID_     ((_LIBOS_MEASURE_REDIS_NETWORKING_ID_BASE_) + 0)
#define _LIBOS_MEASURE_REDIS_NETWORKING_WRITE_ID_    ((_LIBOS_MEASURE_REDIS_NETWORKING_ID_BASE_) + 1)

/* redis/src/ae.c */
#define _LIBOS_MEASURE_REDIS_AEEPOLL_ID_BASE_        20
#define _LIBOS_MEASURE_REDIS_AEEPOLL_EPOLLWAIT_ID_   ((_LIBOS_MEASURE_REDIS_AEEPOLL_ID_BASE_) + 0)


#define MAX_RCD_NUM 100000

typedef struct _MEASURE_RCD {
    int index;
    int measure_point_ids[MAX_RCD_NUM];
    uint64_t time_ticks[MAX_RCD_NUM];
    //uint64_t start_tick[MAX_RCD_NUM];
    //uint64_t finish_tick[MAX_RCD_NUM];
}MEASURE_RCD;

/**
void display_measure_rcd(MEASURE_RCD *rcd){
    int i;
    printf("-- measurement record --\n");
    for(i = 0; i < rcd->index; i++){
        printf("index:%d measure_point_id:%d time_tick:%llu\n", i, (rcd->measure_point_ids)[i], (rcd->time_ticks)[i]);
    }
}**/

#endif
// _LIBOS_MEASURE_H_


/*************************************************************************/
// JUST FOR ILLUSTRATION
/**
 * Example rdtsc function
 *
 **/

#if 0
static inline uint64_t rdtsc(void)
{
    uint64_t eax, edx;
    __asm volatile ("rdtsc" : "=a" (eax), "=d" (edx));
    return (edx << 32) | eax;
}

// example usage: unit64_t start = rdtsc();
#endif

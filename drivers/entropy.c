#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>

int generate_entropy() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    int rand_sys = (tv.tv_sec * 1000000 + tv.tv_usec) % RAND_MAX;
    int combined_seed = (rand() ^ rand_sys) % RAND_MAX;

    srand(combined_seed);
    return rand();
}
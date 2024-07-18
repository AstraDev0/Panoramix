/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-panoramix-matthis.brocheton
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <unistd.h>

typedef struct pnrm pnrm;
struct pnrm {
    int nb_villagers;
    int pot_size;
    int save_pot_size;
    int nb_fights;
    int nb_refills;
};

typedef struct th th;
struct th {
    int id;
    pthread_t thread;
    th *next;
    th *prev;
};

    #include "proto.h"
#endif /* !PANORAMIX_H_ */

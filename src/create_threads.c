/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-panoramix-matthis.brocheton
** File description:
** create_threads
*/

#include "../include/panoramix.h"
sem_t semaphore_villager;
sem_t semaphore_druid;
sem_t semaphore_druid_wait;
pnrm pnrm_var;
pthread_mutex_t mutex;

void villager_loop(void *arg, int *nb_fight_left)
{
    sem_wait(&semaphore_villager);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    *(int*)arg, pnrm_var.pot_size);
    pnrm_var.pot_size <= 0 ? printf("Villager %d: Hey Pano wake up! \
We need more potion.\n", *(int*)arg) : 0;
    pnrm_var.pot_size <= 0 && pnrm_var.nb_refills > 0
    ? sem_post(&semaphore_druid) : 0;
    pnrm_var.pot_size <= 0 ? sem_wait(&semaphore_druid_wait) : 0;
    *nb_fight_left = *nb_fight_left - 1;
    printf("Villager %d: Take that roman scum! Only %d left.\n",
    *(int*)arg, *nb_fight_left);
    pthread_mutex_lock(&mutex);
    pnrm_var.pot_size = pnrm_var.pot_size - 1;
    pthread_mutex_unlock(&mutex);
    sem_post(&semaphore_villager);
}

void *villager(void *arg)
{
    int nb_fight_left = pnrm_var.nb_fights;

    printf("Villager %d: Going into battle!\n", *(int*)arg);
    while (nb_fight_left > 0)
        villager_loop(arg, &nb_fight_left);
    printf("Villager %d: I'm going to sleep now.\n", *(int*)arg);
    free(arg);
}

void *druid(void *arg)
{
    printf("Druid: I'm ready... but sleepy...\n");
    while (pnrm_var.nb_refills > 0) {
        sem_wait(&semaphore_druid);
        pthread_mutex_lock(&mutex);
        pnrm_var.nb_refills = pnrm_var.nb_refills - 1;
        pnrm_var.pot_size = pnrm_var.save_pot_size;
        pthread_mutex_unlock(&mutex);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can \
only make %d more refills after this one.\n", pnrm_var.nb_refills);
        sem_post(&semaphore_druid_wait);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    free(arg);
}

void *start_thread(void *arg)
{
    sem_post(&semaphore_villager);
    free(arg);
}

int create_thread(char **av)
{
    pnrm_var.nb_villagers = atoi(av[1]);
    pnrm_var.pot_size = atoi(av[2]);
    pnrm_var.save_pot_size = atoi(av[2]);
    pnrm_var.nb_fights = atoi(av[3]);
    pnrm_var.nb_refills = atoi(av[4]);
    sem_init(&semaphore_villager, 0, 0);
    sem_init(&semaphore_druid, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    loop_start_villager_and_druid(pnrm_var);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaphore_villager);
    sem_destroy(&semaphore_druid);
    return 0;
}

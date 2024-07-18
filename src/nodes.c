/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-panoramix-matthis.brocheton
** File description:
** nodes
*/

#include "../include/panoramix.h"

th *create_node(th *threads, pthread_t t)
{
    th *new_node = malloc(sizeof(th));

    new_node->thread = t;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (!threads)
        return new_node;
    new_node->prev = threads;
    threads->next = new_node;
    return new_node;
}

void delete_nodes(th *threads)
{
    th *tmp;

    if (!threads)
        return;
    tmp = threads->next;
    free(threads);
    delete_nodes(tmp);
}

void loop_start_villager_and_druid(pnrm pnrm_var)
{
    th *thread = NULL;
    pthread_t t;
    int *d;

    for (int i = pnrm_var.nb_villagers + 1; i >= 0; i--) {
        d = malloc(sizeof(int));
        *d = i - 1;
        pthread_create(&t, NULL, i == 0 ? &start_thread
        : i == pnrm_var.nb_villagers + 1 ? &druid : &villager, d);
        thread = create_node(thread, t);
    }
    while (thread) {
        pthread_join(thread->thread, NULL);
        if (!thread->prev)
            break;
        thread = thread->prev;
    }
    delete_nodes(thread);
}

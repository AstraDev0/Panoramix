/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-panoramix-matthis.brocheton
** File description:
** start
*/

#include "../include/panoramix.h"

int usage(void)
{
    printf("USAGE: ./panoramix <nb_villagers> \
<pot_size> <nb_fights> <nb_refills>");
    return 0;
}

int error(void)
{
    fprintf(stderr, "USAGE: ./panoramix <nb_villagers> \
<pot_size> <nb_fights> <nb_refills>\nValues must be >0.\n");
    return 84;
}

int start(int ac, char **av)
{
    if (ac == 1 || (ac == 2 && strcmp(av[1], "-h") == 0))
        return usage();
    if (ac != 5 || handle_error(av))
        return error();
    return create_thread(av);
}

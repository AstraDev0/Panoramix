/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-panoramix-matthis.brocheton
** File description:
** handle_error
*/

#include "../include/panoramix.h"

int is_number(char *value)
{
    for (int i = 0; value[i]; i++) {
        if (value[i] < '0' || value[i] > '9')
            return 0;
    }
    return 1;
}

int handle_error(char **av)
{
    if (is_number(av[1]) && is_number(av[2])
    && is_number(av[3]) && is_number(av[4])
    && atoi(av[1]) > 0 && atoi(av[2]) > 0
    && atoi(av[3]) > 0 && atoi(av[4]) > 0)
        return 0;
    return 1;
}

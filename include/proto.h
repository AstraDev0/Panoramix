/*
** EPITECH PROJECT, 2021
** project name
** File description:
** simple description
*/

#ifndef PROTO_H_
    #define PROTO_H_

int main(int ac, char **av);
int usage(void);
int error(void);
int start(int ac, char **av);
int is_number(char *value);
int handle_error(char **av);
th *create_node(th *threads, pthread_t t);
void delete_nodes(th *threads);
void loop_start_villager_and_druid(pnrm pnrm_var);
void *villager(void *arg);
void *druid(void *arg);
void *start_thread(void *arg);
int create_thread(char **av);

#endif /* PROTO_H_ */

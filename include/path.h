/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** path.h
*/

#ifndef PATH_H
    #define PATH_H

    #include "graph.h"

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct step_s {
    int ind;
    struct step_s *prev;
} step_t;

typedef struct linked_list_s {
    step_t *val;
    struct linked_list_s *next;
    struct linked_list_s *prev;
} linked_list_t;

typedef struct path_s {
    int len;
    step_t *steps;
} path_t;

typedef struct ant_s {
    int *seen;
    int nb_moves;
    int room;
    int id;
    path_t *path;
} ant_t;

path_t *get_path(graph_t *graph, int start, int end, int *seen);
graph_t *create_test_graph(void);
linked_list_t *create_linked_list(int val, step_t *father);
void remove_from_linked_list(linked_list_t *list, int val);
void add_to_linked_list(linked_list_t *list, int val);
step_t *create_step(int ind, step_t *father);
void free_path(path_t *path);
void revert_path(step_t **path);
void free_linked_list(linked_list_t *list);
void print_ant_path(graph_t *graph, ant_t *ant, bool *not_first_print);

ant_t *create_ant(graph_t *graph, int id);
void delete_ant(ant_t *ant);
void set_ant_path(graph_t *graph, ant_t *ant);
int move_ant(graph_t *graph, ant_t *ant, bool *not_first_print);

#endif

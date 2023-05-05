/*
** EPITECH PROJECT, 2023
** names
** File description:
** file for names functions
*/

#ifndef NAMES_H
    #define NAMES_H

    #include "tools.h"
    #include "graph.h"
    #include "parsing.h"

int add_room(graph_t *graph, char *room);
int get_room_index(graph_t *graph, char *room);
int get_room_type_index(graph_t *graph, char *room);
void set_start_end(graph_t *graph, input_t **first_input);

#endif

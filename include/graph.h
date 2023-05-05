/*
** EPITECH PROJECT, 2023
** graph
** File description:
** file for graph functions
*/

#ifndef GRAPH_H
    #define GRAPH_H

    #include <stdbool.h>

    #define GET_NODE(graph, a, b) \
        ((graph)->matrix + (b) * (graph)->size + (a))
    #define GET_ROW(graph, b) \
        ((graph)->matrix + (b) * (graph)->size)
    #define GET_STATE(graph, v) \
        ((graph)->states[(v)])

    #define SET_NODE(graph, a, b, value) \
        ((graph)->matrix[(b) * (graph)->size + (a)] = (value))

typedef enum state_e {
    OCCUPIED,
    FREE,
} state_t;

typedef enum room_state_e {
    START,
    END,
    NORMAL,
} room_state_t;

typedef struct room_states_s {
    room_state_t room_state;
    state_t state;
} room_states_t;

typedef struct graph_s {
    room_states_t *states;
    // this is the matrix for the graph full filled with
    // 1 (connected) or 0 (not connected)
    bool *matrix;
    // the name of each room in the graph
    char **names;
    // this is for the number of ants in the beginning of the program
    int ants;
    // the amount of rooms
    int size;
    int start_room;
    int end_room;
} graph_t;

graph_t *graph_create(int size, int ants);
void graph_destroy(graph_t *graph);
int get_start_room(graph_t *graph);
int get_end_room(graph_t *graph);

#endif

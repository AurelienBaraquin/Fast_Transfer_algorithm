/*
** EPITECH PROJECT, 2023
** graph
** File description:
** file for graph functions
*/

#include <malloc.h>
#include "graph.h"

graph_t *graph_create(int size, int ants)
{
    graph_t *graph = malloc(sizeof(graph_t));

    if (graph == NULL)
        return NULL;
    graph->size = size;
    graph->ants = ants;
    graph->matrix = malloc(sizeof(bool) * size * size);
    graph->states = malloc(sizeof(room_states_t) * size);
    graph->names = malloc(sizeof(char *) * (size + 1));
    if (graph->matrix == NULL)
        return NULL;
    for (int i = 0; i < size * size; i++)
        graph->matrix[i] = 0;
    for (int i = 0; i < size; i++)
        graph->states[i] = (room_states_t) {NORMAL, FREE};
    for (int i = 0; i < size; i++)
        graph->names[i] = NULL;
    return graph;
}

void graph_destroy(graph_t *graph)
{
    if (graph == NULL)
        return;
    for (int i = 0; i < graph->size; i++)
        if (graph->names[i] != NULL)
            free(graph->names[i]);
    free(graph->matrix);
    free(graph->states);
    free(graph->names);
    free(graph);
}

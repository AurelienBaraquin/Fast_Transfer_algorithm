/*
** EPITECH PROJECT, 2023
** names
** File description:
** file for names functions
*/

#include "names.h"

int add_room(graph_t *graph, char *room)
{
    int i = 0;
    char *room_name;

    for (; room[i] != ' ' && room[i]; i++);
    room[i] = '\0';
    room_name = my_strdup(room);
    for (int j = 0; j < graph->size; j++) {
        if (!graph->names[j]) {
            graph->names[j] = room_name;
            graph->names[j + 1] = NULL;
            return 0;
        }
        if (my_strcmp(graph->names[j], room_name) == 0)
            return 84;
    }
    return 84;
}

int get_room_index(graph_t *graph, char *room)
{
    for (int j = 0; j < graph->size; j++) {
        if (graph->names[j] && my_strcmp(graph->names[j], room) == 0)
            return j;
    }
    return -1;
}

int get_room_type_index(graph_t *graph, char *room)
{
    int i = 0;
    for (; room[i] != ' ' && room[i]; i++);
    room[i] = 0;
    return get_room_index(graph, room);
}

void set_start_end(graph_t *graph, input_t **first_input)
{
    input_t *tmp = *first_input;

    while (tmp != NULL) {
        if (my_strcmp(tmp->str, "##start") == 0 && tmp->next != NULL)
            GET_STATE(graph, get_room_type_index(graph, tmp->next->str))
                    .room_state = START;
        if (my_strcmp(tmp->str, "##end") == 0 && tmp->next != NULL)
            GET_STATE(graph, get_room_type_index(graph, tmp->next->str))
                    .room_state = END;
        tmp = tmp->next;
    }
}

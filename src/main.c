/*
** EPITECH PROJECT, 2022
** main
** File description:
** yes
*/

#include "parsing.h"
#include "path.h"
#include "tools.h"

#include <stdbool.h>

static int try_move_ant(graph_t *graph, ant_t **all_ants)
{
    int move_count = 0;
    int move_status;
    bool not_first_print = false;

    for (int j = 0; j < graph->ants; j++) {
        move_status = move_ant(graph, all_ants[j], &not_first_print);
        if (move_status < 0) {
            move_count = move_status;
            break;
        }
        move_count += move_status;
    }
    if (move_count >= 0 && move_count != graph->ants)
        my_putstr("\n");

    return move_count;
}

static void print_moves(graph_t *graph)
{
    ant_t **all_ants = malloc(sizeof(ant_t *) * graph->ants);

    for (int i = 0; i < graph->ants; i++)
        all_ants[i] = create_ant(graph, i + 1);
    for (int i = 0, k = 0; i != graph->ants; k++) {
        if ((i = try_move_ant(graph, all_ants)) < 0)
            break;
    }
    for (int i = 0; i < graph->ants; i++)
        delete_ant(all_ants[i]);
    free(all_ants);
}

int main(void)
{
    graph_t *graph = parse_input();

    if (graph == NULL)
        return 84;
    if (!(graph->start_room == -1 || graph->end_room == -1))
        print_moves(graph);
    graph_destroy(graph);
    return 0;
}

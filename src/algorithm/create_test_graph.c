/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** create_test_graph.c
*/

#include "graph.h"

void put_room_link(int room_from, int room_to, graph_t *graph)
{
    SET_NODE(graph, room_from, room_to, 1);
    SET_NODE(graph, room_to, room_from, 1);
}

graph_t *create_test_graph(void)
{
    graph_t *res = graph_create(8, 5);
    res->states[0].room_state = START;
    res->states[7].room_state = END;
    put_room_link(0, 4, res);
    put_room_link(1, 3, res);
    put_room_link(3, 4, res);
    put_room_link(4, 5, res);
    put_room_link(5, 2, res);
    put_room_link(6, 1, res);
    put_room_link(6, 7, res);
    put_room_link(7, 2, res);
    res->start_room = get_start_room(res);
    res->end_room = get_end_room(res);
    return res;
}

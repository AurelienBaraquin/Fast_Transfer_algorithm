/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** parsing
*/

#include "parsing.h"
#include "graph.h"
#include "tools.h"
#include "names.h"
#include <stdio.h>

void add_element_input(input_t **first_input, char *str)
{
    int str_len = my_strlen(str) - 1;
    str[str_len] = '\0';
    str = remove_comment(str);
    if (str[0] == '\0')
        return;
    while (str_len + 1 > 0 && (str[str_len] == ' ' || str[str_len] == '\t' ||
        str[str_len] == '\n'))
        str[str_len] = '\0';
    input_t *new_input = malloc(sizeof(input_t));
    input_t *tmp = *first_input;
    new_input->str = my_strdup(str);
    new_input->next = NULL;
    if (*first_input == NULL) {
        *first_input = new_input;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_input;
}

index_t get_tunnel(graph_t *graph, char *str)
{
    int len = my_strlen(str);
    index_t res;
    char str_a[len];
    char str_b[len];
    int i = 0;
    int j = 0;

    my_memset(str_a, 0, len);
    my_memset(str_b, 0, len);
    while (str[i] != '-')
        str_a[j++] = str[i++];
    i++;
    j = 0;
    while (str[i] != '\0')
        str_b[j++] = str[i++];
    res = (index_t) {get_room_index(graph, str_a),
                    get_room_index(graph, str_b)};
    return res;
}

graph_t *set_rooms_values(graph_t *graph, input_t *input, int room_type)
{
    index_t index;

    if (room_type == -1)
        return NULL;
    if (room_type == 1) {
        print_room(input->str);
        if (add_room(graph, input->str))
            return NULL;
    }
    if (room_type == 2) {
        index = get_tunnel(graph, input->str);
        print_marquee(M_TUNNELS);
        print_tunnel(index.a, index.b);
        if (index.a == -1 || index.b == -1)
            return NULL;
        SET_NODE(graph, index.a, index.b, 1);
        SET_NODE(graph, index.b, index.a, 1);
    }
    return graph;
}

graph_t* set_rooms_and_pipes(input_t **first_input, int nb_ants)
{
    graph_t *graph = graph_create(get_upper_room(first_input), nb_ants);
    input_t *tmp = *first_input;
    int room_type;

    tmp = tmp->next;
    while (tmp != NULL) {
        print_marquee(M_NO_ROOMS);
        room_type = get_room_type(tmp->str);
        if (my_strcmp(tmp->str, "##start") == 0)
            print_marquee(M_ROOM_START);
        if (my_strcmp(tmp->str, "##end") == 0)
            print_marquee(M_ROOM_END);
        set_rooms_values(graph, tmp, room_type);
        tmp = tmp->next;
    }
    set_start_end(graph, first_input);
    return graph;
}

graph_t *parse_input(void)
{
    input_t *first_input = NULL;
    size_t size = 0;
    char *str = NULL;
    while (getline(&str, &size, stdin) >= 2)
        add_element_input(&first_input, str);
    free(str);
    int nb_ants = my_getnbr(first_input->str);
    if (nb_ants <= -1)
        return NULL;
    print_marquee(M_NO_ANTS);
    my_put_nbr(nb_ants);
    my_putchar('\n');
    graph_t *graph = set_rooms_and_pipes(&first_input, nb_ants);
    graph->ants = nb_ants;
    if (graph == NULL)
        return NULL;
    graph->start_room = get_start_room(graph);
    graph->end_room = get_end_room(graph);
    return graph;
}

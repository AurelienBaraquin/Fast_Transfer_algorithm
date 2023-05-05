/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** get_all_path.c
*/

#include "path.h"
#include "graph.h"

int get_next_step(int i, graph_t *graph, int *seen, linked_list_t *actual)
{
    if (*GET_NODE(graph, actual->val->ind, i) &&
    !seen[i]) {
        add_to_linked_list(actual, i);
        return 1;
    }
    return 0;
}

int get_path_len(path_t *path)
{
    step_t *temp = path->steps;
    int i = 0;

    while (temp != NULL) {
        temp = temp->prev;
        i++;
    }
    return i;
}

path_t *get_path(graph_t *graph, int start, int end, int *seen)
{
    path_t *res = malloc(sizeof(path_t));
    linked_list_t *actual = create_linked_list(start, NULL), *cpy = actual;
    int temp[graph->size];
    for (int i = 0; i < graph->size; i++)
        temp[i] = seen[i];
    while (actual->val->ind != end) {
        temp[actual->val->ind] = 1;
        for (int i = 0; i < graph->size; i++)
            get_next_step(i, graph, temp, actual);
        actual = actual->next;
        if (actual == NULL) {
            free_linked_list(cpy);
            return NULL;
        }
    }
    res->steps = actual->val;
    res->len = get_path_len(res);
    revert_path(&res->steps);
    free_linked_list(actual);
    return res;
}

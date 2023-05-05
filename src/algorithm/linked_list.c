/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** create_linked_list.c
*/

#include "path.h"

linked_list_t *create_linked_list(int val, step_t *father)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->val = create_step(val, father);
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void add_to_linked_list(linked_list_t *list, int val)
{
    linked_list_t *temp = list;
    linked_list_t *new = create_linked_list(val, temp->val);

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    temp->next->prev = temp;
}

void remove_from_linked_list(linked_list_t *list, int val)
{
    linked_list_t *temp = list;
    linked_list_t *prev = NULL;

    if (temp->val->ind == val) {
        list = temp->next;
        list->prev = NULL;
        free(temp);
        return;
    }

    while (temp->val->ind != val) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
}

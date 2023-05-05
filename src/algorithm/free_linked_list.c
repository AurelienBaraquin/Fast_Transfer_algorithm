/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** free_linked_list.c
*/

#include "path.h"

void free_linked_list(linked_list_t *list)
{
    linked_list_t *current = list;
    linked_list_t *temp = current;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

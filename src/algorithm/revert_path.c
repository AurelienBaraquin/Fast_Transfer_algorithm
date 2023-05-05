/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** revert_path.c
*/

#include "path.h"

void revert_path(step_t** head)
{
    step_t* prev = NULL;
    step_t* curr = *head;
    step_t* next = NULL;

    while (curr != NULL) {
        next = curr->prev;
        curr->prev = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

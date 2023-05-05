/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** create_step.c
*/

#include "path.h"

step_t *create_step(int ind, step_t *father)
{
    step_t *res = malloc(sizeof(step_t));
    res->ind = ind;
    res->prev = father;
    return res;
}

/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header
*/

#ifndef PARSING_H
    #define PARSING_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include "graph.h"

typedef struct index_s {
    int a;
    int b;
} index_t;

typedef struct input_s {
    char *str;
    struct input_s *next;
} input_t;

typedef enum marquee_type_e {
    M_NO_ANTS,
    M_NO_ROOMS,
    M_ROOM_START,
    M_ROOM_END,
    M_TUNNELS,
    M_MOVES,
    __M_ENUM_END
} marquee_type_t;

graph_t *parse_input(void);
int get_room_type(char *str);
char *remove_comment(char *str);
int get_upper_room(input_t **first_input);

void print_ant_count(int ant_count);
void print_room(const char *room_desc);
void print_tunnel(int a, int b);
void print_marquee(marquee_type_t type);

#endif

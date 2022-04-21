#ifndef _LAPS_H_
#define _LAPS_H_
#include <stdio.h>
#include <stdlib.h>

/**
* struct cardef - definition of car
* @id: id of car
* @laps: laps count
* @next: pointer
*/
typedef struct cardef_s
{
    int id;
    int laps;
    struct cardef_s *next;
} cardef_t;

void race_state(int *id, size_t size);
cardef_t *add_car(cardef_t **head, int id);
cardef_t *get_car(cardef_t *head, int id);
void print_race(cardef_t *head);
void free_car(cardef_t *head);

#endif
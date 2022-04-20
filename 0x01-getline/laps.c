#include "laps.h"

/**
 * race_state - Keep track of the number of laps made by several cars in a race
 * id: array of int identifier of a car (unique)
 * size: the size of the array
 */
void race_state(int *id, size_t size)
{
    if (size == 0){
        free_memory();
    }
    // get array
    // store array element if not in keys
    // if new element add node else print state and sum 1
    // if identifier is unknown
    // create a new car with laps = 0
    // Print Car X joined the race \n X = identifier
    // Each time the function is called 
    // number of laps +1 for all cars in identifier
    // print state of race
    // HEADER Race state: \n
    // Car X [Y laps]
    // if functions is called with size = 0 free all memory
}

cardef_t *add_car(cardef_t **head, int id)
{

}
cardef_t *get_car(cardef_t *head, int id){

}
void print_car(cardef_t *head){

}
void free_car(cardef_t *head){
    
}

// int_stack.c

#include "int_stack.h"

#include <stdlib.h>
#include <stdio.h>

void int_stack_init(int_stack_t *stk, int capacity) {
    SLIST_INIT(&stk->head);
    stk->size = 0;
    stk->capacity = capacity;
}

int int_stack_push(int_stack_t *stk, int value) {
    if (stk->size >= stk->capacity) {
        printf("Stack is at full capacity.\n");
        return 0; // fail
    }

    int_entry_t *newEntry = malloc(sizeof(int_entry_t));
    if (newEntry) {
        newEntry->value = value;
        SLIST_INSERT_HEAD(&stk->head, newEntry, entries);
        stk->size++;
        return 1; //success
    }
    return 0; // fail
}

int int_stack_pop(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        int value = entry->value;
        SLIST_REMOVE_HEAD(&stk->head, entries);
        free(entry);
        stk->size--;
        *top_value = value;
        return 1; // success
    }
    return 0; // fail
}

int int_stack_top(int_stack_t *stk, int *top_value) {
    int_entry_t *entry = SLIST_FIRST(&stk->head);
    if (entry) {
        *top_value = entry->value;
        return 1; // success
    }
    return 0; // fail
}

/* Functions for FORTH langauge stack operators */

int int_stack_dup(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    int_stack_top(stk, &top_value);
    return int_stack_push(stk, top_value); // success only if last operation succeeds
}

int int_stack_swap(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); // success only if last operation succeeds
}

/* Example of how to create a binary operator that works o top two elements (if present) */


//arithmetic

int int_stack_add(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value + next_to_top_value);
}

int int_stack_subtraction(int_stack_t *stk){
	if(stk ->size < 2)
		return 0;
	int top_value, next_to_top_value;
	int_stack_pop(stk, &top_value);
	int_stack_pop(stk, &next_to_top_value);
	return int_stack_push(stk, top_value - next_to_top_value);
}

int int_stack_multiply(int_stack_t *stk){
	if(stk->size < 2)
		return 0; 
	int top_value, next_to_top_value;
	int_stack_pop(stk, &top_value);
	int_stack_pop(stk, &next_to_top_value);
	return int_stack_push(stk, top_value * next_to_top_value);
}

int int_stack_divide(int_stack_t *stk) {
	if (stk->size < 2)
		return 0;
	int top_value, next_to_top_value;
	int_stack_pop(stk, &top_value);
	int_stack_pop(stk, &next_to_top_value);
	if (next_to_top_value == 0)
		return -1; // Error code for division by zero
	return int_stack_push(stk, top_value / next_to_top_value);
}

int int_stack_divmod(int_stack_t *stk) {
	if (stk->size < 2)
		return 0;
	int divisor, dividend;
	int_stack_pop(stk, &divisor);
	int_stack_pop(stk, &dividend);
	if (divisor == 0)
		return -1; // Error code for division by zero
	int_stack_push(stk, dividend % divisor);
	return int_stack_push(stk, dividend / divisor);
}

int int_stack_mod(int_stack_t *stk) {
	if(stk->size < 2)
		return 0;
	int divisor, dividend;
	int_stack_pop(stk, &divisor);
	int_stack_pop(stk, &dividend);	
	if(divisor == 0)
		return -1; //error code for division by zero
	return int_stack_push(stk, dividend % divisor);
}

//stack manipulation 
int int_stack_over(int_stack_t *stk) {
	if(stk->size < 2)
		return -1;// error code for not enough elements 
	int n1 = stk->data[stk-<size -2];
	return int_stack_push(stk,n1);
}

int int_stack_rot(int_stack_t *stk) {
	if(stk->size < 3) 
		return -1;//error code for not enough elements 
	int top, middle, bottom;
	int stack_pop(stk, &top);
	int stack_pop(stk, &middle);
	int stack_pop(stk, &bottom);
	int stack_push(stk, middle);
	int stack_push(stk, top);
	return int_stack_push(stk, bottom);
}

int int_stack_drop(int_stack_t *stk){
	if(stk->size == 0)
		return -1;//error code for stack underflow 
	int top_value;
	return int_stack_pop(stk, &top_value);
}

//double element operations 

int int_stack_two_swap(int_stack_t *stk) {
	if(stk->size < 4)
		return -1;// error code for not enough elements 
	int d1_top, d1_bottom, d2_top, d2_bottom;
	int_stack_pop(stk, &d1_top);
	int_stack_pop(stk, &d1_bottom);
	int_stack_pop(stk, &d2_top);
	int_stack_pop(stk, &d2_bottom);
	int_stack_push(stk, d1_bottom);
	int_stack_push(stk, d1_top);
	int_stack_push(stk, d2_bottom);
	int_stack_push(stk, d2_top);
	return 0; //sucess
}

int int_stack_two_dup(int_stack_t *stk) {
	if(stk->size < 2)
		return -1; // error code for not enough elements
	int top, second_top;
	second_top = stk->data[stk->size - 2];
	top = stk->data[stk->size - 1];
	int_stack_push(stk, second_top);
	int_stack_push(stk, top);
	return 0; //sucess 
}

int int_stack_two_over(int_stack_t *stk) {
	if (stk->size < 4)
		return -1; // Error code for not enough elements
	int second_top, third_top;
	third_top = stk->data[stk->size - 3];
	second_top = stk->data[stk->size - 2];
	int_stack_push(stk, third_top);
	int_stack_push(stk, second_top);
	return 0; // Success
}

int int_stack_two_drop(int_stack_t *stk) {
	if (stk->size < 2)
		return -1; // Error code for not enough elements
	int top_value;
	int_stack_pop(stk, &top_value);
	int_stack_pop(stk, &top_value);
	return 0; // Success
}



void int_stack_print(int_stack_t *stk, FILE *file) {
    int_entry_t *entry;
    int pos = 0;
    if (stk->size == 0) {
        fprintf(file, "empty stack\n");
    }

    SLIST_FOREACH(entry, &stk->head, entries) {
        fprintf(file, "%d: %d\n", pos, entry->value);
        pos++;
    }
    printf("\n");
}

int int_stack_size(int_stack_t* stk) {
    return stk->size;
}

int int_stack_capacity(int_stack_t* stk) {
    return stk->capacity;
}


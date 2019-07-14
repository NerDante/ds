#ifndef __STACK_H__
#define __STACK_H__

#include "list.h"

// implement stacks as linked list
typedef List Stack;

// public intefaces
#define stack_init list_init
#define stack_destroy list_destroy
#define stack_size list_size
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#endif // __STACK_H__

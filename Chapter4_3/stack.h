#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct {
    element* data;
    int capacity;
    int top;
} Stack;

void init_stack(Stack* s, int size);
void delete(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s);
int string_length(const char* str);

//! postfix
int eval(char* exp);

//! infix to postfix
int prec(char op);
void infix_to_postfix(char* exp);

//! infix to postfix and eval
void infix_to_postfix_eval(char* exp, char* result);
#include "chapter4.h"

void init_stack(Stack* s) { s->top = -1; }

int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == (MAX_SIZE - 1)); }
void push(Stack* s, element item) {
    if (is_full(s)) { printf("Stack full/n"); return; }
    s->data[++(s->top)] = item;
}
element pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack empty/n");
        return NULL;
    }
    return s->data[(s->top)--];
}
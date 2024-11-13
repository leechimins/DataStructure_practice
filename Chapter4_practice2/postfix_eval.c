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
int eval(char* exp);

int main(void) {
    char exp[101];
    scanf("%s", exp);
    int result = eval(exp);
    printf("계산값은 %d\n", result);

    return 0;
}

void init_stack(Stack* s, int size) {
    s->top = -1;
    s->capacity = size;
    s->data = (element*)malloc((s->capacity) * sizeof(element));
}

void delete(Stack* s) {
    printf("Stack data free\n");
    free(s->data);
}

int is_empty(Stack* s) { return (s->top == -1); }
int is_full(Stack* s) { return (s->top == (s->capacity - 1)); }

void push(Stack* s, element item) {
    if (is_full(s)) {
        // printf("Stack full\n");
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, (s->capacity) * sizeof(element));
    }
    s->data[++(s->top)] = item;
}
element pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack empty\n");
        return NULL;
    }
    return s->data[(s->top)--];
}
element peek(Stack* s) {
    if (is_empty(s)) {
        printf("Stack empty\n");
        return NULL;
    }
    else return s->data[s->top];
}

int string_length(const char* str) {
    int len = 0;
    while (str[len++] != '\0');
    return (len - 1);
}

int eval(char* exp) {
    int op1, op2, value, len = string_length(exp);
    char ch;
    Stack s; init_stack(&s, len);

    for (int i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch)
            {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    value = pop(&s);
    delete(&s);
    return value;
}
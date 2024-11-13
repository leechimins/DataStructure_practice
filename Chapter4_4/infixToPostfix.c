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
int prec(char op);
void infix_to_postfix(char* exp);

int main(void) {
    char exp[101];
    scanf("%s", exp);
    printf("���� �������� ��ȯ�մϴ�.\n");
    infix_to_postfix(exp);

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


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
int check_matching(const element* in);
int string_length(const char* str);
int check_open_close(char s1, char s2);


int main(void) {
    char p[101];
    scanf("%s", p);

    if (check_matching(p)) printf("성공~! %s는 괄호가 올바르게 닫혀있습니다.\n", p);
    else printf("실패!! %s는 괄호가 올바르게 닫혀있지 않습니다.\n", p);

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

int check_matching(const char* in) {
    Stack s;
    char ch, open_ch;
    int len = string_length(in);
    init_stack(&s, len);

    for (int i = 0; i < len; i++) {
        ch = in[i];
        switch (ch)
        {
        case '(': case '[': case '{':
            push(&s, ch); break;
        case ')': case ']': case '}':
            if (is_empty(&s)) return 0;
            open_ch = pop(&s);
            if (!check_open_close(open_ch, ch)) return 0;
            break;
        default:
            break;
        }
    }
    if (!is_empty(&s)) return 0;
    return 1;
}

int string_length(const char* str) {
    int len = 0;
    while (str[len++] != '\0');
    return (len - 1);
}

int check_open_close(char s1, char s2) {
    if (s1 == '(') s1 = ')';
    else if (s1 == '[') s1 = ']';
    else s1 = '}';

    if (s1 == s2) return 1;
    return 0;
}
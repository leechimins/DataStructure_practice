#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;    //! ����� �ڷ����� �����Ӱ� ������ ��� ����
typedef struct {
    element data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
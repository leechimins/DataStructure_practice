#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;    //! 요소의 자료형을 자유롭게 수정해 사용 가능
typedef struct {
    element data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
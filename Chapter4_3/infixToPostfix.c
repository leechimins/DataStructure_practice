#include "stack.h"

int prec(char op) {
    switch (op)
    {
    case '(': case')': return 0;
    case '+': case'-': return 1;
    case '*': case'/': return 2;
    default: return -1;
    }
}

void infix_to_postfix(char* exp) {
    char ch, top_op;
    int len = string_length(exp);
    Stack s;

    init_stack(&s, len);
    for (int i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                printf("%c", pop(&s));
            push(&s, ch); break;
        case '(':
            push(&s, ch); break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(') {
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s)) printf("%c", pop(&s));
    printf("\n");
    delete(&s);
}
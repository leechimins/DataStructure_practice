#include "stack.h"

void infix_to_postfix_eval(char* exp, char* result) {
    char ch, top_op;
    int r = 0, len = string_length(exp);
    Stack s;

    init_stack(&s, len);
    for (int i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch)
        {
        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                result[r] = pop(&s);
                printf("%c", result[r++]);
            }
            push(&s, ch); break;
        case '(':
            push(&s, ch); break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(') {
                result[r++] = top_op;
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            result[r++] = ch;
            printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s)) {
        result[r] = pop(&s);
        printf("%c", result[r++]);
    }
    printf("\n");
    delete(&s);
    result[r] = '\0';
}
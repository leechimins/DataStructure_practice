#include "stack.h"

int main(void) {
    /*
    char exp[101];
    scanf("%s", exp);
    int result = eval(exp);
    printf("��갪�� %d\n", result);

    char exp[101], post[101] = "";
    scanf("%s", exp);
    printf("���� �������� ��ȯ�մϴ�.\n��ȯ ��� : ");
    infix_to_postfix(exp);
    */

    char exp[101], post[101] = "";
    scanf("%s", exp);
    printf("���� �������� ��ȯ�մϴ�.\n��ȯ ��� : ");
    infix_to_postfix_eval(exp, post);
    int result = eval(post);
    printf("���� ��갪 : %d\n", result);

    printf("���� -> ���� �׽�Ʈ\n");

    return 0;
}
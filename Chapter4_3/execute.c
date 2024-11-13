#include "stack.h"

int main(void) {
    /*
    char exp[101];
    scanf("%s", exp);
    int result = eval(exp);
    printf("계산값은 %d\n", result);

    char exp[101], post[101] = "";
    scanf("%s", exp);
    printf("후위 수식으로 변환합니다.\n변환 결과 : ");
    infix_to_postfix(exp);
    */

    char exp[101], post[101] = "";
    scanf("%s", exp);
    printf("후위 수식으로 변환합니다.\n변환 결과 : ");
    infix_to_postfix_eval(exp, post);
    int result = eval(post);
    printf("수식 계산값 : %d\n", result);

    printf("로컬 -> 원격 테스트\n");

    return 0;
}
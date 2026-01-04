#include <stdio.h>
#include <ctype.h>
#include <string.h>

char yigin[100];
int ust = -1;

void push(char eleman) {
    yigin[++ust] = eleman;
}

char pop() {
    if (ust == -1) return -1;
    return yigin[ust--];
}

int oncelik(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    char sembol, temp;

    for (i = 0; i < strlen(infix); i++) {
        sembol = infix[i];

        if (isalnum(sembol)) {
            postfix[k++] = sembol;
        }
        else if (sembol == '(') {
            push(sembol);
        }
        else if (sembol == ')') {
            while ((temp = pop()) != '(') {
                postfix[k++] = temp;
            }
        }
        else {
            while (ust != -1 && oncelik(yigin[ust]) >= oncelik(sembol)) {
                postfix[k++] = pop();
            }
            push(sembol);
        }
    }

    while (ust != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Infix ifadeyi giriniz: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix hali: %s\n", postfix);

    return 0;
}

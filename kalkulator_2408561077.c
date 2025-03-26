#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int data[MAX];
    int top;
} Stack;

void ubahstack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int x) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = x;
    }
}

int pop(Stack *s) {
    if (s->top == -1)
        return -1;
    return s->data[s->top--];
}

int prioritas(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return -1;
}

int operasi(char *postfix) {
    Stack s;
    ubahstack(&s);
    char *e = postfix;
    while (*e != '\0') {
        if (isdigit(*e)) {
            push(&s, *e - '0'); // Konversi karakter angka ke int
        } else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            int result = 0;
            switch (*e) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            push(&s, result);
        }
        e++;
    }
    return pop(&s);
}

void ubahinfix(char *infix, char *postfix) {
    Stack s;
    ubahstack(&s);
    char *e, x;
    int j = 0;
    e = infix;
    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
            postfix[j++] = *e;
        } else if (*e == '(') {
            push(&s, *e);
        } else if (*e == ')') {
            while ((x = pop(&s)) != '(') {
                printf("%c", x);
                postfix[j++] = x;
            }
        } else {
            while (s.top != -1) {
                if (prioritas(s.data[s.top]) < prioritas(*e))
                    break;
                printf("%c", pop(&s));
                postfix[j++] = pop(&s);
            }
            push(&s, *e);
        }
        e++;
    }
    while (s.top != -1) {
        char popped = pop(&s);
        printf("%c", popped);
        postfix[j++] = popped;
    }
    postfix[j] = '\0';
}


int main() {
    char infix[MAX], postfix[MAX];
    system("cls");
    printf("==============================\n");
    printf("Masukkan Infix: ");
    scanf("%s", infix);
    
    printf("------------------------------\n");
    printf("Hasil Postfix: ");
    ubahinfix(infix, postfix);
    
    printf("\nHasil Perhitungan: %d\n", operasi(postfix));
    printf("==============================\n");

    return 0;
}

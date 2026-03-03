#include <stdio.h>
#include <string.h>

int main() {
    char nonTerminal, alpha[50], beta[50];

    printf("Enter Non-Terminal (A): ");
    scanf("%c", &nonTerminal);

    printf("Enter alpha part (after A -> A alpha): ");
    scanf("%s", alpha);

    printf("Enter beta part (A -> beta): ");
    scanf("%s", beta);

    printf("\nGrammar after removing Left Recursion:\n");
    printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
    printf("%c' -> %s%c' | ε\n", nonTerminal, alpha, nonTerminal);

    return 0;
}
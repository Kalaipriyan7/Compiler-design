#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char nonTerminals[10], terminals[10];
    char table[10][10][10];
    int nt, t;

    printf("Enter number of Non-Terminals: ");
    scanf("%d", &nt);

    printf("Enter Non-Terminals:\n");
    for(int i=0;i<nt;i++)
        scanf(" %c", &nonTerminals[i]);

    printf("Enter number of Terminals: ");
    scanf("%d", &t);

    printf("Enter Terminals:\n");
    for(int i=0;i<t;i++)
        scanf(" %c", &terminals[i]);

    printf("\nEnter parsing table entries (use - for empty):\n");

    for(int i=0;i<nt;i++) {
        for(int j=0;j<t;j++) {
            printf("M[%c,%c]: ", nonTerminals[i], terminals[j]);
            scanf("%s", table[i][j]);
        }
    }

    printf("\nPredictive Parsing Table:\n\n");
    printf("\t");
    for(int j=0;j<t;j++)
        printf("%c\t", terminals[j]);
    printf("\n");

    for(int i=0;i<nt;i++) {
        printf("%c\t", nonTerminals[i]);
        for(int j=0;j<t;j++) {
            printf("%s\t", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
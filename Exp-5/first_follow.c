#include<stdio.h>
#include<ctype.h>
#include<string.h>

int n;
char production[10][20];
char result[20];
int resultIndex;

void addToResult(char c) {
    for(int i = 0; i < resultIndex; i++)
        if(result[i] == c)
            return;
    result[resultIndex++] = c;
}

void FIRST(char c) {
    if(!isupper(c)) {
        addToResult(c);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(production[i][0] == c) {
            if(production[i][2] == '#') {
                addToResult('#');
            } else {
                FIRST(production[i][2]);
            }
        }
    }
}

int main() {
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for(int i = 0; i < n; i++)
        scanf("%s", production[i]);

    printf("Enter non-terminal to find FIRST: ");
    scanf(" %c", &c);

    resultIndex = 0;
    FIRST(c);

    printf("FIRST(%c) = { ", c);
    for(int i = 0; i < resultIndex; i++)
        printf("%c ", result[i]);
    printf("}\n");

    return 0;
}
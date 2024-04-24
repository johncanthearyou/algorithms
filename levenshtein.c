#include <stdio.h>


char *stringN = 0;
int n = 0;
char *stringM = 0;
int m = 0;


void zeroMatrix(int matrix[n][m]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

int stringLength(char* string)
{
    int i = 0;
    while (string[i] != '\0') { i++; }
    return i;
}

void printMatrix(int matrix[n][m]) {
    printf("    ");
    for (int i = 0; i < m; i++) {
        printf("%c ", stringM[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        if (i==0) { printf("  "); }
        else { printf("%c ", stringN[i-1]); }
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int getMinimum(int a, int b, int c) {
    int min = a;
    if (b < min) { min = b; }
    if (c < min) { min = c; }

    return min;
}

int main(int argc, char* argv[])
{
    stringN = argv[1];
    n = stringLength(stringN)+1;
    printf("%d", n);
    if (n==0) { return m; }
    stringM = argv[2];
    m = stringLength(stringM)+1;
    if (m==0) { return n; }
    printf("Computing Levenshtein Distance from %s to %s\n", stringN, stringM);

    int matrix[n][m];
    zeroMatrix(matrix);
    for (int i = 0; i < n; i++) { matrix[i][0] = i; }
    for (int j = 0; j < m; j++) {  matrix[0][j] = j; }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int aboveLeftCell = matrix[i-1][j-1];
            if (stringN[i-1] != stringM[j-1]) { aboveLeftCell += 1;}
            int aboveCell = 1 + matrix[i][j-1];
            int leftCell = 1 + matrix[i-1][j];
            matrix[i][j] = getMinimum(aboveLeftCell, aboveCell, leftCell); 
        }
    }
    printMatrix(matrix);

    int distance = matrix[n-1][m-1];
    printf("Levenshtein Distance from %s to %s: %d\n", stringN, stringM, distance);
    return distance;
}
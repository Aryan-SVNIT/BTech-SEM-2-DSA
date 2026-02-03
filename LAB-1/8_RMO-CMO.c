#include <stdio.h>
int main() {
    int m, n, i, j;
    int *rmo, *cmo , *base;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int A[m][n];
    printf("Enter i and j : ");
    scanf("%d %d", &i, &j);
    base = &A[0][0];
    rmo = base + ((i * n) + j);
    cmo = base + ((j * m) + i);
    printf("\nRow Major Address      : %d", (void *)rmo);
    printf("\nColumn Major Address   : %d", (void *)cmo);
    if (rmo == &A[i][j])
        printf("\nSUCCESS\n");
    else
        printf("FAILED");
}
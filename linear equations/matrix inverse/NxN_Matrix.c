#include <stdio.h>
#include <stdlib.h>

double getDeterminant(double matrix, int unknows)
{
    double determinant;
    for (int i = 0; i < n; i++)
    {
    }
    return result;
}

int main()
{
    int unknows;
    int i, j;
    int rows, cols;

    printf("Enter Total unknows: ");
    scanf("%d", &unknows);
    rows = unknows, cols = unknows + 1;

    double **A = calloc(rows, sizeof(double));
    for (int i = 0; i < rows; i++)
    {
        A[i] = calloc(cols, sizeof(double));
    }
    double det1, det2, det3, det;
    double minors[3][3];

    printf("Enter the agument matrix: \n");
    printf("Example:\n");
    printf("1 2 3 9\n");
    printf("2 3 1 8\n");
    printf("3 1 2 7\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d th %d th ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    double det = getDeterminant(A, unknows);

    printf("%d ", &det);

    return 0;
}
#include <stdio.h>

int main()
{
    double matrix[2][3] = {2, 1, 5,
                           1, -1, 1};
    double det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    double swap;

    swap = matrix[1][1];
    matrix[1][1] = matrix[0][0];
    matrix[0][0] = swap;

    swap = -matrix[0][1];
    matrix[0][1] = -matrix[1][0];
    matrix[1][0] = swap;

    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            matrix[i][j] = matrix[i][j] / det;
            printf("%.2f ", matrix[i][j]);
        }
        printf("%.2f ", matrix[i][j]);
        printf("\n");
    }

    double result[2];
    printf("\n\n");

    result[0] = (matrix[0][0] * matrix[0][2]) + (matrix[1][0] * matrix[1][2]);
    result[1] = (matrix[0][1] * matrix[0][2]) + (matrix[1][1] * matrix[1][2]);

    printf("%.2f %.2f ", result[0], result[1]);

    return 0;
}
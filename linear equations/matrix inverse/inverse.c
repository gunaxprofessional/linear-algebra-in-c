#include <stdio.h>

int main()
{
    double matrix[2][2] = {2, 1,
                           1, -1};
    double det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    double swap;

    swap = matrix[1][1];
    matrix[1][1] = matrix[0][0];
    matrix[0][0] = swap;

    swap = -matrix[0][1];
    matrix[0][1] = -matrix[1][0];
    matrix[1][0] = swap;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f ", matrix[i][j]);
            matrix[i][j] = matrix[i][j] / (1.0 / det);
        }
        printf("\n");
    }

    return 0;
}
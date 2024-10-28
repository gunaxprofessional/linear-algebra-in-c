#include <stdlib.h>
#include <stdio.h>

int main()
{
    double matrix[3][3] = {2, 1, 3,
                           4, 2, 1,
                           1, 5, 2};

    double x = matrix[0][0];

    for (int i = 0; i < 3; i++)
        matrix[0][i] = matrix[0][i] / x;

    x = matrix[1][0];

    for (int i = 0; i < 3; i++)
    {
        if (x < 0)
            matrix[1][i] = matrix[1][i] + (x * matrix[0][i]);
        else
            matrix[1][i] = matrix[1][i] + (-x * matrix[0][i]);
    }

    x = matrix[2][0];

    for (int i = 0; i < 3; i++)
    {
        if (x < 0)
            matrix[2][i] = matrix[2][i] + (x * matrix[0][i]);
        else
            matrix[2][i] = matrix[2][i] + (-x * matrix[0][i]);
    }

    printf("\n\n\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
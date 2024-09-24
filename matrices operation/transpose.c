#include <stdio.h>

int main()
{
    int matrix[3][3] = {1, 2, 3,
                        4, 5, 6,
                        7, 8, 9};
    int row = sizeof(matrix) / sizeof(matrix[0]);
    int column = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < column; j++)
        {
            // printf("%d %d ", matrix[i][j], matrix[j][i]);
            int swap = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = swap;
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
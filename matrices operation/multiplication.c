#include <stdio.h>

int main()
{

    int vector_X[2][2] = {1, 2,
                          4, 5};

    int vector_Y[2][2] = {1, 2,
                          4, 5};

    int result[2][2];

    int A_row = sizeof(vector_X) / sizeof(vector_X[0]);
    int B_row = sizeof(vector_Y) / sizeof(vector_Y[0]);
    int A_column = sizeof(vector_X[0]) / sizeof(vector_X[0][0]);
    int B_column = sizeof(vector_Y[0]) / sizeof(vector_Y[0][0]);

    if ((A_row != B_row) || (A_column != B_column))
        printf("the size of two vector should be equal");
    else
    {
        printf("the result of multiplication of two matrix: \n");
        for (int i = 0; i < A_row; i++)
        {
            for (int j = 0; j < A_column; j++)
            {
                result[i][j] = 0;
                int dummy = 0;
                for (int second_row = 0; second_row < B_row; second_row++)
                {
                    dummy += (vector_X[i][second_row] * vector_Y[second_row][j]);
                }
                result[i][j] = dummy;
                // printf("%d ", result[i][j]);
            }
        }
        for (int i = 0; i < A_row; i++)
        {
            for (int j = 0; j < A_column; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
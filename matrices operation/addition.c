#include <stdio.h>

int main()
{
    int A[2][3] = {1, 2, 3,
                   4, 5, 6};

    int B[2][3] = {1, 2, 3,
                   4, 5, 6};

    int result[2][3];

    int A_row = sizeof(A) / sizeof(A[0]);
    int B_row = sizeof(B) / sizeof(B[0]);
    int A_column = sizeof(A[0]) / sizeof(A[0][0]);
    int B_column = sizeof(B[0]) / sizeof(B[0][0]);

    if ((A_row != B_row) || (A_column != B_column))
        printf("the size of two vector should be equal");
    else
    {
        printf("the result of addition of two matrix: \n");
        for (int i = 0; i < A_row; i++)
        {
            for (int j = 0; j < A_column; j++)
            {
                result[i][j] = A[i][j] + B[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
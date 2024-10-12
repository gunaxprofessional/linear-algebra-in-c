#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, columns;
    printf("Enter rows and columns\t");
    scanf("%d %d", &rows, &columns);

    int **arr = calloc(columns, sizeof(int));

    for (int i = 0; i < columns; i++)
        arr[i] = calloc(rows, sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
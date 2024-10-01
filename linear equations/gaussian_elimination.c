#include <stdio.h>

int main()
{
    int total_unknows;
    printf("Enter the total unknows: ");
    scanf("%d", &total_unknows);
    int cols = total_unknows + 1;
    int equations[total_unknows][cols];

    for (int i = 0; i < total_unknows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("\nEnter the %d%d th element of ur augmented matrix: ", i, j);
            scanf("%d", &equations[i][j]);
        }
    }

    for (int i = 0; i < total_unknows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", equations[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 2 = > 2 int + 2 operators + 1 result
// 3 = > 3 int + 3 operators + 1 result
// 4 = > 4 int + 4 operators + 1 result
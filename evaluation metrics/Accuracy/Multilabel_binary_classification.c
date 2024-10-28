#include <stdio.h>

int main()
{
    int y_true[3][4] = {{0, 1, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int y_pred[3][4] = {{0, 1, 1, 0},
                        {1, 1, 0, 1},
                        {0, 1, 0, 1}};
    int row_count = sizeof(y_true) / sizeof(y_true[0]);
    int col_count = sizeof(y_true[0]) / sizeof(y_true[0][0]);

    int total_miss_matches = 0;
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < col_count; j++)
            if (y_true[i][j] != y_pred[i][j])
            {
                total_miss_matches += 1;
                break;
            }
    }

    printf("%.2lf ", (float)(row_count - total_miss_matches) / row_count);
    return 0;
}
#include <stdio.h>

int main()
{
    int y_true[10] = {1, 0, 2, 0, 0, 1, 3, 0, 2};
    int y_pred[10] = {0, 1, 2, 0, 2, 3, 1, 0, 0};
    int total_sample = sizeof(y_pred) / sizeof(y_pred[0]);
    int total_matches = 0;
    for (int i = 0; i < total_sample; i++)
    {
        if (y_true[i] == y_pred[i])
        {
            total_matches += 1;
        }
    }

    printf("%.2lf ", (float)total_matches / total_sample);
    return 0;
}
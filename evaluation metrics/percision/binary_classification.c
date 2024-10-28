#include <stdio.h>

int main()
{
    int y_true[10] = {1, 0, 0, 0, 0, 1, 1, 0, 0, 0};
    int y_pred[10] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 0};
    int total_sample = sizeof(y_pred) / sizeof(y_pred[0]);
    int TP, FP, FN, TN;
    TP = FP = FN = TN = 0;
    for (int i = 0; i < total_sample; i++)
    {
        if (y_true[i] == 1)
        {
            if (y_pred[i] == 1)
                TP += 1;
            else if (y_pred[i] == 0)
                FN += 1;
        }
        else
        {
            if (y_pred[i] == 1)
                FP += 1;
            else if (y_pred[i] == 0)
                TN += 1;
        }
        printf("%d %d %d %d \n", TP, FP, FN, TN);
    }

    printf("%d %d %d %d \n", TP, FP, FN, TN);

    printf("%.2lf ", (float)TN / (TN + FP));
    return 0;
}
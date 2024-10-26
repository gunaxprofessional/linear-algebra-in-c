#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unknowns;
    printf("Enter the total unkowns ");
    scanf("%d", &unknowns);

    double **Coefficient = (double **)calloc(unknowns, sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        Coefficient[i] = (double *)calloc(unknowns, sizeof(double));

    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            printf("%dth %dth: ", i, j);
            scanf("%lf", &Coefficient[i][j]);
        }
    }

    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            printf("%.2lf ", Coefficient[i][j]);
        }
        printf("\n");
    }
    return 0;
}
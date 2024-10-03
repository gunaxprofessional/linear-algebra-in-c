#include <stdio.h>

int main()
{
    int unknows;
    int i, j;
    int rows, cols;

    printf("Enter Total unknows: ");
    scanf("%d", &unknows);
    rows = unknows, cols = unknows + 1;

    double A[rows][cols];
    double det1, det2, det3, det;
    double minors[3][3];

    printf("Enter the agument matrix: \n");
    printf("Example:\n");
    printf("1 2 3 9\n");
    printf("2 3 1 8\n");
    printf("3 1 2 7\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d th %d th ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    det1 = (A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1])));
    det2 = (-A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0])));
    det3 = (A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])));

    det = det1 + det2 + det3;
    printf("The determinant: %.2f \n", det);

    minors[0][0] = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);
    minors[0][1] = (A[1][0] * A[2][2]) - (A[1][2] * A[2][0]);
    minors[0][2] = (A[1][0] * A[2][1]) - (A[1][1] * A[2][0]);
    minors[1][0] = (A[0][1] * A[2][2]) - (A[0][2] * A[2][1]);
    minors[1][1] = (A[0][0] * A[2][2]) - (A[0][2] * A[2][0]);
    minors[1][2] = (A[0][0] * A[2][1]) - (A[0][1] * A[2][0]);
    minors[2][0] = (A[0][1] * A[1][2]) - (A[0][2] * A[1][1]);
    minors[2][1] = (A[0][0] * A[1][2]) - (A[1][0] * A[0][2]);
    minors[2][2] = (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]);

    printf("applying checkboard pattern to minors\n");
    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (flag % 2 != 0)
            {
                minors[i][j] *= -1;
            }
            flag += 1;
        }
    }

    printf("The Minors: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", minors[i][j]);
        }
        printf("\n");
    }

    printf("Transpose operation\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            double swap = minors[j][i];
            minors[j][i] = minors[i][j];
            minors[i][j] = swap;
        }
    }

    printf("The Adjugate: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", minors[i][j]);
        }
        printf("\n");
    }

    double inverse[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverse[i][j] = minors[i][j] / det;
        }
    }

    printf("The inverse: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", inverse[i][j]);
        }
        printf("\n");
    }

    double result[3] = {0, 0, 0};

    i = 0, j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            result[j] += (inverse[j][i] * A[i][3]);
        }
    }

    printf("The result:\nX: %.5f, Y: %.5f, Z: %.5f ", result[0], result[1], result[2]);

    return 0;
}
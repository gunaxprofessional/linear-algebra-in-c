#include <stdio.h>
#include <stdlib.h>

void getCofactor(double **mat, double **temp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // Skip the current row and column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double determinantOfMatrix(double **mat, int n)
{
    double det = 0;

    if (n == 1)
        return mat[0][0];

    int sign = 1;

    double **Cofactor = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++)
        Cofactor[i] = (double *)malloc((n - 1) * sizeof(double));

    // Iterate for each element of the first row
    for (int f = 0; f < n; f++)
    {
        // Getting the cofactor of mat[0][f]
        getCofactor(mat, Cofactor, 0, f, n);
        det += sign * mat[0][f] * determinantOfMatrix(Cofactor, n - 1);

        // Alternate signs
        sign = -sign;
    }

    for (int i = 0; i < n - 1; i++)
        free(Cofactor[i]);
    free(Cofactor);

    return det;
}

void calculateMinors(double **mat, double **minors, int n)
{
    double **temp = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++)
        temp[i] = (double *)malloc((n - 1) * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getCofactor(mat, temp, i, j, n);                                               // Get cofactor for element (i, j)
            minors[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinantOfMatrix(temp, n - 1); // Apply checkerboard sign pattern
        }
    }

    for (int i = 0; i < n - 1; i++)
        free(temp[i]);
    free(temp);
}

int main()
{
    int unknowns, i, j;

    printf("Enter total unknowns: ");
    scanf("%d", &unknowns);

    double **Coefficient = (double **)calloc(unknowns, sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        Coefficient[i] = (double *)calloc(unknowns, sizeof(double));

    double **minors = (double **)malloc(unknowns * sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        minors[i] = (double *)malloc(unknowns * sizeof(double));

    double **inverse = (double **)malloc(unknowns * sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        inverse[i] = (double *)malloc(unknowns * sizeof(double));

    double constants[unknowns], result[unknowns];

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < unknowns; i++)
    {
        for (j = 0; j < unknowns + 1; j++)
        {
            printf("Enter %dth %dth value: ");
            if (j == unknowns)
            {
                scanf("%lf", &constants[i]); // Last column (constants)
            }
            else
            {
                scanf("%lf", &Coefficient[i][j]);
            }
        }
    }

    printf("\nThe entered matrix is:\n");
    for (i = 0; i < unknowns; i++)
    {
        for (j = 0; j < unknowns + 1; j++)
        {
            if (j == unknowns)
            {
                printf("%lf ", constants[i]);
            }
            else
            {
                printf("%lf ", Coefficient[i][j]);
            }
        }
        printf("\n");
    }

    double det = determinantOfMatrix(Coefficient, unknowns);
    printf("The determinant of the matrix is: %lf\n", det);

    if (det == 0)
    {
        printf("The matrix is singular and does not have an inverse.\n");
        return 0;
    }

    // Calculate minors
    calculateMinors(Coefficient, minors, unknowns);

    // Transpose the minors matrix (Adjugate)
    for (int i = 0; i < unknowns; i++)
    {
        for (int j = i + 1; j < unknowns; j++)
        {
            double temp = minors[i][j];
            minors[i][j] = minors[j][i];
            minors[j][i] = temp;
        }
    }

    // Calculate inverse by dividing adjugate matrix by the determinant
    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            inverse[i][j] = minors[i][j] / det;
        }
    }

    printf("The inverse matrix is:\n");
    for (i = 0; i < unknowns; i++)
    {
        for (j = 0; j < unknowns; j++)
        {
            printf("%.2f ", inverse[i][j]);
        }
        printf("\n");
    }

    // Solve the system of equations using the inverse matrix
    for (i = 0; i < unknowns; i++)
    {
        result[i] = 0;
        for (j = 0; j < unknowns; j++)
        {
            result[i] += inverse[i][j] * constants[j];
        }
    }

    printf("The result is:\n");
    for (i = 0; i < unknowns; i++)
    {
        printf("Variable %d: %.5f\n", i + 1, result[i]);
    }

    for (i = 0; i < unknowns; i++)
    {
        free(Coefficient[i]);
        free(minors[i]);
        free(inverse[i]);
    }
    free(Coefficient);
    free(minors);
    free(inverse);

    return 0;
}

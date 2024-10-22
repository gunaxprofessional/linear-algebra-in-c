#include <stdio.h>
#include <stdlib.h>

// Function to get the cofactor of a matrix
void getCofactor(double **mat, double **temp, int p, int q, int n)
{
    int i = 0, j = 0;

    // Loop through the matrix to copy elements into the cofactor matrix
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

// Recursive function to calculate the determinant
double determinantOfMatrix(double **mat, int n)
{
    double det = 0;

    // Base case: if matrix contains a single element
    if (n == 1)
        return mat[0][0];

    int sign = 1; // To store sign multiplier

    // Allocate memory for temporary matrix
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

    // Free allocated memory for temp matrix (cofactor matrix)
    for (int i = 0; i < n - 1; i++)
        free(Cofactor[i]);
    free(Cofactor);

    return det;
}

// Function to calculate minors of the matrix
void calculateMinors(double **mat, double **minors, int n)
{
    double **temp = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++)
        temp[i] = (double *)malloc((n - 1) * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getCofactor(mat, temp, i, j, n);                 // Get cofactor for element (i, j)
            minors[i][j] = determinantOfMatrix(temp, n - 1); // Calculate determinant of cofactor
        }
    }

    // Free memory allocated for temp matrix
    for (int i = 0; i < n - 1; i++)
        free(temp[i]);
    free(temp);
}

int main()
{
    int unknowns, i, j;

    printf("Enter total unknowns: ");
    scanf("%d", &unknowns);

    // Allocate memory for coefficient matrix dynamically
    double **Coefficient = (double **)calloc(unknowns, sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        Coefficient[i] = (double *)calloc(unknowns, sizeof(double));

    // Allocate memory for minors matrix
    double **minors = (double **)malloc(unknowns * sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        minors[i] = (double *)malloc(unknowns * sizeof(double));

    // Allocate memory for inverse matrix
    double **inverse = (double **)malloc(unknowns * sizeof(double *));
    for (int i = 0; i < unknowns; i++)
        inverse[i] = (double *)malloc(unknowns * sizeof(double));

    double constants[unknowns], result[unknowns];

    // Input the augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    printf("Example:\n");
    printf("Coefficient of x, Coefficient of y, Coefficient of z, constant\n");
    printf("1 2 3 9\n");
    printf("2 3 1 8\n");
    printf("3 1 2 7\n");

    for (i = 0; i < unknowns; i++)
    {
        for (j = 0; j < unknowns + 1; j++)
        {
            printf("%d %d ", i, j);
            if (j == unknowns)
            {
                scanf("%lf", &constants[i]); // Last column (constants)
            }
            else
            {
                scanf("%lf", &Coefficient[i][j]); // Coefficients
            }
        }
        printf("\n");
    }

    // Output the matrix for verification
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

    // Calculate the determinant of the coefficient matrix
    double det = determinantOfMatrix(Coefficient, unknowns);
    printf("The determinant of the matrix is: %lf\n", det);

    // Calculate minors
    calculateMinors(Coefficient, minors, unknowns);

    printf("applying checkboard pattern to minors\n");
    int flag = 0;
    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            if (flag % 2 != 0)
            {
                minors[i][j] *= -1;
            }
            flag += 1;
        }
    }

    // Print the minors matrix
    printf("\nThe minors of the matrix are:\n");
    for (i = 0; i < unknowns; i++)
    {
        for (j = 0; j < unknowns; j++)
        {
            printf("%lf ", minors[i][j]);
        }
        printf("\n");
    }

    printf("Transpose operation\n");

    for (int i = 0; i < unknowns; i++)
    {
        for (int j = i + 1; j < unknowns; j++)
        {
            double swap = minors[j][i];
            minors[j][i] = minors[i][j];
            minors[i][j] = swap;
        }
    }

    printf("The Adjugate: \n");
    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            printf("%.2f ", minors[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            inverse[i][j] = minors[i][j] / det;
        }
    }

    printf("The inverse: \n");
    for (int i = 0; i < unknowns; i++)
    {
        for (int j = 0; j < unknowns; j++)
        {
            printf("%.2f ", inverse[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < unknowns; i++)
    {
        result[i] = 0;
        for (int j = 0; j < unknowns; j++)
        {
            result[i] += inverse[i][j] * constants[j];
        }
    }
    printf("The result:\nX: %.5f, Y: %.5f, Z: %.5f ", result[0], result[1], result[2]);

    // Free the allocated memory for the coefficient matrix
    for (int i = 0; i < unknowns; i++)
    {
        free(Coefficient[i]);
        free(minors[i]);
    }
    free(Coefficient);
    free(minors);

    return 0;
}

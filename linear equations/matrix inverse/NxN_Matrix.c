#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Allocate memory for cofactor matrix dynamically
    double **temp = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        temp[i] = (double *)malloc(n * sizeof(double));

    int sign = 1; // To store sign multiplier

    // Iterate for each element of the first row
    for (int f = 0; f < n; f++)
    {
        // Getting the cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        det += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);

        // Alternate signs
        sign = -sign;
    }

    // Free allocated memory for temp matrix
    for (int i = 0; i < n; i++)
        free(temp[i]);
    free(temp);

    return det;
}

int main()
{
    int unknows, i, j;
    int rows, cols;

    printf("Enter total unknowns: ");
    scanf("%d", &unknows);
    rows = unknows;
    cols = unknows;

    // Allocate memory for coefficient matrix dynamically
    double **Coefficient = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        Coefficient[i] = (double *)calloc(cols, sizeof(double));
    }

    double constants[rows];

    // Input the augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    printf("Example:\n");
    printf("Coefficient of x, Coefficient of y, Coefficient of z, constant\n");
    printf("1 2 3 9\n");
    printf("2 3 1 8\n");
    printf("3 1 2 7\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols + 1; j++)
        {
            printf("%d th %d th ", i, j);
            if (j == cols)
            {
                scanf("%lf", &constants[i]); // Last column (constants)
            }
            else
            {
                scanf("%lf", &Coefficient[i][j]); // Coefficients
            }
        }
    }

    // Output the matrix for verification
    printf("\nThe entered matrix is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols + 1; j++)
        {
            if (j == cols)
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
    double det = determinantOfMatrix(Coefficient, unknows);
    printf("The determinant of the matrix is: %lf\n", det);

    double **minor = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        minor[i] = (double *)calloc(cols, sizeof(double));
        memcpy(minor[i], Coefficient[i], rows * sizeof(double));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            minor[i][j] = determinantOfMatrix(Coefficient, unknows)
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

    // Free the allocated memory for the coefficient matrix
    for (int i = 0; i < rows; i++)
    {
        free(Coefficient[i]);
    }
    free(Coefficient);

    return 0;
}

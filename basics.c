/*
    scalars : just a single number,
              it can be negative,
              positive,
              or zero and can be an integer,
              fraction,
              complex number

                  Vectors : list of ordered numbers,
                            have both magnitude and direction.

                            2D = [ 3, 4 ] 3D = [ 1, 2, 3 ]

                            Additions :

    U = [ 1, 2 ] V = [ 3, 4 ] U + V = [ 4, 6 ]

                                      Scalar multiplication :

                                      2 *
                                      [ 3, 4 ] = [ 6, 8 ]

    Dot product :

    u = [ 1, 3 ] v = [ 2, 4 ]

                     u.v = (1 * 3) + (2 * 4) = 3 + 8 = 11

    */

#include <stdio.h>

int main()
{

    // vector additions

    int U[] = {1, 2};
    int V[] = {3, 4};

    int len_of_vector1 = sizeof(U) / sizeof(U[0]);
    int len_of_vector2 = sizeof(V) / sizeof(V[0]);

    int add_U_V[len_of_vector1];

    if (len_of_vector1 != len_of_vector2)
        printf("the length of the two vector should be equal");
    else
    {
        printf("the additions of two vector is: \n");
        for (int i = 0; i < len_of_vector1; i++)
        {
            add_U_V[i] = U[i] + V[i];
            printf("%d \t", add_U_V[i]);
        }
    }

    // scalar multiplication

    printf("\n\n");

    int scalar = 2;
    int vector[] = {1, 2, 3};
    int length_of_vector = sizeof(vector) / sizeof(vector[0]);

    for (int i = 0; i < length_of_vector; i++)
        vector[i] = scalar * vector[i];

    printf("the output: of scalar multiplication: \n");
    for (int i = 0; i < length_of_vector; i++)
        printf("%d \t", vector[i]);

    // Dot Product

    printf("\n\n\n");

    int vector_U[] = {1, 2};
    int vector_V[] = {3, 5};

    int multiplication_of_U = 1;
    int multiplication_of_V = 1;

    int length_of_U = sizeof(vector_U) / sizeof(vector_U[0]);
    int length_of_V = sizeof(vector_V) / sizeof(vector_V[0]);

    if (length_of_U != length_of_V)
        printf("the size of two vectors should be equal\n\n");
    else
    {
        for (int i = 0; i < length_of_U; i++)
            multiplication_of_U *= vector_U[i];

        for (int i = 0; i < length_of_V; i++)
            multiplication_of_V *= vector_V[i];

        int ans = multiplication_of_U + multiplication_of_V;

        printf("the output of the dot product of given two vectors is %d ", ans);
    }

    return 0;
}

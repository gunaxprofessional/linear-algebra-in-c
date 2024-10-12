#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    int *new_arr = realloc(arr, 2);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", new_arr[i]);
    }

    free(arr);
    arr = NULL;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
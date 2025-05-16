#include <stdio.h>
#include <stdlib.h>

void inc_val(int *x)
{
    (*x)++;
}
int main()
{
    // int a = 24;
    // int *p = &a;
    // printf("%d\n", *p);
    // printf("%p\n", p);
    // printf("%d\n", a++); //? pass the value the n incriments
    // printf("%d\n", ++a); //? incremnts then it pass the value

    // int arr[3] = {1, 2, 3};
    // int *p = arr;
    //
    // printf("%d\n", *p);
    // p++;

    // ! If you use malloc, the values in the memory you get are uninitialized garbage — just whatever was already in that memory area.
    // ? taht's why we should use calloc
    //? malloc is like creating  a pointer that point to memory that have that size of data
    // => Hey system, give me a block of memory big enough to hold X bytes.
    // int *p = malloc(sizeof(int) * 3); //? allocate memory for 3 integers => I need 3 blocks, and each block is the size of an int.
    // if (p == NULL)                    // this bcs memory allocation could fail
    // {
    //     printf("Memory allocation failed!\n");
    //     return 1;
    // }

    // p[0] = 1;
    // p[1] = 2;
    // p[2] = 3;
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d\n", p[i]);
    // }
    // free(p);

    // int a = 5;
    // inc_val(&a);
    // printf("%d\n", a);

    return 0;
}

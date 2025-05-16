#include <stdio.h>

void modifyPointer(int **p)
{
    **p = 0;
    *p = NULL; // Now modifies the actual pointer in main()
}

int main()
{
    int x = 10;
    int *ptr = &x;

    modifyPointer(&ptr);                              // Passing a pointer to the pointer
    printf("After modifyPointer: %p\n", (void *)ptr); // Now ptr is NULL
    printf(" the value of x %d\n", x);
    return 0;
}

// #include <stdio.h>

// void modifyPointer(int *p)
// {
//     printf("Inside modifyPointer, before change: %p\n", (void *)p);
//     *p = 0;
//     p = NULL; // This only changes the local copy of `p`
//     printf("Inside modifyPointer, after change: %p\n", (void *)p);
// }

// int main()
// {
//     int x = 10;
//     int *ptr = &x;

//     printf("Before calling modifyPointer: %p\n", (void *)ptr);
//     // Passing the pointer by value
//     printf("After calling modifyPointer: %p\n", (void *)ptr); // Still the same
//     printf(" the value of x %d\n", x);
//     return 0;
// }

// #include <stdio.h>

// struct str
// {
//     char tit;
//     int qte;
// };

// void testStruct(struct str t)
// {
//     printf("%p \n", t);
//     t.qte = 1;
//     printf("%d\n", t.qte);
//     // printf("hi\n");
// }

// int main()
// {
//     struct str test;
//     test.qte = 0;

//     printf("in main %p \n", test);
//     printf("value befor proc %d\n", test.qte);

//     testStruct(test);

//     printf(" value after proc %d\n", test.qte);
//     return 0;
// };

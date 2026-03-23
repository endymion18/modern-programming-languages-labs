#include <stdio.h>

#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)
#define PR_float(x) printf("x=%u, *x=%f, &x=%u\n", x, *x, &x)

void ptr_test_var1()
{
    int mas[] = {100, 200, 300};
    int *ptr1, *ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];

    PR(ptr1);
    ptr1++;
    PR(ptr1);

    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1= %u\n", ptr2 - ptr1);
}

void ptr_test_var2()
{
    float mas[] = {100.0, 200.0, 300.0};
    float *ptr1, *ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];

    PR_float(ptr1);
    ptr1++;
    PR_float(ptr1);

    PR_float(ptr2);
    ++ptr2;
    printf("ptr2-ptr1= %u\n", ptr2 - ptr1);
}

int main()
{
    ptr_test_var1();
    ptr_test_var2();
}
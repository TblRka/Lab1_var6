#include <stdio.h>
#include <stdlib.h>

#include "head.h"

Info *CreateInfo
        (
                size_t size,
                size_t size_ptr,
                void (*input)(void *),
                void (*output)(void *),
                void (*sum)(void *, void *, void *),
                void (*mult)(void *, void *, void *),
                void (*power)(void *, int, void *),
                void (*zero)(void *),
                int (*sign)(void *)
        )
{
    Info *inf = (Info *)calloc(1, sizeof(Info));
    inf->size = size;
    inf->size_ptr = size_ptr;
    inf->input = input;
    inf->output = output;
    inf->sum = sum;
    inf->mult = mult;
    inf->power = power;
    inf->zero = zero;
    inf->sign = sign;
    return inf;
}

void IntInput(void *el)
{
    scanf("%d", (int*)el);
}

void DoubleInput(void *el)
{
    scanf("%lf", (double*)el);
}

void IntOutput(void *el)
{
    printf("%d", *(int*)el);
}

void DoubleOutput(void *el)
{
    printf("%lf", *(double*)el);
}

void IntSum(void *el1, void *el2, void *el3)
{
    *(int*)el3 =  *(int*)el1  + *(int*)el2;
}

void DoubleSum(void *el1, void *el2, void *el3)
{
    *(double*)el3 =  *(double*)el1  + *(double*)el2;
}

void IntMult(void *el1, void *el2, void *el3)
{
    *(int*)el3 =  (*(int*)el1) * (*(int*)el2);
}

void DoubleMult(void *el1, void *el2, void *el3)
{
    *(double*)el3 =  (*(double*)el1)  * (*(double*)el2);
}

void IntPower(void *el1, int n, void *el2)
{
    int y;
    y = *(int*)el1;
    int s = 1;
    for (int i = 0; i < n; i ++)
    {
        s *= y;
    }
    *(int*)el2 = s;
}

void DoublePower(void *el1, int n, void *el2)
{
    double y;
    y = *(double*)el1;
    double s = 1.0;
    for (int i = 0; i < n; i ++)
    {
        s *= y;
    }
    *(double*)el2 = s;
}

void IntZero(void *el)
{
    *(int*)el = 0;
}

void DoubleZero(void *el)
{
    *(double*)el = 0.0;
}

int IntSign(void *el)
{
    if (*(int*)el >= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int DoubleSign(void *el)
{
    if (*(double*)el >= 0.0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*
void IntDev(void *el1, void *el2, void *el3)
{
    *(int*)el3 =  (*(int*)el1) / (*(int*)el2);
}

void DoubleDev(void *el1, void *el2, void *el3)
{
    *(double*)el3 =  (*(double*)el1) / (*(double*)el2);
}
*/


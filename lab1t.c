#include <stdio.h>
#include <stdlib.h>
#include "head.h"


void polynom_input(struct Polynom *A)
{
    printf("Enter polynom degree: \n");
    scanf("%d", &(A->deg));

    A->index = calloc(A->deg + 1, A->inf->size_ptr);

    printf("Enter numbers starting with the HIGHEST coefficient: \n");
    for (int i = 0; i < A->deg + 1; i ++)
    {
        A->index[i] = calloc(1, A->inf->size);
        A->inf->input(&(A->index[i]));
    }
}

void polynom_output(struct Polynom *A)
{
    for (int i = 0; i < A->deg + 1; i ++)
    {
        if (A->inf->sign(&A->index[i]) == 0 && i > 0)
        {
            printf("+");
        }
        A->inf->output(&(A->index[i]));
        printf("*X^%d", (A->deg) - i);
    }
    printf("\n");
}

int maximum(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void polynom_sum(struct Polynom *A)
{
    struct Polynom *B;
    struct Polynom *C;
    B = (struct Polynom *)calloc(1, sizeof(struct Polynom));
    C = (struct Polynom *)calloc(1, sizeof(struct Polynom));

    B->inf = (Info *)calloc(1, sizeof(Info));
    B->inf = A->inf;
    polynom_input(B);
    
    C->deg = maximum(A->deg, B->deg);
    C->inf = (Info *)calloc(1, sizeof(Info));
    C->inf = A->inf;


    C->index = calloc(C->deg, C->inf->size_ptr);

    if (A->deg >= B->deg)
    {
        int delta = A->deg - B->deg;
        int i;
        for (i = 0; i < delta; i++ )
        { 
            C->index[i] = calloc(1, A->inf->size);
            A->inf->zero(&(C->index[i]));
            A->inf->sum(&(C->index[i]), &(A->index[i]), &(C->index[i]));
        }
        for (i = delta; i < C->deg + 1; i ++)
        {
            C->index[i] = calloc(1, C->inf->size);
            A->inf->zero(&(C->index[i]));
            A->inf->sum(&(C->index[i]), &(A->index[i]), &(C->index[i]));
            A->inf->sum(&(C->index[i]), &(B->index[i - delta]), &(C->index[i]));
        }
    }
    if (A->deg < B->deg)
    {
        int delta = B->deg - A->deg;
        int i;
        for (i = 0; i < delta; i++ )
        { 
            C->index[i] = calloc(1, A->inf->size);
            A->inf->zero(&(C->index[i]));
            A->inf->sum(&(C->index[i]), &(B->index[i]), &(C->index[i]));
        }
        for (i = delta; i < C->deg + 1; i ++)
        {
            C->index[i] = calloc(1, C->inf->size);
            A->inf->zero(&(C->index[i]));
            A->inf->sum(&(C->index[i]), &(B->index[i]), &(C->index[i]));
            A->inf->sum(&(C->index[i]), &(A->index[i - delta]), &(C->index[i]));
        }
    }

    A->deg = C->deg;
    free(A->index);
    A->index = calloc(A->deg, A->inf->size_ptr);
    A->index = C->index;

    //polynom_output(A);    
    free(C);
    free(B->index);
    free(B);
}

void substitution(struct Polynom *A)
{
    void *x;
    x = calloc(1, A->inf->size);
    printf("X = ");
    A->inf->input(x);

    void *Res;
    Res = calloc(1, A->inf->size);
    A->inf->zero(Res);

    void *y1;
    y1 = calloc(1, A->inf->size);

    for (int i = 0; i < A->deg + 1; i ++)
    {
       A->inf->zero(y1);
       A->inf->sum(y1, x, y1);
       A->inf->power(y1, A->deg - i, y1);
       A->inf->mult(y1, &(A->index)[i], y1);
       A->inf->sum(Res, y1, Res);

    }
    A->inf->output(Res);
    printf("\n");
    free(x);
    free(y1);
    free(Res);

}

void const_multiplicate(struct Polynom *A)
{
    void *c;
    c = calloc(1, A->inf->size);
    printf("Enter constante: ");
    A->inf->input(c);

    for (int i = 0; i < A->deg + 1; i++ )
    {
        A->inf->mult(&(A->index[i]), c, &(A->index[i]));
    }
}

void multiplicate(struct Polynom *A)
{
    struct Polynom *B;
    struct Polynom *C;
    B = calloc(1, sizeof(struct Polynom));
    C = calloc(1, sizeof(struct Polynom));

    B->inf = (Info *)calloc(1, sizeof(Info));
    C->inf = (Info *)calloc(1, sizeof(Info));
    B->inf = A->inf;
    C->inf = A->inf;

    polynom_input(B);

    C->deg = A->deg + B->deg;
    C->index = calloc(C->deg + 1, A->inf->size_ptr);
    for (int k = 0; k < C->deg + 1; k ++)
    {
        C->index[k] = calloc(1, A->inf->size);
        C->inf->zero(&(C->index[k])); 
    }

    void *y;
    y = calloc(1, A->inf->size);

    for (int i = 0; i < A->deg + 1; i ++)
    {
        for (int j = 0; j < B->deg + 1; j ++)
        {
            A->inf->mult(&(A->index[i]), &(B->index[j]), y);
            A->inf->sum(&(C->index[i + j]), y, &(C->index[i + j]));
        }
    }

    A->deg = C->deg;
    free(A->index);
    A->index = calloc(A->deg, A->inf->size_ptr);
    A->index = C->index;

    polynom_output(A);    
    free(C);
    free(B->index);
    free(B);
}

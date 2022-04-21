#include <stdio.h>
#include <stdlib.h>
#include "head.h"


void multiplicate_1(struct Polynom *A, struct Polynom *B)
{
    struct Polynom *C;
    C = calloc(1, sizeof(struct Polynom));
    C->inf = (Info *)calloc(1, sizeof(Info));
    C->inf = A->inf;

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
    free(C);
}

void polynom_degree(struct Polynom *A, int d)
{
    struct Polynom *C;
    C = calloc(1, sizeof(struct Polynom));
    C->inf = (Info *)calloc(1, sizeof(Info));
    C->inf = A->inf;
    C->deg = A->deg;
    C->index = calloc(C->deg + 1, A->inf->size_ptr);
    for (int j = 0; j < A->deg + 1; j ++)
    {
        C->index[j] = calloc(1, A->inf->size);
        A->inf->zero(&(C->index[j]));
        A->inf->sum(&(C->index[j]), &(A->index[j]), &(C->index[j]));
    }

    polynom_output(C);
    for (int i = 1; i < d; i ++)
    {
        multiplicate_1(A, C);
        printf("%d :\n ", i);
        polynom_output(A);
        polynom_output(C);
    }
}

void composition(struct Polynom *A)
{
    struct Polynom *B;
    struct Polynom *C;
    struct Polynom *Y;
    struct Polynom *X;
    Y = calloc(1, sizeof(struct Polynom));
    B = calloc(1, sizeof(struct Polynom));
    C = calloc(1, sizeof(struct Polynom));
    X = calloc(1, sizeof(struct Polynom));

    B->inf = (Info *)calloc(1, sizeof(Info));
    C->inf = (Info *)calloc(1, sizeof(Info));
    Y->inf = (Info *)calloc(1, sizeof(Info));
    X->inf = (Info *)calloc(1, sizeof(Info));
    B->inf = A->inf;
    C->inf = A->inf; 
    Y->inf = A->inf;
    X->inf = A->inf;
    polynom_input(B);

    C->deg = A->deg * B->deg;
    C->index = calloc(C->deg + 1, A->inf->size_ptr);
    for (int g = 0; g < C->deg + 1; g ++)
    {
        C->index[g] = calloc(1, C->inf->size);
        C->inf->zero(&(C->index[g]));
    }

    X->deg = X->deg;
    X->index = calloc(X->deg + 1, A->inf->size_ptr);
    for (int g = 0; g < X->deg + 1; g ++)
    {
        X->index[g] = calloc(1, A->inf->size);
        A->inf->zero(&(X->index[g]));
        A->inf->sum(&(X->index[g]), &(B->index[g]), &(X->index[g]));
    }

    Y->deg = B->deg;
    Y->index = calloc(Y->deg + 1, A->inf->size_ptr);
    for (int g = 0; g < Y->deg + 1; g ++)
    {
        Y->index[g] = calloc(1, A->inf->size);
        A->inf->zero(&(Y->index[g]));
        A->inf->sum(&(Y->index[g]), &(B->index[g]), &(Y->index[g]));
    }


    for (int i = 1; i < A->deg + 1; i ++)
    {
        for (int j = 0; j < B->deg + 1; j++ )
        {
            A->inf->mult(&(B->index[j]), &(A->index[A->deg - i]), &(X->index[j]));
        }
        int delta = C->deg - B->deg;
        int k;
        for (k = delta; k < C->deg + 1; k ++)
        {
            A->inf->sum(&(C->index[k]), &(X->index[k - delta]), &(C->index[k]));
        }
    }
    A->inf->sum(&(C->index[C->deg]), &(A->index[A->deg]), &(C->index[C->deg]));
    A->deg = C->deg;
    free(A->index);
    A->index = calloc(A->deg, A->inf->size_ptr);
    A->index = C->index;
   
    free(C);
    free(Y->index);
    free(Y);
    free(B->index);
    free(B);
}
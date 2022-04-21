#ifndef LAB1_HEAD_H
#define LAB1_HEAD_H

#include <math.h>

typedef struct Info
{
    size_t size;
    size_t size_ptr;
    void (*input)(void *);
    void (*output)(void *);
    void (*sum)(void *, void *, void *);
    void (*mult)(void *, void *, void *);
    void (*power)(void *, int, void *);
    void (*zero)(void *);
    int (*sign)(void *);

} Info;

struct Polynom
{
    int deg;
    void **index;
    Info *inf;
};

Info *CreateInfo(
                size_t size,
                size_t size_ptr,
                void (*input)(void *),
                void (*output)(void *),
                void (*sum)(void *, void *, void *),
                void (*mult)(void *, void *, void *),
                void (*power)(void *, int, void *),
                void (*zero)(void *),
                int (*sign)(void *)
        );

void IntInput(void *el);
void DoubleInput(void *el);
void IntOutput(void *el);
void DoubleOutput(void *el);
void IntSum(void *el1, void *el2, void *el3);
void DoubleSum(void *el1, void *el2, void *el3);
void IntMult(void *el1, void *el2, void *el3);
void DoubleMult(void *el1, void *el2, void *el3);
void IntPower(void *el1, int n, void *el2);
void DoublePower(void *el1, int n, void *el2);
void IntZero(void *el);
void DoubleZero(void *el);
int IntSign(void *el);
int DoubleSign(void *el);
void IntDev(void *el1, void *el2, void *el3);
void DoubleDev(void *el1, void *el2, void *el3);


void composition(struct Polynom *A);
void multiplicate(struct Polynom *A);
void const_multiplicate(struct Polynom *A);
void substitution(struct Polynom *A);
void polynom_sum(struct Polynom *A);
void polynom_output(struct Polynom *A);
void polynom_input(struct Polynom *A);
void multiplicate_1(struct Polynom *A, struct Polynom *B);

#endif //LAB1_HEAD_H

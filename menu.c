#include <stdio.h>
#include "head.h"

void IntMenu(struct Polynom *G)
{
    G->inf = CreateInfo(
            sizeof(int),
            sizeof(int*),
            IntInput,
            IntOutput,
            IntSum,
            IntMult,
            IntPower,
            IntZero,
            IntSign
    );
}

void DoubleMenu(struct Polynom *G)
{
    G->inf = CreateInfo(
            sizeof(double),
            sizeof(double*),
            DoubleInput,
            DoubleOutput,
            DoubleSum,
            DoubleMult,
            DoublePower,
            DoubleZero,
            DoubleSign
    );
}

void Menu(struct Polynom *K, struct Polynom *P)
{
    printf("Polynom type:\n1. Integer\n2. Float\n");
    int type;
    scanf("%d", &type);
    if (type == 1)
    {
        IntMenu(K);
        IntMenu(P);
    }
    if (type == 2)
    {
        DoubleMenu(K);
        DoubleMenu(P);
    }

    printf("1. Input\n2. Output\n3. Substitution\n4. Sum\n5. Multiplicate\n6. Constant multiplicate\n7. Composition\n8. Quit\n");
    int variation;
    scanf("%d", &variation);
    while (variation != 8)
    {
        switch(variation)
        {
            case(1):
                polynom_input(K);
                break;
            case(2):
                polynom_output(K);
                break;
            case(3):
                substitution(K);
                break;
            case(4):
                polynom_sum(K);
                break;
            case(5):
                multiplicate(K);
                break;
            case(6):
                const_multiplicate(K);
                break;
            case(7):
                //polynom_input(P);
                //polynom_output()
                //polynom_degree(K, 3);
                //multiplicate_1(K, K);
                composition(K);
                break;
            default:
                printf("Error\n");

        }
        printf("1. Input\n2. Output\n3. Substitution\n4. Sum\n5. Multiplicate\n6. Constant multiplicate\n7. Composition\n8. Quit\n");
        scanf("%d", &variation);
    }
}

int main()
{
    struct Polynom F;
    struct Polynom P;
    Menu(&F, &P);
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct No {
    int Info;
    struct No *Lig;
};

typedef struct No *NoPtr;

void InsereLista(NoPtr *L, int X) {
    NoPtr Novo = (NoPtr)malloc(sizeof(struct No));
    Novo->Info = X;
    Novo->Lig = *L;
    *L = Novo;
}

bool RetiraLista(NoPtr *L, int *X) {
    if (*L == NULL) {
        return false; // Lista vazia
    }
    NoPtr Temp = *L;
    *X = Temp->Info;
    *L = Temp->Lig;
    free(Temp);
    return true;
}

void ImprimeLista(NoPtr L) {
    NoPtr Temp = L;
    while (Temp != NULL) {
        printf("%d ", Temp->Info);
        Temp = Temp->Lig;
    }
    printf("\n");
}

NoPtr PrimeiroDaLista(NoPtr L) {
    return L;
}

NoPtr UniaoListas(NoPtr L1, NoPtr L2) {
    NoPtr Resultado = NULL;
    NoPtr Temp1 = L1;
    NoPtr Temp2 = L2;

    while (Temp1 != NULL) {
        InsereLista(&Resultado, Temp1->Info);
        Temp1 = Temp1->Lig;
    }

    while (Temp2 != NULL) {
        InsereLista(&Resultado, Temp2->Info);
        Temp2 = Temp2->Lig;
    }

    return Resultado;
}

NoPtr IntersecaoListas(NoPtr L1, NoPtr L2) {
    NoPtr Resultado = NULL;
    NoPtr Temp1 = L1;

    while (Temp1 != NULL) {
        NoPtr Temp2 = L2;
        while (Temp2 != NULL) {
            if (Temp1->Info == Temp2->Info) {
                InsereLista(&Resultado, Temp1->Info);
                break;
            }
            Temp2 = Temp2->Lig;
        }
        Temp1 = Temp1->Lig;
    }

    return Resultado;
}

int main(void) {
    NoPtr L1 = NULL;
    NoPtr L2 = NULL;

    InsereLista(&L1, 1);
    InsereLista(&L1, 2);
    InsereLista(&L1, 3);

    InsereLista(&L2, 3);
    InsereLista(&L2, 4);
    InsereLista(&L2, 5);

    printf("Lista 1: ");
    ImprimeLista(L1);
    printf("Lista 2: ");
    ImprimeLista(L2);

    NoPtr Uniao = UniaoListas(L1, L2);
    printf("União das listas: ");
    ImprimeLista(Uniao);

    NoPtr Intersecao = IntersecaoListas(L1, L2);
    printf("Interseção das listas: ");
    ImprimeLista(Intersecao);

    return 0;
}
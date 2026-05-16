#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct No {
    int Info;
    struct No *esq;
    struct No *dir;
};

typedef struct No *Arvore;

void insere(Arvore *A, int X) {
    if (*A == NULL) {
        *A = (Arvore)malloc(sizeof(struct No));
        (*A)->Info = X;
        (*A)->esq = NULL;
        (*A)->dir = NULL;
    } else if (X < (*A)->Info) {
        insere(&(*A)->esq, X);
    } else {
        insere(&(*A)->dir, X);
    }
}

void ordem(Arvore A) {
    if (A != NULL) {
        ordem(A->esq);
        printf("%d ", A->Info);
        ordem(A->dir);
    }
}

int SomaFolhas(Arvore A) {
    if (A == NULL) {
        return 0;
    }
    if (A->esq == NULL && A->dir == NULL) {
        return A->Info;
    }
    return SomaFolhas(A->esq) + SomaFolhas(A->dir);
}

bool EstritamenteBin(Arvore a) {
    if (a == NULL) {
        return true;
    }
    if ((a->esq == NULL && a->dir != NULL) || (a->esq != NULL && a->dir == NULL)) {
        return false;
    }
    return EstritamenteBin(a->esq) && EstritamenteBin(a->dir);
}

int main(void) {
    printf("Criar uma árvore binária e calcular a soma de suas folhas!\n");

    Arvore A = NULL;
    insere(&A, 5);
    insere(&A, 3);
    insere(&A, 7);
    insere(&A, 2);
    insere(&A, 4);
    insere(&A, 6);
    //insere(&A, 8);

    printf("Árvore em ordem: ");
    ordem(A);
    printf("\n");

    int Resultado = SomaFolhas(A);
    printf("Soma das folhas: %d\n", Resultado);

    bool EstritamenteBinaria = EstritamenteBin(A);
    printf("A árvore é estritamente binária? %s\n", EstritamenteBinaria ? "Sim" : "Não");

    return 0;
}
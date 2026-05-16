#include <stdio.h>
#include <stdbool.h>

struct No {
    int Info;
    struct No *Lig;
};

typedef struct No *Pilha;

Pilha TopoPilha(Pilha P) {
    return P;
}

void Empilha(Pilha *P, int X) {
    Pilha Novo = (Pilha)malloc(sizeof(struct No));
    Novo->Info = X;
    Novo->Lig = *P;
    *P = Novo;
}

bool Desempilha(Pilha *P, int *X) {
    if (*P == NULL) {
        return false; // Pilha vazia
    }
    Pilha Temp = *P;
    *X = Temp->Info;
    *P = Temp->Lig;
    free(Temp);
    return true;
}

bool PilhaVazia(Pilha P) {
    return P == NULL;
}

// Função para somar duas pilhas
Pilha SomaPilhas(Pilha P1, Pilha P2) {
    Pilha Resultado = NULL;
    Pilha InvTemp1 = NULL;
    Pilha InvTemp2 = NULL;

    while (P1 != NULL) {
        int valor;
        Desempilha(&P1, &valor);
        Empilha(&InvTemp1, valor);
    }

    while (P2 != NULL) {
        int valor;
        Desempilha(&P2, &valor);
        Empilha(&InvTemp2, valor);
    }

    while (InvTemp1 != NULL || InvTemp2 != NULL) {
        int valor1 = (InvTemp1 != NULL) ? InvTemp1->Info : 0;
        int valor2 = (InvTemp2 != NULL) ? InvTemp2->Info : 0;
        int soma = valor1 + valor2;

        Empilha(&Resultado, soma);

        if (InvTemp1 != NULL) InvTemp1 = InvTemp1->Lig;
        if (InvTemp2 != NULL) InvTemp2 = InvTemp2->Lig;
    }

    return Resultado;
}

// Função para imprimir a pilha
void ImprimePilha(Pilha P) {
    Pilha Temp = P;
    while (Temp != NULL) {
        printf("%d ", Temp->Info);
        Temp = Temp->Lig;
    }
    printf("\n");
}

int main(void) {
    printf("Realizar a soma de duas pilhas com tamanhos variados!\n");

    // Criar pilha A com os valores 2. 6, 4, 1
    Pilha A = NULL;
    Empilha(&A, 2);
    Empilha(&A, 6);
    Empilha(&A, 4);
    Empilha(&A, 1);

    // Criar pilha B com os valores 3, 7, 5, 3
    Pilha B = NULL;
    Empilha(&B, 3);
    Empilha(&B, 7);
    Empilha(&B, 5);
    Empilha(&B, 3);

    // Somar as pilhas A e B
    Pilha Resultado = SomaPilhas(A, B);

    // Imprimir o resultado da soma
    printf("Resultado da soma: ");
    ImprimePilha(Resultado);

    // Criar pilha C com os valores 8, 2, 3, 4
    Pilha C = NULL;
    Empilha(&C, 8);
    Empilha(&C, 2);
    Empilha(&C, 3);
    Empilha(&C, 4);

    // Criar pilha D com os valores 8, 15, 2
    Pilha D = NULL;
    Empilha(&D, 8);
    Empilha(&D, 15);
    Empilha(&D, 2);

    // Somar as pilhas C e D
    Pilha Resultado2 = SomaPilhas(C, D);
    // Imprimir o resultado da soma
    printf("Resultado da soma: ");
    ImprimePilha(Resultado2);


    return 0;
}

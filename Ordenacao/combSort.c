#include <stdio.h>
#include <stdlib.h>
//Discentes: Jonas Henrique

void combSort(int *vet, int tam)
{
    int intervalo, troca = 0, comp = 0;
    int aux;
    intervalo = tam;

    while (intervalo > 1)
    {
        //fator de encolhimento aproximadamente 1.3
        intervalo = (int)(intervalo / 1.3);
        if (intervalo == 9 || intervalo == 10)
        {
            intervalo = 11;
        }
        if (intervalo < 1)
        {
            intervalo = 1;
        }
        for (int i = 0; i + intervalo < tam; i++)
        {
            comp++;
            if ((*(vet + i)) > (*(vet + i + intervalo)))
            {
                aux = (*(vet + i));
                (*(vet + i)) = (*(vet + i + intervalo));
                (*(vet + i + intervalo)) = aux;
                troca++;
            }
        }
    }
    printf("Quantidade de TROCAS: %d\n", troca);
    printf("Quantidade de COMPARACAO: %d\n", comp);
}
void aleatorio(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        (*(vet + i)) = (rand() % tam);
    }
}
void mostrarVetor(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", (*(vet + i)));
    }
    printf("\n");
}
int main()
{

    int vet1[10];
    int vet2[1000];
    int vet3[10000];

    //quiser mostrar os vetores é descomentar abaixo
    printf("-----VETOR 1 DE 10 POSIÇÕES------------\n");
    printf("ORDEM ALEATÓRIA:\n");
    aleatorio(vet1, 10);
    //mostrarVetor(vet3, 10);
    combSort(vet1, 10);
    printf("\n");

    printf("--------VETOR 2 DE 1000 POSIÇÕES-----------\n");
    printf("ORDEM ALEATÓRIA:\n");
    aleatorio(vet2, 1000);
    //  mostrarVetor(vet3, 1000);
    combSort(vet2, 1000);
    printf("\n");

    printf("--------VETOR 3 DE 10000 POSIÇÕES---------\n");
    printf("ORDEM ALEATÓRIA:\n");
    aleatorio(vet3, 10000);
    // mostrarVetor(vet3, 10000);
    combSort(vet3, 10000);
    printf("\n");
}
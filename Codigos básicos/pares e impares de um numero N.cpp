#include <iostream>
//mostrar todos os pares e impares de 0 ate N
int main()
{
    int n;
    scanf("%d", &n);
    int nVerifica, qtdPares = 0, qtdImpares = 0;
    ;
    printf("Pares:\n");
    for (int i = 0; i < n; i++)
    {
        nVerifica = i % 2;
        if (nVerifica == 0)
        {
            qtdPares++;
            printf("%d ", i);
        }
    }
    printf("\nImpares:\n");
    for (int i = 0; i < n; i++)
    {
        nVerifica = i % 2;
        if (nVerifica == 1)
        {
            qtdImpares++;
            printf("%d ", i);
        }
    }
    printf("\n\nQuantidade de pares: %d\nQuantidade de Impares: %d\n", qtdPares, qtdImpares);
    printf("\n");
}
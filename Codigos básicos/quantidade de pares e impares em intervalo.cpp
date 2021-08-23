#include <iostream>
// mostrar pares e impares de x até <= n
int main()
{
    int n, x;
    do
    {
        printf("Informe o X ate <= Y:\n");
        scanf("%d %d", &x, &n);
    } while (x > n);
    int qtdPar = 0, qtdImpar = 0;
    for (int i = x; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            qtdPar++;
        }
        else
        {
            qtdImpar++;
        }
    }

    printf("\nQuantidade de pares: %d\nQuantidade de Impares: %d\n", qtdPar, qtdImpar);
}
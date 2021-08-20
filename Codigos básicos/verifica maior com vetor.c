#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Informe a quantidade de compras::\n");
    scanf("%d", &n);
    float compras[n], maior = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Informe o valor da compra do cliente[ %d ]\n", (i + 1));
        scanf("%f", &compras[i]);

        if (compras[i] > maior)
        {
            maior = compras[i];
        }
    }
    printf("A compra maior foi %.2f \n", maior);
}

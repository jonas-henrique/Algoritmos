#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd;
    float valorcompra, Nmaior = 0;
    printf("Informe a quantidade de clientes:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("Informe o valor da compra do cliente[ %d ]\n", i + 1);
        scanf("%f", &valorcompra);
        if (valorcompra > Nmaior)
        {
            Nmaior = valorcompra;
        }
    }
    printf("Maior: %.2f", Nmaior);
}

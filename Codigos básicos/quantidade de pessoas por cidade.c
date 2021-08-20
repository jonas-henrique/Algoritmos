#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cidade, cont1, cont2, cont3, qtd;
    cont1 = 0;
    cont2 = 0;
    cont3 = 0;
    printf("Tem quantas pessoas?\n");
    scanf("%d", &qtd);
    printf("==Informe a cidade==\n");
    printf("1 - Pau dos Ferros --RN\n");
    printf("2 - Apodi -- RN\n");
    printf("3 - Rafael Fernandes -- RN\n");
    for (int i = 0; i < qtd; i++)
    {
        printf("Pessoa %d\n", i + 1);
        scanf("%d", &cidade);
        if (cidade == 1)
        {
            cont1++;
        }
        else if (cidade == 2)
        {
            cont2++;
        }
        else if (cidade == 3)
        {
            cont3++;
        }
        else
        {
            printf("INEXISTENTE\n");
        }
    }

    printf("PAU DOS FERROS - %d clientes \n", cont1);
    printf("APODI - %d clientes\n", cont2);
    printf("RAFAEL FERNANDES - %d clientes\n", cont3);
}

#include <stdio.h>
#include <stdlib.h>
//discentes: Jonas Henrique
// questao: mostrar media, min e max de tensoes de N entradas
int main()
{
    int n;
    int *pn = &n;
    int continuar = 0;

    while (continuar == 0)
    {
        printf("Informe a quantidade de medições:\n");
        scanf("%d", pn);

        int *tensao = malloc(*pn * sizeof(int));

        int tensaoMedia = 0;
        int *ptensaoMedia = &tensaoMedia;
        int soma = 0;
        int *psoma = &soma;

        int maior = 0;
        int *pmaior = &maior;
        int menor = 0;
        int *pmenor = &menor;

        printf("Preencha as tensões registradas abaixo:\n");

        for (int i = 0; i < *pn; i++)
        {
            printf("Tensão [%d]:", i);
            scanf("%d", (tensao + i));
        }

        *pmaior = tensao[0];
        *pmenor = tensao[0];
        for (int i = 0; i < *pn; i++)
        {
            *psoma = *psoma + (*(tensao + i));

            if ((*(tensao + i)) > *pmaior)
            {
                *pmaior = (*(tensao + i));
            }
            else if ((*(tensao + i)) < *pmenor)
            {
                *pmenor = (*(tensao + i));
            }
        }

        *ptensaoMedia = *psoma / (*pn);
        printf("\n");
        printf("Tensão Máxima: %d\n", *pmaior);
        printf("Tensão Menor: %d\n", *pmenor);
        printf("Tensão Média: %d\n\n", *ptensaoMedia);
        printf("Deseja calcular novamente? 1- SIM || qualquer n° para NAO\n");
        scanf("%d", &continuar);
    }
    printf("FIM\n");
}
#include <stdio.h>
#include <stdlib.h>
//discentes: Jonas Henrique
//Calcular media de N notas de N alunos
void calcMatriz(int *pallDiscentes, int *pnotas)
{
    int totalColunas = (*pnotas + 1);
    // total de notas + 1(matricula), o numero do aluno basta dizer o "i"
    int **notasDiscente = (int **)malloc(totalColunas * sizeof(int *));

    if (notasDiscente == NULL)
    {
        printf("Memória insuficiente!");
        exit(1);
    }
    for (int i = 0; i < *pallDiscentes; i++)
    {
        notasDiscente[i] = (int *)malloc((*pallDiscentes) * sizeof(int));
        if (notasDiscente == NULL)
        {
            printf("Memória insuficiente!");
            exit(1);
        }
    }
    if (*pnotas == 3)
    {
        for (int i = 0; i < *pallDiscentes; i++)
        {
            printf("Insira matricula aluno %d:\n", (i + 1));
            scanf("%d", &notasDiscente[i][0]);
            printf("Insira Nota 1 Nota 2 Nota 3:\n");
            scanf("%d%d%d", &notasDiscente[i][1], &notasDiscente[i][2], &notasDiscente[i][3]);
        }
        printf("Alunos\t\t\tMatrícula\t\tNota 1\t\tNota 2\t\tNota 3\n");
        printf("----------------------------------------------------------------------------------------\n");
        for (int i = 0; i < *pallDiscentes; i++)
        {
            printf("Aluno %d\t\t\t%d\t\t\t%d\t\t%d\t\t%d \n", (i + 1), notasDiscente[i][0], notasDiscente[i][1], notasDiscente[i][2], notasDiscente[i][3]);
        }
        printf("\n");
        for (int i = 0; i < *pallDiscentes; i++)
        {
            free(notasDiscente[i]);
        }

        free(notasDiscente);
    }
    else if (*pnotas == 4)
    {
        for (int i = 0; i < *pallDiscentes; i++)
        {
            printf("Insira matricula aluno %d:\n", (i + 1));
            scanf("%d", &notasDiscente[i][0]);
            printf("Insira Nota 1 Nota 2 Nota 3 Nota 4:\n");
            scanf("%d%d%d%d", &notasDiscente[i][1], &notasDiscente[i][2], &notasDiscente[i][3], &notasDiscente[i][4]);
        }
        printf("\n");
        printf("Alunos\t\t\tMatrícula\t\tNota 1\t\tNota 2\t\tNota 3\t\tNota 4\n");
        printf("----------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < *pallDiscentes; i++)
        {
            printf("Aluno %d\t\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t%d \n", (i + 1), notasDiscente[i][0], notasDiscente[i][1], notasDiscente[i][2], notasDiscente[i][3], notasDiscente[i][4]);
        }
        printf("\n");
        for (int i = 0; i < *pallDiscentes; i++)
        {
            free(notasDiscente[i]);
        }

        free(notasDiscente);
    }
}

int main()
{
    int allDiscentes, notas, continuar = 1;
    int *pallDiscentes = &allDiscentes;
    int *pnotas = &notas;
    int *pcontinuar = &continuar;

    while (*pcontinuar == 1)
    {
        printf("Digite a quantidade de Alunos:\n");
        scanf("%d", pallDiscentes);
        printf("Digite a quantidade de Notas:\n");
        scanf("%d", pnotas);
        if (*pnotas != 3 && *pnotas != 4)
        {
            while (*pnotas != 3 && *pnotas != 4)
            {
                printf("Só é possivel ter 3 ou 4 notas, informe novamente a quantidade de notas:\n");
                scanf("%d", pnotas);
            }
        }
        printf("\n");
        calcMatriz(pallDiscentes, pnotas);

        printf("Deseja continuar? (1 - SIM) (2 - NÃO) \n");
        scanf("%d", pcontinuar);
        if (*pcontinuar != 1 && *pcontinuar != 2)
        {
            while (*pcontinuar != 1 && *pcontinuar != 2)
            {
                printf("Numero diferente de 1 ou 2, digite novamente:\n");
                scanf("%d", pcontinuar);
            }
        }
    }
}

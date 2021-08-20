#include <stdio.h>
#include <string.h>
//Discentes: Jonas Henrique
/*
    Questao: 
    1) permutar dois numeros
    2) somar elementos de vetor de N posicoes
    3) Informar tamanho de vetor de string
    4) concartenização de duas strings
*/
void permutacao()
{
    int vetor[2];
    printf("Informe dois numeros:\n");
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", (vetor + i));
    }
    int auxiliar = 0;

    for (int i = 0; i < 2; i++)
    {
        auxiliar = vetor[i];
        vetor[i] = vetor[2 - 1];
        vetor[2 - 1] = auxiliar;
    }
    printf("RESULTADO DOS NUMEROS PERMUTADOS:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%d\t", (*(vetor + i)));
    }
    //como é so dois numeros eu pensei em tipo imprimir o ultimo e depois o primeiro,
    //mas acredito que a forma certa é atribuir uma variavel auxiliar e inverter os numeros comparando
    //com auxiliar
    printf("\n------------------------------------------------------");
}
void somaVetor()
{
    int tamanho, resultado = 0;
    int *ptamanho = &tamanho;
    int *presultado = &resultado;
    printf("FUNÇÃO SOMAR ELEMENTOS DO VETOR:\n\n");
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", ptamanho);

    int vetor[*ptamanho];
    for (int i = 0; i < *ptamanho; i++)
    {
        printf("[%d]:", i);
        scanf("%d", (vetor + i));
    }

    for (int i = 0; i < *ptamanho; i++)
    {
        *presultado = *presultado + (*(vetor + i));
    }
    printf("SOMA DO VETOR:  %d\n", *presultado);
    printf("------------------------------------------------------");
}
void calcTamanhoString()
{
    char mensagem[100];
    char *pmensagem = &mensagem;
    int tamanho;
    int *ptamanho = &tamanho;
    printf("CALCULO DE TAMANHO DE STRING:\n\n");

    printf("Escreva qualquer string:\n");
    scanf(" %[^\n]s", pmensagem);

    *ptamanho = strlen(pmensagem);

    printf("\nTamanho da String: %d \n", *ptamanho);
    printf("------------------------------------------------------");
}

void concaternarString()
{
    char txt1[200];
    char *ptxt1 = &txt1;
    char txt2[200];
    char *ptxt2 = &txt2;
    printf("CONCARTENIZAÇÃO DE DUAS STRINGS\n\n");

    printf("Preencha a string1:\n");
    scanf(" %[^\n]s", ptxt1);
    printf("Preencha a string2:\n");
    scanf(" %[^\n]s", ptxt2);

    strncat(ptxt1, ptxt2, 200);

    printf("\nJunção das Strings: %s\n", ptxt1);
    printf("------------------------------------------------------");
}

int main()
{

    //PROBLEMA 1
    permutacao();

    printf("\n\n");

    //PROBLEMA 2
    somaVetor();

    printf("\n\n");

    //PROBLEMA 3
    calcTamanhoString();

    printf("\n\n");

    //PROBLEMA 4
    concaternarString();

    printf("\n\n");

    //OBS: em alguns casos foi usado o scanf(" %[^\n]s") para pegar os espaços entre palavras
}

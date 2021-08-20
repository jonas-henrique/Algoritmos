#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

int ano(int a)
{
    time_t ano;
    ano = time(NULL);
    struct tm tm = *localtime(&ano);
    int b = ((tm.tm_year + 1900) - a);
    return b;
}
bool verifica(int d)
{
    bool dd = true;
    if (d == 1)
    {
        return dd;
    }
    else
    {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idade, anoNasc, opc;
    bool ab = true;
    while (ab)
    {
        printf("Digite sua idade: \n");
        scanf("%d", &idade);

        anoNasc = ano(idade);
        printf("voce nasceu em %d \n", anoNasc);
        printf("Deseja continuar? 1(sim) e 2(nao)\n");
        scanf("%d", &opc);
        if ((opc == 1) || (opc == 2))
        {
            ab = verifica(opc);
        }
        else
        {
            while ((opc != 1) && (opc != 2))
            {
                printf("OPCAO INEXISTENTE, CORRIJA!\n\n");
                printf("Deseja continuar? 1(sim) e 2(n�o)\n");
                scanf("%d", &opc);
                ab = verifica(opc);
            }
        }
    }
}

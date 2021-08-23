#include <iostream>
//mostrar todos os primos de X ate <=N
void quantidade_pares_impares(int n, int p, int resto, int c, int b)
{
    for (int x = n; x <= p; x++)
    {
        resto = x % 2;
        if (resto == 0)
        {
            c++;
        }
        else
        {
            b++;
        }
    }
    printf("Quantidade de numeros PARES: %d\n", c);
    printf("Quantidade de numeros IMPARES: %d\n", b);
}
int quantidade_primos(int n, int p)
{
    int contador = 0, cont_primo = 0;
    for (int x = n; x <= p; x++)
    {
        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
            {
                contador++;
                break;
            }
        }
        if (contador == 0)
        {
            cont_primo++;
        }
        contador = 0;
    }
    return cont_primo;
}
void mostrar_primos(int cont_primo, int *vetPrimo)
{
    for (int i = 0; i < cont_primo; i++)
    {
        printf("%d\t", vetPrimo[i]);
    }
}
int main()
{
    int c = 0, resto, b = 0;
    int n, p, contador = 0;
    do
    {
        printf("Informe o intervalor [n,p]\n");
        scanf("%d %d", &n, &p);
    } while (n > p);

    system("clear");
    printf("Intervalo usado: %d <= X <= %d ou [%d,%d]\n\n", n, p, n, p);
    quantidade_pares_impares(n, p, resto, c, b);

    int cont_primo = quantidade_primos(n, p);

    printf("\nTotal de Primos: %d\n", cont_primo);
    int vetPrimo[cont_primo], m = 0;

    for (int x = n; x <= p; x++)
    {
        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
            {
                contador++;
                break;
            }
        }
        if (contador == 0)
        {
            vetPrimo[m] = x;
            m++;
        }
        contador = 0;
    }
    printf("Numeros primos de %d a %d:\n", n, p);
    mostrar_primos(cont_primo, vetPrimo);

    printf("\n");
}
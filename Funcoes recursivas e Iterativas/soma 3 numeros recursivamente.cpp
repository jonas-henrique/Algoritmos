#include <iostream>
//somar 3 numeros recursivamente
int soma(int a, int b, int m)
{
    if (a == 0 && b == 0)
    {
        return m;
    }
    else if (b == 0)
    {
        return soma(a - 1, b, m + 1);
    }
    else if (a == 0)
    {
        return soma(a, b - 1, m + 1);
    }
    else
    {
        return soma(a - 1, b - 1, m + 2);
    }
}
int main()
{
    int a, b, m;
    printf("Digite 3 numeros para somar recursivamente:\n");
    scanf("%d %d %d", &a, &b, &m);
    printf("Resultado: %d\n", soma(a, b, m));
}
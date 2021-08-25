#include <stdio.h>
//Calcular recursivamente X^N
int expoente(int x, int n)
{
    if (n != 0 && n != 1)
    {
        return x * expoente(x, n - 1);
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
}
int main()
{
    int x, n;
    printf("Digite x e n\n");
    scanf("%d %d", &x, &n);
    printf("%d^%d = %d\n", x, n, expoente(x, n));
}
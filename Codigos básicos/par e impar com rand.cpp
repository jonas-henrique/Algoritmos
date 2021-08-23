#include <iostream>
//Par e impar com rand();
int main()
{
    int vetPar[10], vetImpar[10], x, nPar, nImpar;
    scanf("%d", &x);

    for (int i = 0; i < 10; i++)
    {
        do
        {
            nPar = rand() % x;
        } while ((nPar % 2) == 1);
        do
        {
            nImpar = rand() % x;
        } while ((nImpar % 2) == 0);

        vetPar[i] = nPar;
        vetImpar[i] = nImpar;
    }
    printf("Pares:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", vetPar[i]);
    }
    printf("\nImpares:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", vetImpar[i]);
    }
    printf("\n");
}
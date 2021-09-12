#include <iostream>

int main()
{
    int n, div, resto;
    printf("informe o dividendo e o divisor\n");
    scanf("%d %d", &n, &div);
    resto = n % div;
    printf("Resto de %d/%d = %d\n", n, div, resto);
}
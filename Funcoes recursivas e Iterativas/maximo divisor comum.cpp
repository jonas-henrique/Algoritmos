#include <iostream>
int mdc(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return mdc(a - b, b);
    else
        return mdc(a, b - a);
}
int main()
{
    int a, b;
    printf("Digite dois numeros:\n");
    scanf("%d %d", &a, &b);
    printf("MDC(%d,%d): %d\n", a, b, mdc(a, b));
}
#include <stdio.h>
//aumento de 10%
int main()
{
    float p1, p2, p3, s1, s2, s3;
    char n1[10], n2[10], n3[10];

    printf("\t\t\tSistema financeiro do apostasbr.com\n\n");

    printf("Digite o nome do cambista 1:\n");
    scanf("%s", &n1);
    printf("Informe o salario de %s :\n", n1);
    scanf("%f", &p1);

    printf("Digite o nome do cambista 2:\n");
    scanf("%s", &n2);
    printf("Informe o salario de %s :\n", n2);
    scanf("%f", &p2);

    printf("Digite o nome do cambista 3:\n");
    scanf("%s", &n3);
    printf("Informe o salario de %s :\n", n3);
    scanf("%f", &p3);

    s1 = (((p1 * 10) / 100) + p1);
    s2 = (((p2 * 10) / 100) + p2);
    s3 = (((p3 * 10) / 100) + p3);

    printf("O salario de %s �:R$ %.2f \n", n1, s1);
    printf("O salario de %s �:R$ %.2f \n", n2, s2);
    printf("O salario de %s �:R$ %.2f \n", n3, s3);
}

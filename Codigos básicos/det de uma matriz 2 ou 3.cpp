#include <iostream>
//det de matrix 2x2 e 3x3
int main()
{
    int n;
    printf("Digite a dimensão(2 ou 3):\n");
    scanf("%d", &n);
    while (n > 3 || n < 2)
    {
        printf("Errado! digite valores de uma matriz N x N!\n");
        printf("Digite a dimensão(2 ou 3):\n");
        scanf("%d", &n);
    }

    int mat[n][n], determinante;
    printf("Preencha a matriz %d x %d\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("mat[%d][%d]:", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
            printf("\n");
        }
    }
    printf("Matriz:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    if (n == 2)
    {
        //para matriz 2x2
        determinante = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }
    else
    {
        //para 3x3
        int a, b, c;
        a = 1 * ((mat[1][1] * mat[2][2]) - (mat[2][1] * mat[1][2]));
        b = (-1) * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]));
        c = 1 * ((mat[1][0] * mat[2][1]) - (mat[2][0] * mat[1][1]));
        determinante = (mat[0][0] * a) + (mat[0][1] * b) + (mat[0][2] * c);
        //formula:Cij = (-1)^i+j - Mij
    }

    printf("\nDeterminante: %d\n", determinante);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Lista simplesmente encadeada
//Feito por Jonas Henrique
typedef struct no NO;
struct no
{
    char nome[20];
    int mat;
    float n1, n2, n3, media;
    char status[20];
    NO *proximo;
};
typedef struct LISTA
{
    NO *primeiro;
} lista;

lista *criaLista()
{
    lista *lst = malloc(sizeof(lista));
    lst->primeiro = NULL;
    return lst;
}
NO *criaNo()
{
    NO *novo_no = malloc(sizeof(NO));
    return novo_no;
}
NO *inserir(lista *lst, char *nome, int mat, float n1, float n2, float n3, float media, char *status)
{
    NO *novo = criaNo();
    strcpy(novo->nome, nome);
    novo->mat = mat;
    novo->n1 = n1;
    novo->n2 = n2;
    novo->n3 = n3;
    novo->media = media;
    strcpy(novo->status, status);
    novo->proximo = NULL;

    if (lst->primeiro == NULL)
    {
        lst->primeiro = novo;
    }
    else
    {
        NO *aux = lst->primeiro;
        while (aux->proximo != NULL) // trazer o ultimo
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    return lst;
}
void remover(lista *lst, int mat)
{
    NO *aux = lst->primeiro;
    NO *anterior;
    int cont = 0;
    if (lst->primeiro != NULL)
    {
        //encontrar o anterior
        while (aux != NULL && aux->mat != mat)
        {
            anterior = aux;
            aux = aux->proximo;
            //quando aux->n = n ele para e diz q o anterior é aux(antes do n)
        }
        while (aux != NULL)
        {
            if (aux->mat = mat)
            {
                if (aux == lst->primeiro)
                {
                    lst->primeiro = aux->proximo;
                }
                else
                {
                    anterior->proximo = aux->proximo;
                }
                cont++;
                printf("%s foi removido!\n", aux->nome);
                free(aux);
                break;
            }
            aux = aux->proximo;
        }
    }
    if (cont == 0)
    {
        printf("Não encontrado!\n");
    }
    mostrar(lst);
}
void mostrar(lista *lst)
{
    int cont = 1;
    NO *aux = lst->primeiro;
    if (lst != NULL)
    {
        while (aux != NULL)
        {
            printf("------------------------------------\n");
            printf("Discente %d\n", cont);
            printf("Nome: %s\n", aux->nome);
            printf("Matricula: %d\n", aux->mat);
            printf("Nota 1: %.1f\nNota 2: %.1f\nNota 3: %.1f\n", aux->n1, aux->n2, aux->n3);
            printf("Media: %.1f\n", aux->media);
            printf("Situacao: %s\n", aux->status);
            printf("------------------------------------\n");
            cont++;
            aux = aux->proximo;
        }
    }
    else
    {
        printf("A lista está vazia!\n");
    }
}
void buscar(lista *lst, int mat)
{
    NO *aux = lst->primeiro;
    int cont = 0;
    if (lst != NULL)
    {
        while (aux != NULL)
        {
            if (aux->mat == mat)
            {
                printf("ENCONTRADO!!!\n");
                printf("Nome: %s\n", aux->nome);
                printf("Matricula: %d\n", aux->mat);
                printf("Nota 1: %.1f\nNota 2: %.1f\nNota 3: %.1f\n", aux->n1, aux->n2, aux->n3);
                printf("Media: %.1f\n", aux->media);
                printf("Situacao: %s\n", aux->status);
                printf("------------------------------------\n");
                cont++;
            }
            aux = aux->proximo;
        }
    }
    if (cont == 0)
    {
        printf("nao achei\n");
    }
}
int main()
{
    lista *lst = criaLista();
    char nome[20];
    int mat;
    float n1, n2, n3, media;
    char status[20];
    int continuar = 1;
    int cont = 1;

    while (continuar == 1)
    {
        printf("Discente %d\n", cont);
        printf("Digite o nome: ");
        scanf("%s", nome);
        printf("Matricula: ");
        scanf("%d", &mat);
        printf("Digite 3 notas:\n");
        scanf("%f %f %f", &n1, &n2, &n3);
        media = ((n1 + n2 + n3) / 3);
        if (media >= 7)
        {
            strcpy(status, "APROVADO");
        }
        else if (media > 3.4 && media < 7)
        {
            strcpy(status, "RECUPERACAO");
        }
        else
        {
            strcpy(status, "REPROVADO");
        }
        lst = inserir(lst, nome, mat, n1, n2, n3, media, status);
        cont++;
        printf("Deseja adicionar mais algum discente? 1 para SIM e qualquer numero para NAO\n");
        scanf("%d", &continuar);
    }
    system("clear");
    printf("Mostrando dados...\n");
    mostrar(lst);
    printf("Busque uma pessoa, digite a matricula:\n");
    scanf("%d", &mat);
    system("clear");
    buscar(lst, mat);
    printf("Informe matricula para remover\n");
    scanf("%d", &mat);
    system("clear");
    remover(lst, mat);
}
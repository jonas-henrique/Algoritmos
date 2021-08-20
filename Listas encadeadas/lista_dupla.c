#include <stdio.h>
#include <stdlib.h>
//Lista duplamente encadeada
//feito por Jonas Henrique
typedef struct no NO;
struct no
{
    char nome[20];
    int mat;
    float n1, n2, n3, media;
    char status[20];
    NO *proximo;
    NO *anterior;
};
typedef struct LISTA
{
    NO *primeiro;
    NO *ultimo;
} lista;
lista *criaLista(void)
{
    lista *lst = (lista *)malloc(sizeof(lista));
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    return lst;
}
NO *criaNo(void)
{
    NO *novo_no = (NO *)malloc(sizeof(NO));
    return novo_no;
}

NO *inserirElemento(lista *lst, char *nome, int mat, float n1, float n2, float n3, float media, char *status)
{
    NO *novo_no = criaNo();
    if (novo_no == NULL)
    {
        puts("ERRO");
    }
    strcpy(novo_no->nome, nome);
    novo_no->mat = mat;
    novo_no->n1 = n1;
    novo_no->n2 = n2;
    novo_no->n3 = n3;
    novo_no->media = media;
    strcpy(novo_no->status, status);
    novo_no->proximo = NULL;
    novo_no->anterior = lst->ultimo;

    if (lst->primeiro == NULL)
    {
        lst->primeiro = novo_no;
    }
    else
    {
        lst->ultimo->proximo = novo_no;
    }
    lst->ultimo = novo_no;

    return lst;
}
NO *buscar(lista *lst, int mat)
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
    else
    {
        printf("lista esta vazia\n");
    }
    if (cont == 0)
    {
        printf("não ha nenhum\n");
    }
    return lst;
}
void remover(lista *lst, int mat)
{
    NO *aux = lst->primeiro;
    int cont = 0;
    if (lst != NULL)
    {
        while (aux != NULL)
        {
            if (aux->mat == mat)
            {
                printf("%s foi deletado!\n", aux->nome);
                if (aux == lst->primeiro)
                {
                    if (aux->proximo != NULL)
                    {
                        lst->primeiro = aux->proximo;
                        //aux->proximo->anterior
                        lst->primeiro->proximo->anterior = NULL;
                        lst->primeiro->anterior->proximo = NULL;
                    }
                    else
                    {
                        lst->primeiro = NULL;
                        lst->ultimo = NULL;
                    }
                }
                else
                {
                    aux->anterior->proximo = aux->proximo;
                }
                cont++;
                free(aux);
                break;
            }
            aux = aux->proximo;
        }
        if (cont == 0)
        {

            printf("nao encontrado\n");
        }
        mostrar(lst);
    }
}
void mostrar(lista *lst)
{
    NO *aux = lst->primeiro;
    int cont = 1;
    if (lst != NULL)
    {
        if (aux == NULL)
        {
            printf("vazia\n");
        }
        else
        {
            printf("Mostrando dados...\n");
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
    }
    else
    {
        printf("Lista vazia!\n");
    }
}
void liberar(lista *lst)
{
    NO *aux = lst->primeiro;
    while (aux != NULL)
    {
        NO *recebe = aux->proximo;
        free(aux);
        aux = recebe;
    }
    free(lst);
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
        lst = inserirElemento(lst, nome, mat, n1, n2, n3, media, status);
        cont++;
        printf("Deseja adicionar mais algum discente? 1 para SIM e qualquer numero para NAO\n");
        scanf("%d", &continuar);
    }
    system("clear");
    mostrar(lst);
    printf("Busque uma pessoa, digite a matricula:\n");
    scanf("%d", &mat);
    system("clear");
    buscar(lst, mat);
    printf("Informe matricula para remover\n");
    scanf("%d", &mat);
    system("clear");
    remover(lst, mat);
    liberar(lst);
}
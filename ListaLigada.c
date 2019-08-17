/* Lista ligada simplesmente encadeada desenvolvida em C
   Possui a estrutura de dados de uma lista ligada e as operações sobre
   Autor: Cayo Eduardo
   Trabalho feito em 2017 alterado e modificado em 2019
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//

/* Nó e funções do nó:
   -Inicializar
   -Inserir
   -Alterar
   -Excluir
*/

//No
struct _No
{
    int ano;

    struct _No *prox;

};

typedef struct _No No;

/*Inicializa - 
    Recebe um ponteiro para Nó não inicializado e devolve o ponteiro inicializado
*/
No* inicializa(No *head)
{   
    head = (No*)malloc(sizeof(No));
    head->ano = 0;

    head->prox = NULL;
    
    return(head);
}

/* Vazia - 
    Retorna 1 se a lista estiver vazia, 0 se não estiver
*/
int vazia(No *head)
{
    return(head->prox == NULL);
}

/* Cria No -
    Retorna o endereço para um Nó criado com os parametros escolhidos

No* criaNo(char *nome, char *genero, int ano)
{
    No* novo = (No*)malloc(sizeof(No));

    if(novo == NULL)
    {   
        printf("Espaco insuficiente na memoria!\n");
        exit(1);
    }
    
    //strcpy(string_destino, string_origem);
    strcpy(novo->nome,nome);
    strcpy(novo->genero,genero);

    novo->ano = ano;
    novo->prox = NULL;

    return(novo);
}

*/

/* Insere -
    Insere o nó na Lista
*/
int insere(No *head, int ano)
{   
    //Lista vazia
    if(head->prox == NULL)
    {
        No *novo = (No*)malloc(sizeof(No));
        
        novo->ano = ano;
        novo->prox = NULL;
        head->prox = novo;
        
        return(1);
    }
    //Lista com pelo menos 1 elemento
    else
    {   
         //No temporário
        No* tmp = head->prox;

        //Busca a proxima posição da lista (prox = null)
        while(tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = (No*)malloc(sizeof(No));
        tmp->prox->ano = ano;
        tmp->prox->prox = NULL;

        return(1);
    }

    //Inserção não concluida
    return(0);
    
}

/*Exibe-
   Retorna uma lista de todos os jogos cadastrados
*/
void exibe(No *head)
{
    No* tmp;

    for(tmp = head->prox; tmp != NULL; tmp = tmp->prox)
    {
        printf("%d\n", tmp->ano);
    }
}

int main()
{   
    No *head = inicializa(head);
    int a = insere(head, 12);
    int b = insere(head, 25);
    exibe(head);

    return(0);
}
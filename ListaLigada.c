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
    char nome[100];
    char genero[100];
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
*/
No* criaNo(char *nome, char *genero, int ano)
{
    No* novo = (No*)malloc(sizeof(No));

    if(!novo)
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

/* Insere -
    Insere o nó na Lista
*/
int insere(No *head, char *nome, char *genero, int ano)
{   
    //Lista vazia
    if(vazia(head))
    {
        No *novo = criaNo(nome,genero,ano);
     
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

        tmp->prox = criaNo(nome, genero, ano);
        

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
    tmp = head->prox;

    printf("\nLista: \n\n");

    while(tmp)
    {
        printf("Nome: %s\n", tmp->nome);
        printf("Genero: %s\n", tmp->genero);
        printf("Ano: %d\n", tmp->ano); 
        printf("\n");
        tmp = tmp->prox;  
    }

}

/* Exclui -
   Remove item da lista com base no nome.
*/
int exclui(No *head, int ano)
{   
    //Lista vazia
    if(vazia(head))
    {
        printf("Lista vazia!\n");
        return(0);
    }

    else
    {   
        //Dois nós para ter o ponteiro anterior.
        No* tmp1 = head;
        No* tmp2 = head->prox;

        while(tmp2 != NULL && tmp2->ano != ano)
        {
            tmp1 = tmp1->prox;
            tmp2 = tmp2->prox;
        }

            if(tmp2 == NULL)
            {
                printf("Nao encontrado!\n");
                return(0);
            }
            else
            {
                No* aux = tmp2->prox;
                free(tmp2);
                tmp1->prox = aux;
                printf("Remocao bem sucedida!");

                return(1);   
            }
    }
}


int main()
{   
    No *head = inicializa(head);
    int a = insere(head,"Alan wake","Action", 2010);
    int b = insere(head,"Half-Life","Action", 1997);
    int c = insere(head,"Pokemon","Adventure", 1994);
    int d = insere(head, "Counter-Strike", "Action", 1998);
    exclui(head, 1994);
    exibe(head);
    printf("\n %d %d %d\n", a,b,c);


    return(0);
}

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
Disciplina return_disciplina(Lista_disciplina lista_main)
{
   // lnode_dis* curr = lista_main->next;
    int n=0,i,j;
    Lista_disciplina correr,ultimo;
    correr = lista_main;
    ultimo =lista_main;
    Disciplina disc;
    while(correr->next != NULL)
    {
        correr = correr->next;
        n+=1;
        printf("%d-%s\n",n,correr->disciplina->nome);
    }
    scanf("%d",&i);
    fflush(stdin);

    for(j=0;j<i;j++)
    {
        ultimo=ultimo->next;
    }
    disc.nome= ultimo->disciplina->nome;
    disc.docente=ultimo->disciplina->docente;
    return disc;
}
Disciplina return_disciplina_alt(Lista_disciplina lista_main)
{
   // lnode_dis* curr = lista_main->next;
    int n=0,i,j;
    char* nom;
    Lista_disciplina correr,ultimo;
    correr = lista_main;
    ultimo =lista_main;
    Disciplina disc;
    while(correr->next != NULL)
    {
        correr = correr->next;
        n+=1;
        printf("%d-%s\n",n,correr->disciplina->nome);
    }
    scanf("%d",&i);
    fflush(stdin);

    for(j=0;j<i;j++)
    {
        ultimo=ultimo->next;
    }
    disc.nome= ultimo->disciplina->nome;
    disc.docente=ultimo->disciplina->docente;
    nom = disc.nome;
    altera_disciplina(lista_main,disc,nom);
    return disc;
}
Lista_disciplina cria_lista_disciplina(){
    Lista_disciplina aux;

    aux = (Lista_disciplina) malloc (sizeof (Lista_disciplina_node));

    if (aux != NULL){
        aux->disciplina = NULL;
        aux->next = NULL;
    }

    return aux;
}

void procura_lista_disciplina (Lista_disciplina lista,char* chave, Lista_disciplina *ant, Lista_disciplina *actual)
{
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && strcmp((*actual)-> disciplina->nome,chave)!=0)
    {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (strcmp((*actual)-> disciplina->nome,chave)!=0))
        *actual = NULL;   /* Se elemento não encontrado*/
}
void insere_lista_disciplina (Lista_disciplina lista,Disciplina *disciplina)
{
    Lista_disciplina no;
    Lista_disciplina ant, inutil;
    no = cria_lista_disciplina();
    if (no != NULL)
    {
        no->disciplina = disciplina;
        procura_lista_disciplina(lista,disciplina->nome, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}
void registra_disciplina(Lista_disciplina lista_main,char* nome,char* docente)
{
    Disciplina* disciplina;

    disciplina=(Disciplina*)malloc(sizeof(Disciplina));
    if(disciplina==NULL)
        printf("Erro na alocação de memória.\n");

    disciplina->nome=nome;
    disciplina->docente=docente;
    insere_lista_disciplina(lista_main, disciplina);
}
void cria_disciplina(Lista_disciplina lista)
{
    system("cls");
    char* nome;
    char* docente;
    printf("Introduza o nome da disciplina\n");
    nome = devolve_nome();
    printf("Introduza o docente da disciplina\n");
    docente = devolve_nome();
    registra_disciplina(lista,nome,docente);


}
void imprime_lista_disciplina (Lista_disciplina lista)
{
    Lista_disciplina l= lista->next; /* Salta o header */
    while (l)
        {
            printf("Nome da disciplina: %s \n", l->disciplina->nome);
            printf("Docente da disciplina: %s \n", l->disciplina->docente);
            l=l->next;
        }
        _getch();
}
void elimina_disciplina(Lista_disciplina lista,Disciplina disciplina,Lista_exame lista2)
{
    char* nom;
    Lista_disciplina ant;
    Lista_disciplina actual;
    nom= disciplina.nome;
    procura_lista_disciplina(lista,disciplina.nome,&ant, &actual);
    if (actual != NULL)
    {
        ant->next = actual->next;
        free (actual);
    }
    elimina_lista_exame_disc(lista2,nom);
}
void altera_disciplina(Lista_disciplina lista,Disciplina disciplina,char* nome)
{
{
    Lista_aluno ant;
    Lista_aluno actual;
    procura_lista_disciplina(lista,disciplina.nome,&ant, &actual);
    if (actual != NULL)
    {
        ant->next = actual->next;
        free (actual);
    }
    altera_disciplina_2(lista,nome);

}
}
void altera_disciplina_2(Lista_disciplina lista,char* nome)
{
    char* docente;
    printf("Introduza o novo docente:\n");
    docente = devolve_nome();

    registra_disciplina(lista,nome,docente);


}

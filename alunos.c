#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
Aluno* escolher_aluno(Lista_aluno lista_main)
{
    int n=0,i,j;
    Lista_aluno correr,ultimo;
    Aluno* aluno;
    correr = lista_main;
    //ultimo =lista_main;
    while(correr->next != NULL)
    {
        correr = correr->next;
        n+=1;
        printf("%d-%s\n",n,correr->aluno->nome);
    }
    scanf("%d",&i);
    fflush(stdin);
    for(j=0;j<i;j++)
    {
        lista_main=lista_main->next;
    }
    aluno=lista_main;
    return aluno;
}

void return_aluno(Lista_aluno lista_main)
{
    int n=0,i,j;
    Aluno aluno;
    Lista_aluno correr,ultimo;
    correr = lista_main;
    ultimo =lista_main;
    while(correr->next != NULL)
    {
        correr = correr->next;
        n+=1;
        printf("%d-%s\n",n,correr->aluno->nome);
    }
    scanf("%d",&i);
    fflush(stdin);

    for(j=0;j<i;j++)
    {
        ultimo=ultimo->next;
    }
    aluno.ano= ultimo->aluno->ano;
    aluno.curso= ultimo->aluno->curso;
    aluno.nome=ultimo->aluno->nome;
    aluno.numero=ultimo->aluno->numero;
    aluno.regime=ultimo->aluno->regime;
    elimina_aluno(lista_main,aluno);
    return;
}
void return_aluno_alt(Lista_aluno lista_main)
{
    int n=0,i,j,num;
    Aluno aluno;
    Lista_aluno correr,ultimo;
    correr = lista_main;
    ultimo =lista_main;
    while(correr->next != NULL)
    {
        correr = correr->next;
        n+=1;
        printf("%d-%s\n",n,correr->aluno->nome);
    }
    scanf("%d",&i);
    fflush(stdin);

    for(j=0;j<i;j++)
    {
        ultimo=ultimo->next;
    }
    aluno.ano= ultimo->aluno->ano;
    aluno.curso= ultimo->aluno->curso;
    aluno.nome=ultimo->aluno->nome;
    aluno.numero=ultimo->aluno->numero;
    aluno.regime=ultimo->aluno->regime;
    num = aluno.numero;
    altera_aluno(lista_main,aluno,num);
    return;
}
char* regime_aluno()
{
    int n;
    char* nome;
    while (1>0)
    {
        printf("1-Estudante\n");
        printf("2-Trabalhador estudante\n");
        printf("3-Atleta\n");
        printf("4-Dirigente Associativo\n");
        printf("5-Aluno de Erasmus\n");
        scanf("%d", &n);
        fflush(stdin);
        switch(n)
        {
            case 1:
                nome = "Estudante";
                return nome;
            case 2:
                nome = "Trabalhador estudante";
                return nome;
            case 3:
                nome = "Atleta";
                return nome;
            case 4:
                nome = "Dirigente Associativo";
                return nome;
            case 5:
                nome = "Aluno de Erasmus";
                return nome;
            default:
                printf("Erro introduza um numero de 1 a 3\n");
                break;
        }
    }
}
Lista_aluno cria_lista_aluno(void)
{
     Lista_aluno aux;
     aux = (Lista_aluno) malloc (sizeof (Lista_aluno_node));
     if (aux != NULL)
    {
        aux->aluno = NULL;
        aux->next = NULL;
    }
    return aux;
}

void procura_lista_aluno (Lista_aluno lista,int *chave ,Lista_aluno *ant, Lista_aluno *actual)
{
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)-> aluno->numero != chave)
    {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->aluno->numero != chave)
        *actual = NULL;   /* Se elemento não encontrado*/
}

void insere_lista_aluno (Lista_aluno lista,Aluno *aluno)
{
    Lista_aluno no;
    Lista_aluno ant, inutil;
    no = cria_lista_aluno();
    if (no != NULL)
    {
        no->aluno = aluno;
        procura_lista_aluno (lista,aluno->numero, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}
void registra_aluno(Lista_aluno lista_main,char* nome,char* curso,char* regime,int numero,int ano)
{
    Aluno* aluno;

    aluno=(Aluno*)malloc(sizeof(Aluno));
    if(aluno==NULL)
        printf("Erro na alocação de memória.\n");

    aluno->nome=nome;
    aluno->curso=curso;
    aluno->regime=regime;
    aluno->numero=numero;
    aluno->ano=ano;
    insere_lista_aluno(lista_main, aluno);
}
void cria_aluno(Lista_aluno lista)
{
    system("cls");
    char* nome;
    char* curso;
    char* regime;
    int numero,ano;
    printf("Introduza o nome do aluno\n");
    nome = devolve_nome();
    printf("Introduza o curso do aluno\n");
    curso = devolve_nome();
    printf("Introduza o regime do aluno\n");
    regime = regime_aluno();
    printf("Introduza o numero do aluno\n");
    numero = devolve_inteiro();
    printf("Introduza o ano do aluno\n");
    ano = devolve_inteiro();
    registra_aluno(lista,nome,curso,regime,numero,ano);


}
void print_aluno(Aluno* aluno)
{
    printf("%s ", aluno -> nome);
    printf("%s ", aluno -> curso);
    printf("%s ", aluno -> regime);
    printf("%d ", aluno -> ano);
    printf("%d \n", aluno -> numero);
}
void imprime_lista_aluno (Lista_aluno lista)
{
    Aluno alun;
    Lista_aluno l = lista->next; /* Salta o header */
    while (l)
    {
        alun.nome= l->aluno->nome;
        alun.numero= l->aluno->numero;
        alun.regime= l->aluno->regime;
        alun.curso= l->aluno->curso;
        alun.ano= l->aluno->ano;
        printf("nome: %s\n", alun.nome);
        printf("numero: %d\n", alun.numero);
        printf("curso: %s\n", alun.curso);
        printf("regime: %s\n", alun.regime);
        printf("ano: %d\n", alun.ano);
        l=l->next;
    }
    _getch();
}
void elimina_aluno (Lista_aluno lista,Aluno aluno)
{
    Lista_aluno ant;
    Lista_aluno actual;
    procura_lista_aluno(lista,aluno.numero,&ant, &actual);
    if (actual != NULL)
    {
        ant->next = actual->next;
        free (actual);
    }
}
void altera_aluno(Lista_aluno lista,Aluno aluno,int num)
{
{
    Lista_aluno ant;
    Lista_aluno actual;
    procura_lista_aluno(lista,aluno.numero,&ant, &actual);
    if (actual != NULL)
    {
        ant->next = actual->next;
        free (actual);
    }
    altera_aluno_2(lista,num);

}
}
void altera_aluno_2(Lista_aluno lista,int numero)
{
    char* nome;
    char* curso;
    char* regime;
    int ano;
    printf("Introduza o nome do aluno\n");
    nome = devolve_nome();
    printf("Introduza o curso do aluno\n");
    curso = devolve_nome();
    printf("Introduza o regime do aluno\n");
    regime = regime_aluno();
    printf("Introduza o ano do aluno\n");
    ano = devolve_inteiro();
    registra_aluno(lista,nome,curso,regime,numero,ano);


}

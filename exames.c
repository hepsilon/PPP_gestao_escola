#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "header.h"



char* tipo_exame()
{
    int n;
    char* nome;
    while (1>0)
    {
        system("cls");
        printf("Introduza o tipo de exame\n");
        printf("1-Frequência\n");
        printf("2-Exame Normal\n");
        printf("3-Exame Recurso\n");
        printf("4-Exame de Época especial\n");
        scanf("%d", &n);
        fflush(stdin);
        switch(n)
        {
            case 1:
                nome = "Frequência";
                return nome;
            case 2:
                nome = "Exame Normal";
                return nome;
            case 3:
                nome = "Exame de Recurso";
                return nome;
            case 4:
                nome = "Exame de Época Especial";
                return nome;
            default:
                printf("Erro introduza um numero de 1 a 3\n");
                break;
        }
    }
}
Lista_exame cria_lista_exame(){
    Lista_exame aux;

    aux = (Lista_exame) malloc (sizeof (Lista_exame_node));

    if (aux != NULL){
        aux->exame = NULL;
        aux->next = NULL;
    }
    else
        printf("Erro na alocação de memória.\n");
    return aux;
}
void procura_lista_exame (Lista_exame lista,int chave, Lista_exame *ant, Lista_exame *actual)
{
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && (*actual)->exame < chave)
    {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)-> exame != chave)
        *actual = NULL;   /* Se elemento não encontrado*/
}
void elimina_lista_exame_data (Lista_exame lista, Lista_exame *ant, Lista_exame *actual)
{
    *ant = lista;
    *actual = lista->next;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int date2,i;
    date2 =  (tm.tm_year + 1900)*365*24*60+ (tm.tm_mon + 1)*30*24*60+ (tm.tm_mday*24*60)+ (tm.tm_hour)*60+ (tm.tm_min);
    printf("%d",date2);
    while ((*actual) != NULL && (*actual)-> exame->data.total > date2)
    {
        printf("%d",(*actual)-> exame->data.total);
        scanf("%d",&i);
        fflush(stdin);
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)-> exame->data.total > date2)
        *actual = NULL;   /* Se elemento não encontrado*/
}
void insere_lista_exame (Lista_exame lista,Exame *exame)
{
    Lista_exame no;
    Lista_exame ant, inutil;
    no = cria_lista_exame();
    if (no != NULL)
    {
        no->exame = exame;
        procura_lista_exame (lista,exame->sala, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}
void registra_exame(Lista_exame lista_main_exame,char*tipo ,int sala,Disciplina disc,Data data)
{
    Exame* exame;

    exame=(Exame*)malloc(sizeof(Exame));
    if(exame==NULL)
        printf("Erro na alocação de memória.\n");

    exame->tipo=tipo;
    exame->sala=sala;
    exame->disciplina=disc;
    exame->data=data;
    exame->aluno=cria_lista_aluno();
    insere_lista_exame(lista_main_exame, exame);
}
void cria_exame(Lista_exame lista_exame_main,Lista_disciplina lista_disciplina_main)
{
    system("cls");
    Data data;
    Disciplina disciplina;
    char* tipo;
    int sala;
    tipo = tipo_exame();
    printf("Introduza a sala do exame\n");
    sala = devolve_inteiro();
    printf("Introduza o número relativo à disciplina do exame.\n");
    disciplina = return_disciplina(lista_disciplina_main);
    printf("Introduza a data do exame.\n");
    data = devolve_data();
    registra_exame(lista_exame_main,tipo,sala,disciplina,data);
}
void imprime_lista_exame (Lista_exame lista)
{
    Exame exame;
    Lista_exame l = lista->next; /* Salta o header */
    while (l)
    {
        exame.data= l->exame->data;
        exame.disciplina= l->exame->disciplina;
        exame.sala= l->exame->sala;
        exame.tipo= l->exame->tipo;
        printf("Disciplina: %s\n", exame.disciplina);
        printf("Sala: %d\n", exame.sala);
        printf("Tipo: %s\n", exame.tipo);
        printf("Data: %d/%d/%d %d:%d\n",exame.data.dia,exame.data.mes,exame.data.ano,exame.data.hora,exame.data.minuto);
        l=l->next;
    }

}
void elimina_lista_exame (Lista_exame lista)
{
    Lista_exame ant;
    Lista_exame actual;

    elimina_lista_exame_data(lista, &ant, &actual);
    if (actual != NULL)
    {
        ant->next = actual->next;
        free (actual);
    }
}

void elimina_lista_exame_disc (Lista_exame lista,char* disc)
{
    Lista_exame ant;
    Lista_exame actual;

    elimina_lista_exame_disc2(lista,disc,&ant, &actual);
    if (actual != NULL)
    {
        ant->next = actual->next;
        free (actual);
    }
}
void elimina_lista_exame_disc2(Lista_exame lista,char* chave, Lista_exame *ant, Lista_exame *actual)
{
    *ant = lista;
    *actual = lista->next;
    while ((*actual) != NULL && strcmp((*actual)-> exame->disciplina.nome,chave)!=0)
    {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (strcmp((*actual)-> exame->disciplina.nome,chave)!=0))
        *actual = NULL;   /* Se elemento não encontrado*/
}



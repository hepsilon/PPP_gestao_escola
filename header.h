#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX_STRING 5000

// estruturas


typedef struct aluno
{
    char* nome;
    char* curso;
    char* regime; // estudante trabalhador...
    int numero;
    int ano;

}Aluno;


typedef struct sala
{
    int numero;
}Sala;

typedef struct data
{
int dia;
int mes;
int ano;
int hora;
int minuto;
int total;

}Data;

typedef struct disciplina
{
    char* nome;
    char* docente;
}Disciplina;

typedef struct lnode_alu *Lista_aluno;
typedef struct lnode_alu
{
    Aluno *aluno;
    Lista_aluno next;
} Lista_aluno_node;

typedef struct exame
{
    char* tipo;
    int sala;
    Data data;
    Disciplina disciplina;
    Lista_aluno aluno;
}Exame;


// listas e nodes
typedef struct lnode_exa *Lista_exame;
typedef struct lnode_dis *Lista_disciplina;
typedef struct lnode_sla *Lista_sala;


typedef struct lnode_exa
{
    Exame *exame;
    Lista_exame next;
} Lista_exame_node;

typedef struct lnode_dis
{
    Disciplina *disciplina;
    Lista_disciplina next;
} Lista_disciplina_node;

typedef struct lnode_sla
{
    Sala *sala;
    Lista_sala next;
}Lista_sala_node;

        //misc//
char* devolve_nome(void);
int devolve_inteiro(void);
Data devolve_data(void);
        //aluno//
Aluno* escolher_aluno(Lista_aluno lista_main);
void elimina_aluno(Lista_aluno lista,Aluno aluno);
void insere_lista_aluno(Lista_aluno lista,Aluno* aluno);
        //exame//
void elimina_lista_exame_disc (Lista_exame lista,char* disc);
void elimina_lista_exame_disc2(Lista_exame lista,char* chave, Lista_exame *ant, Lista_exame *actual);
Exame* escolher_exame(Lista_exame lista_exame_main);
        //disciplinas//
void elimina_disciplina (Lista_disciplina lista,Disciplina disciplina,Lista_exame lista2);

#endif // HEADER_H_INCLUDED

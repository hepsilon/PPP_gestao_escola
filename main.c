#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include "header.h"
#include "disciplinas.c"
#include "alunos.c"
#include "exames.c"
#include "misc.c"
#include "ficheiros.c"



int main()
{
    setlocale(LC_ALL,""); // Corrige problemas de acentos e Ç
    Lista_aluno lista_aluno_main;
    Lista_exame lista_exame_main;
    Lista_disciplina lista_disciplina_main;
    lista_aluno_main = cria_lista_aluno();
    lista_exame_main = cria_lista_exame();
    lista_disciplina_main = cria_lista_disciplina();

    //verificar_ficheiros();
    //carregar_ficheiro(lista_aluno_main,lista_disciplina_main,lista_exame_main);
    menu(lista_aluno_main,lista_disciplina_main,lista_exame_main);
    return 0;
}

void menu(Lista_aluno lista_aluno_main,Lista_disciplina lista_disciplina_main,Lista_exame lista_exame_main)
{
    char* a;
    while (1>0)
    {

        int n;
        system("cls");
        printf("1-Gestao alunos.\n");
        printf("2-Gestão de disciplinas\n");
        printf("3-Gestão de exames\n");
        printf("4-Apagar exames realizados\n");
        printf("5-Listar exames\n");
        printf("6-Terminar o programa e guardar ficheiros\n");

        scanf("%d", &n);
        fflush(stdin);
        switch(n)
        {
            case 1:
                um(lista_aluno_main);
                break;
            case 2:
                dois(lista_disciplina_main,lista_exame_main);
                break;
            case 3:
                tres(lista_exame_main,lista_disciplina_main);
                break;
            case 4:
                elimina_lista_exame(lista_exame_main);
                break;
            case 5:
                imprime_lista_exame(lista_exame_main);
                _getch();
                fflush(stdin);
                if (a=1)
                    break;
                else
                    break;
            case 6:
                guardar_ficheiros(lista_aluno_main,lista_disciplina_main,lista_exame_main);
                return;

            default:
                printf("Erro introduza um numero de 1 a 10\n");
                break;
        }
    }
}

void um(Lista_aluno lista_main){
    while (1>0)
    {
        int n;
        system("cls");
        printf("1- Criar informaçao de aluno.\n");
        printf("2- Alterar informaçao aluno.\n");
        printf("3- Apagar informaçao de aluno.\n");
        printf("4- Voltar ao menu inicial.\n");
        printf("5- Listar alunos\n");

        scanf("%d",&n);
        fflush(stdin);
        switch (n)
        {
        case 1:
            cria_aluno(lista_main);
            break;
        case 2:
            return_aluno_alt(lista_main);
            break;
        case 3:
            return_aluno(lista_main);
            break;
        case 4:
            return;
        case 5:
            imprime_lista_aluno(lista_main);
            break;
        default:
            printf("Erro introduza um numero de 1 a 5");
            break;
        }
    }

}

void dois(Lista_disciplina lista_main,Lista_exame lista_exame){
    char* nome,docente;
    while (1>0)
    {
        int n;
        system("cls");
        printf("1- Criar informaçao da disciplina.\n");
        printf("2- Alterar informaçao da disciplina.\n");
        printf("3- Apagar informaçao da disciplina.\n");
        printf("4- Voltar ao menu inicial.\n");
        printf("5- Imprime lista de disciplinas\n");

        scanf("%d",&n);
        fflush(stdin);
        switch (n)
        {
        case 1:
            cria_disciplina(lista_main);
            break;
        case 2:
            return_disciplina_alt(lista_main);
            break;
        case 3:
            elimina_disciplina(lista_main,return_disciplina(lista_main),lista_exame);
            break;
        case 4:
            return;
            break;
        case 5:
            imprime_lista_disciplina(lista_main);
        default:
            printf("Erro introduza um numero de 1 a 5");
            break;
        }
    }

}

void tres(Lista_exame lista_main_exame,Lista_disciplina lista_main_disciplina){
    while (1>0)
    {
        int n;
        system("cls");
        printf("1- Criar exame.\n");
        printf("2- Configurar sala exame.\n");
        printf("3- Voltar ao menu inicial.\n");

        scanf("%d",&n);
        fflush(stdin);
        switch (n)
        {
        case 1:
            cria_exame(lista_main_exame,lista_main_disciplina);
            break;
        case 2:
            break;
        case 3:
            return;
        default:
            printf("Erro introduza um numero de 1 a 3");
            break;
        }
    }

}

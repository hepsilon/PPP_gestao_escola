#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void guardar_ficheiros(Lista_aluno lista_aluno_main, Lista_disciplina lista_disciplina_main,Lista_exame lista_exame_main){
    Lista_aluno la_aux;
    Lista_disciplina ld_aux;
    Lista_exame le_aux;
    FILE *ficheiro;
    int int_aux;

//Alunos
    ficheiro=fopen("alunos.txt", "w");
    la_aux=lista_aluno_main;
    while(la_aux->next!=NULL){
        la_aux=la_aux->next;
        fprintf(ficheiro, "%s;%s;%s;%d;%d", la_aux->aluno->nome, la_aux->aluno->curso,la_aux->aluno->regime,la_aux->aluno->numero,la_aux->aluno->ano);
        if(la_aux->next!=NULL)
            fprintf(ficheiro, "\n");
    }
    fclose(ficheiro);

//disciplinas
    ficheiro=fopen("disciplinas.txt", "w");
    ld_aux=lista_disciplina_main;
    while(ld_aux->next!=NULL){
        ld_aux=ld_aux->next;
        fprintf(ficheiro, "%s;%s",ld_aux->disciplina->nome,ld_aux->disciplina->docente);
        if(ld_aux->next!=NULL)
            fprintf(ficheiro, "\n");
    }
    fclose(ficheiro);
//exames
    Data data;
    ficheiro=fopen("exames.txt", "w");
    le_aux=lista_exame_main;
    while(le_aux->next!=NULL){
        le_aux=le_aux->next;
        data = le_aux->exame->data;
        fprintf(ficheiro, "%s;%d;%s;%d;%d;%d;%d/%d",le_aux->exame->tipo,le_aux->exame->sala,le_aux->exame->disciplina,data.dia,data.mes,data.ano,data.hora,data.minuto);
        if(le_aux->next!=NULL)
            fprintf(ficheiro, "\n");
    }


}

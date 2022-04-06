#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <unistd.h>
#include <ctype.h>
#include "header.h"
#define MAX_STRING 500

void retira_enter(char* str){
    int len;
    len=strlen(str);
    if(len>0 && str[len-1] == '\n')
        str[len-1] = '\0';
}

char* devolve_nome(){
    char *nome;
    char recebe[MAX_STRING];
    int contador, i, invalido;

    do{
        i=0;
        contador=0;
        invalido=0;
        fgets(recebe, MAX_STRING, stdin);
        retira_enter(recebe);
        while(recebe[i] != '\0'){
            if((recebe[i]>='A' && recebe[i]<='Z') || (recebe[i]>='a' && recebe[i]<='z') || recebe[i] == ' ')
                contador++;
            i++;
        }
        if(recebe[0] == ' ' || recebe[0] == '\0' || recebe[strlen(recebe)-1] == ' ' || contador != i){
            printf("Nome inválido. Insira de novo: ");
            invalido=1;
        }
    }while(invalido==1);

    nome=strdup(recebe);

    return nome;
}

int devolve_inteiro(){
    char numero[MAX_STRING];
    int i, aux;

    do{
        fgets(numero, MAX_STRING, stdin);
        retira_enter(numero);

        aux=0;
        for(i=0; numero[i] != '\0'; i++){
            if(isdigit(numero[i]))
                aux++;
        }
        if (aux != i || i==0)
            printf("Número introduzido inválido. Introduza de novo:");
        else if (strlen(numero)>10)
            printf("Apenas permitidos números até 10 dígitos. Introduza de novo: ");
    }while(aux != i || i==0 || strlen(numero)>10);

    /*passa de char para int*/

    return atoi(numero);
}

Data devolve_data()
{
    Data data;
    int a,minuto,hora,dia,mes,ano;
    int i=2;
    while(i>1)
    {
        printf("introduza o ano\n");
        a=devolve_inteiro();
        if (a>20)
        {
            ano = a;
            i=1;
        }
        else
            printf("Ano tem que ser maior que 2016\n");
    }
        i=2;
    while(i>1)
    {
        printf("introduza o mes\n");
        a=devolve_inteiro();
        if (a<13)
        {
            mes = a;
            i=1;
        }
        else
            printf("Meses tem que ser menor ou iguais a 12\n");
    }
        i=2;
    while(i>1)
    {
        printf("introduza o dia\n");
        a=devolve_inteiro();
        if (a<31)
        {
            dia = a;
            i=1;
        }
        else
            printf("dia tem que ser menor a 31\n");
    }
        i=2;
    while(i>1)
    {
        printf("introduza a hora\n");
        a=devolve_inteiro();
        if (a<24)
        {
            hora = a;
            i=1;
        }
        else
            printf("Horas tem que ser menor a 24\n");
    }
        i=2;
    while(i>1)
    {
        printf("introduza o minuto\n");
        a=devolve_inteiro();
        if (a<60)
        {
            minuto = a;
            i=1;
        }
        else
            printf("Minutos tem que ser menor a 60\n");
    }
    data.ano=ano;
    data.dia=dia;
    data.hora=hora;
    data.mes=mes;
    data.minuto=minuto;
    data.total= ((data.ano*365*24*60)+(data.mes*30*24*60)+(data.dia*24*60)+(data.minuto));
    return data;
}

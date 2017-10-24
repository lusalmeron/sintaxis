#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "parser.h"

int main(){
    FILE* archivo = fopen("archivo.txt","r");
    TOKEN tokenActual;
    tokenActual = scanear(archivo);
    while(tokenActual!=FDT){
	switch(tokenActual){
    case ID:
         printf("Identificador\n");
         break;
    case SUMA:
        printf("Suma\n");
        break;
    case RESTA:
        printf("Resta\n");
        break;
    case INICIO:
        printf("Inicio\n");
        break;
    case CONSTANTE:
        printf("Constante\n");
        break;
    case FIN:
        printf("Fin\n");
        break;
    case PARENT_IZQ:
        printf("Parentesis izquierdo\n");
        break;
    case PARENT_DER:
        printf("Parentesis derecho\n");
        break;
    case PUNTOYCOMA:
        printf("Punto y coma\n");
        break;
    case ASIGNACION:
        printf("Asignacion\n");
        break;
    case ESCRIBIR:
        printf("Escribir\n");
        break;
    case LEER:
        printf("Leer\n");
        break;
    case COMA:
        printf("Coma\n");
        break;
	};
	tokenActual =scanear(archivo);
    };
    printf("\nTermino\n");
	fclose(archivo);
    return 0;
}

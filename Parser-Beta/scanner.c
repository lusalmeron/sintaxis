#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define esNumero isdigit
#define esLetra islower
#define esMayuscula isupper



typedef enum {
    INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENT_IZQ, PARENT_DER, PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT
    } TOKEN;


    int esPalabraReservada(char buffer[]) {
        return (strcmp(buffer,"inicio") == 0 || strcmp(buffer,"fin") == 0 || strcmp(buffer,"leer") == 0 || strcmp(buffer,"escribir") == 0);
    }

    void resetearBuffer(char buffer[]){
        int i;
        for(i = 0;i < 33;i++) {
            buffer[i] = '\0';
        }
    }

    int esOperadorAditivo(char caracter) {
        return (caracter == '+' || caracter == '-');
    }

    int esCaracterPuntuacion(char caracter) {
        return (caracter == '(' || caracter == ')' || caracter == ',' || caracter == ';');
    }

TOKEN scanear(FILE *archivo){
        char caracter;
        char buffer[33]={'\0'};
        int i = 0;
        caracter = getc(archivo);
        while(!feof(archivo)) {
            if (esLetra(caracter)){
                while(!feof(archivo) && (esLetra(caracter) || esNumero(caracter))) {
                buffer[i] = caracter;
                i++;
                caracter = getc(archivo);
            }
                if(esPalabraReservada(buffer)) {
                    if(strcmp(buffer,"inicio") == 0) return INICIO;
                    else {
                        if(strcmp(buffer,"leer") == 0) return LEER;
                        else {
                            if(strcmp(buffer,"escribir") == 0) return ESCRIBIR;
                            else return FIN;
                        }
                    }
                }
                else {if(!isspace(caracter) && !esCaracterPuntuacion(caracter) && !esOperadorAditivo(caracter)) {
                        printf("Error Lexico. Un identificador solo comienza con una letra y esta compuesto por una cadena de letras y numeros\n");
                        printf("El Programa se cierra.");
                        exit(-1);
                }
                        else {
                         return ID;
                }
                }
                ungetc(caracter,archivo);
            }


            if(esNumero(caracter)){
                while(!feof(archivo) && esNumero(caracter)) {
                buffer[i] = caracter;
                i++;
                caracter = getc(archivo);
                }
                if(!esNumero(caracter) && !isspace(caracter) && !esCaracterPuntuacion(caracter) && !esOperadorAditivo(caracter)){
                        printf("Error Sintactico. Las constantes enteras estan compuestas solo por numeros.\n");
                        printf("El Programa se cierra.");
                        exit(-1);
                }
                else {
                    return CONSTANTE;
                }
                ungetc(caracter,archivo);
            }

            if(isspace(caracter)) {
                if(feof(archivo)) return FDT;
                resetearBuffer(buffer);
                i = 0;
                caracter = getc(archivo);
            }

            if(esOperadorAditivo(caracter)) {
                if(caracter == '+') {
                return SUMA;
            }
             if(caracter == '-') {
                return RESTA;
            }
            }

            if(caracter == '(') {
                return PARENT_IZQ;
            }

            if(caracter == ')') {
                return PARENT_DER;
            }

            if(caracter == ';') {
                return PUNTOYCOMA;
            }

            if(caracter == ':') {
                caracter = getc(archivo);
                if(caracter == '=') {
                    return ASIGNACION;
                }
                    else {
                        printf("Error Sintactico. Luego de un ':' debe seguir '='\n");
                        printf("El Programa se cierra.");
                        exit(-1);
                    }
            }

        if(esMayuscula(caracter)){
                printf("Error Sintactico. No se aceptan Mayusculas\n");
                printf("El Programa se cierra.");
                exit(-1);
        }
    }
    if(feof(archivo)) return FDT;

}

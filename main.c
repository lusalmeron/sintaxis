#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "scanner.h"

int main(){
    FILE* archivo = fopen("archivo.txt","r");
    char tokenActual[24]={'\0'};
	strcpy(tokenActual,scanear(archivo));
	while (tokenActual != FDT){
	printf("- %s \n", tokenActual);
	strcpy(tokenActual,scanear(archivo));
	};
    fclose(archivo);
    return 0;
}

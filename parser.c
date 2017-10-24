typedef enum {
    INICIO, FIN, LEER, ESCRIBIR, ID, CONSTANTE, PARENT_IZQ, PARENT_DER, PUNTOYCOMA, COMA, ASIGNACION, SUMA, RESTA, FDT
    } TOKEN;

bool match(TOKEN tok) {
    if (scanear(archivo) == tok) return true else return false;
    };

void objetivo (void) {
    programa();
    match(FDT);
    };

void programa(void) {
    match(INICIO);
    listaSentencias();
    match(FIN);
    };

void listaSentencias(void){
    sentencia();
    while(1) {
        switch(scanear(archivo)){
        case ID: case LEER: case ESCRIBIR:
            sentencia();
            break;
        default:
            return;
        }
    }
}

void sentencia(void) {
    TOKEN tok = scanear();
    switch(tok){
case ID:
    match(ID);
    match(ASIGNACION);
    expresion();
    match(PUNTOYCOMA);
    break;
case LEER:
    match(LEER);
    match (PARENT_IZQ);
    listaIdentificadores();
    match(PARENT_DER);
    match(PUNTOYCOMA);
    break;
case ESCRIBIR:
    match(ESCRIBIR);
    match(PARENT_IZQ);
    listaExpresiones();
    match(PARENT_DER);
    match(PUNTOYCOMA);
    break:
default:
    errorSintactico(tok); ///MODELAR
    break;
    }
}
void expresion(void){
TOKEN t;
primaria();
for(int t=scanear(archivo);t==SUMA||t==RESTA;t==scanear(archivo)){
    operadorAditivo();
    primaria();
}
}
void operadorAditivo(void){
TOKEN t=scanear(archivo);
if(t==SUMA||t==RESTA)
    match(t);
else
    errorSintactico(t);
}

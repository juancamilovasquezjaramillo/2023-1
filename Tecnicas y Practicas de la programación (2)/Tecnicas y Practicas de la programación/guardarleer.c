#include <stdio.h>
/*VARIABLES A GUARDAR:
*/
void guardarvariablesint(int var) {
    // Abrir archivo en modo escritura
    FILE *archivo = fopen("datos.txt", "w");
    if (archivo != NULL) {
        // Escribir en el archivo
        fprintf(archivo, "%d\n", var);
        // Cerrar el archivo
        fclose(archivo);
        printf("La informacion se ha guardado correctamente en datos.txt.\n");
    } else {
        printf("No se pudo abrir el archivo.\n");
    }
}

int leervariables() {
    int retorno;
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo != NULL) {
        // Leer y mostrar el contenido línea por línea
        char linea[100];
        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            int retorno = linea;
        }
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }
    return retorno;
}

int main(){
    printf("%s","Prueba de Lectura y guardado de datos\n");
    int Prueba = 48524;
    guardarvariablesint(Prueba);
    char pruebalectura[100] = leervariables();
    printf("%d",pruebalectura);
}
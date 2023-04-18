#include <stdio.h>
int main(void)
{
    FILE *file;
    char text[] = "Hello, World!"; // Texto por guardar

    file = fopen("output.txt", "w"); // Abrir archivo en modo de lectura
    if (file == NULL)                // Verificar que el archivo abrio correctamente
    {
        printf("Error opening file.\n");
        return 1;
    }
    else
    {
        fprintf(file, "%s", text); // Escribir el archivo
        fclose(file);              // Cerrar el archivo
    }

    return 0;
}
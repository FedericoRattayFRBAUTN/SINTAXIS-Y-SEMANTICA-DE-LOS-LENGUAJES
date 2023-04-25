/*
CONSIGNAS:
------------------------------------------------------------------
 (19) Longitud de una cadena
 (20) Determinar si una cadena dada es vacía.
 (21) Concatenación de dos cadenas.
 (22) Determinar si una subcadena es Prefijo de una cadena dada.
------------------------------------------------------------------
*/

#include <stdio.h>

int SIZE = 32;

// 19- Recibe un array de chars, devuelve su longitud
int string_length(char array[])
{
    int length = 0;
    for (int i = 0; i < SIZE; i++)
    {
        char current_character = array[i];

        if (current_character != '\0')
        {
            length++;
        }
    }

    return length;
}

// 20- Recibe un array de chars, devuelve si es vacio
int string_is_empty(char array[])
{
    int result = string_length(array);

    // TRUE
    if (result == 0)
    {
        return 0;
    }
    // FALSE
    else
    {
        return 1;
    }
}

// 21- Recibe 2 arrays de chars, devuelve un tercero resultado de concatenar los 2 anteriores
char *string_concatenate(char array_1[], char array_2[], char new_string[], int new_string_length)
{
    int first_string_length = string_length(array_1);
    int secnd_string_length = string_length(array_2);

    for (int i = 0; i < first_string_length; i++)
    {
        new_string[i] = array_1[i];
    }
    for (int i = first_string_length; i < new_string_length; i++)
    {
        int j = i - first_string_length;
        new_string[i] = array_2[j];
    }

    return new_string;
}

// 22- Recibe 2 arrays de chars, devuelve si uno es prefijo de la otra
int string_is_prefix(char string[], char sub_string[])
{
    int str_len = string_length(string);
    int substr_len = string_length(sub_string);
    int is_prefix = 0;

    if (substr_len <= str_len)
    {
        for (int i = 0; i < substr_len; i++)
        {
            char current_str_char = string[i];
            char current_substr_char = sub_string[i];

            if (current_substr_char != current_str_char)
            {
                is_prefix = 1;
            }
        }
    }
    else
    {
        is_prefix = 1;
    }

    return is_prefix;
}

int main(void)
{
    char generic_string_1[32] = "first string";
    char generic_string_2[32] = "second string";
    char generic_string_3[32] = "";
    char generic_string_4[32] = "fir";
    int first_string_length;
    int secnd_string_length;
    int new_string_length;
    int result1;
    int result2;
    int result4;

    //------------------------------------------------------------------
    // TEST LENGTH
    //------------------------------------------------------------------
    result1 = string_length(generic_string_1);
    printf("String length = %i \n", result1);
    //------------------------------------------------------------------

    //------------------------------------------------------------------
    // TEST IS EMPTY
    //------------------------------------------------------------------
    result2 = string_is_empty(generic_string_3);
    printf("Is string empty? = %i \n", result2);
    //------------------------------------------------------------------

    //------------------------------------------------------------------
    // TEST CONCAT
    //------------------------------------------------------------------
    // Calcular longitud string concatenada
    first_string_length = string_length(generic_string_1);
    secnd_string_length = string_length(generic_string_2);
    new_string_length = first_string_length + secnd_string_length;
    // Concatenar string
    char new_string[new_string_length];
    char *result3 = string_concatenate(generic_string_1, generic_string_2, new_string, new_string_length);
    // Mostrar resultado
    for (int i = 0; i < new_string_length; i++)
    {
        char current_char = result3[i];
        if (current_char != '\0')
        {
            printf("[%c]", current_char);
        }
    }
    printf("\n");
    //------------------------------------------------------------------

    //------------------------------------------------------------------
    // TEST PREFIX
    //------------------------------------------------------------------
    result4 = string_is_prefix(generic_string_1, generic_string_4);
    printf("Is string prefix? = %i", result4);
    //------------------------------------------------------------------

    return 0;
}
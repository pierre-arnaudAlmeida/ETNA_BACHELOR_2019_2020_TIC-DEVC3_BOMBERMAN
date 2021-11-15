/*
    Converti un nombre en un chaine de caractères
*/
void to_string(char text[], int nb)
{
    int rest;
    int x = nb;
    int lenght = 0;
 
    while (x != 0) {
        lenght++;
        x /= 10;
    }

    for (int i = 0; i < lenght; i++) {
        rest = nb % 10;
        nb = nb / 10;
        text[lenght - (i + 1)] = rest + '0';
    }
    
    if (lenght == 0) {
        text[0] = '0';
        text[1] = '\0';
    } else {
        text[lenght] = '\0';
    }
}

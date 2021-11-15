/*
    Vérifie si un string passé en paramètre est un integer ou pas
*/
bool is_int(char *nb)
{
    int i = 0;
    int correct = 1;

    while (nb[i] != '\0') {
        if (nb[i] < '0' || nb[i] > '9')
            correct = 0;     
        i++;
    }
    
    if (correct == 0)
        return false;

    return true;
}

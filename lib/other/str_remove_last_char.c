/*
    Supprime le dernier caractère d'un mot
*/
char* str_remove_last_char(char* text)
{
    int i = 0;
    
    while (text[i] != '\0')
        i++; 
    text[i-1] = '\0';

    return text;
}

/*
    Ajoute une chaine de caractères à une autre chaine de caractères passé en paramètre
*/
void add_new_char_to_str (char *text, int lenght, int count, char *new_text)
{
    if (strlen(text) < lenght)
        strcat(text, new_text);
    if (count == 0)
        text[0] = '\0';
}

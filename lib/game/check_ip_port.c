/*
    Vérifie si l'ip et le port sont correctement remplis et renvoie une valeur 1 ou 0 en fonction du cas
    Ecrit un message d'erreur dans une variable pour qu'il soit afficher
*/
int check_ip_port(char *ip, char *port, char *message)
{
    char delimiter[] = ".";
    int count = search_iteration(ip, '.');
    char *text = strtok(ip, delimiter);

    while (text != NULL) {
        if (!is_int(text)) {
            add_new_char_to_str(message, STR_MAX_SIZE, 1, IP_ERROR_FORMAT);
            return 1;
        } else {
            if (atoi(text) > 255) {
                add_new_char_to_str(message, STR_MAX_SIZE, 1, IP_ERROR_FORMAT_2);
                return 1;
            }
        }
        text = strtok(NULL, delimiter);
    }
    if (count != 3) {
        add_new_char_to_str(message, STR_MAX_SIZE, 1, IP_ERROR_FORMAT_3);
        return 1;
    }
    if (!is_int(port)) {
        add_new_char_to_str(message, STR_MAX_SIZE, 1, PORT_ERROR_FORMAT);
        return 1;
    }
    return 0;
}

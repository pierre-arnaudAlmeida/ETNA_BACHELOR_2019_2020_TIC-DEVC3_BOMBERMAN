/*
    Récupère une adresse ip en paramètre et la converti en une chaine de caractères,
    ensuite on ajoute cette chaine de caractères à la chaine passé en paramètre
*/
void to_str_player_address(char text[] ,struct sockaddr_in addr)
{
    char tmp[4];

    to_string(tmp, addr.sin_addr.s_addr & 0xff);
	strcat(text, tmp);
    strcat(text, ".");
    to_string(tmp, (addr.sin_addr.s_addr & 0xff00) >> 8);
    strcat(text, tmp);
    strcat(text, ".");
    to_string(tmp, (addr.sin_addr.s_addr & 0xff0000) >> 16);
    strcat(text, tmp);
    strcat(text, ".");
    to_string(tmp, (addr.sin_addr.s_addr & 0xff000000) >> 24);
    strcat(text, tmp);
}

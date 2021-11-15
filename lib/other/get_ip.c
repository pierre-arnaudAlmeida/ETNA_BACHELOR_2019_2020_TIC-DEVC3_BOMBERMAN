/*
    Récupère l'adresse ip de la machine et le met dans la valeur passé en paramètre
*/
void get_ip(char *ip)
{
    struct sockaddr_in name;
    socklen_t namelen = sizeof(name);
    struct sockaddr_in serv;
    int error;
    int dns_port = DNS_PORT;
    int sock = socket ( AF_INET, SOCK_DGRAM, 0);
    char buffer[15];
    const char* p;
    const char* google_dns_server = GOOGLE_DNS_SVR;
    
	memset(&serv, 0, sizeof(serv));

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(google_dns_server);
    serv.sin_port = htons(dns_port);

    error = connect(sock ,(const struct sockaddr*)&serv , sizeof(serv));
    error = getsockname(sock ,(struct sockaddr*)&name, &namelen);
    p = inet_ntop(AF_INET, &name.sin_addr, buffer, 100);
    close(sock);

	if (p != NULL)
		add_new_char_to_str(ip, IP_LENGHT, 1, buffer);
}

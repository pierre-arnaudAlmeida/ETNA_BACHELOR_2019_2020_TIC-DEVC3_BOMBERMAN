/*
	Vérification de l'accécisiblité du port et de l'adresse ip pour l'initialisation du serveur
*/
int check_sock(server *server_data)
{
    int option = 1;
    server_data->listenfd = 0;
    server_data->connfd = 0;

    server_data->listenfd = socket(AF_INET, SOCK_STREAM, 0);
  	server_data->serv_addr.sin_family = AF_INET;
  	server_data->serv_addr.sin_addr.s_addr = inet_addr(server_data->ip);
  	server_data->serv_addr.sin_port = htons(server_data->port);
    
    signal(SIGPIPE, SIG_IGN);
	if (setsockopt(server_data->listenfd, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), (char*)&option, sizeof(option)) < 0) {
		perror("ERROR SERVER: setsockopt failed");
    	return 1;
	}
  	if (bind(server_data->listenfd, (struct sockaddr*)&server_data->serv_addr, sizeof(server_data->serv_addr)) < 0) {
    	perror("ERROR SERVER: Socket binding failed");
    	return 1;
  	}
  	if (listen(server_data->listenfd, 10) < 0) {
    	perror("ERROR SERVER: Socket listening failed");
    	return 1;
	}
    return 0;
}

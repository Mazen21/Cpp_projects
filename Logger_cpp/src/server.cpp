#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

int main( int argc, char*argv[]){
	int socket_desc, client_sock, c, read_size;
	char client_message[256];
	struct sockaddr_in server, client;
	
	//First call to socket () function
	socket_desc = socket(AF_INET, SOCK_STREAM,0);
	
	if(socket_desc <0){
		perror("ERROR opening socket");
		exit(-1);
	}
	puts("Socket created");
	
	// Initialize socket structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);
	
	//Bind
	if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server)) <0){
		perror("bind failed");
		exit(-2);
	}
	puts("bind done");
	
	while(1){
		//Listen
		listen(socket_desc, 3);
		
		//Accept and incoming connection
		puts("\n");
		c = sizeof(struct sockaddr_in);
		
		//Accept connection from an incoming client
		client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		if(client_sock < 0){
			perror("accept failed");
			return 1;
		}
		//~ cout<<"\n";
		//Receive a message from client
		while((read_size = recv(client_sock, client_message, 2000, 0)) > 0){
			 write(client_sock , client_message , strlen(client_message));
			 puts(client_message);
		}
		
	memset(client_message,0,256);
	}
	return 0;
}

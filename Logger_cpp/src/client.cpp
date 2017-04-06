#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

int main( int argc, char*argv[]){
	int sock;
	struct sockaddr_in server;
	char message[1000];
	
	//Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		perror("Could not create socket");
	}
	puts("Socket Created");
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	
	//connect to remote server
	if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
		perror("connect failed. Error");
		return 1;
	}
	
	puts("Connected");
	puts("\n");
	//keep communicating with server
	memset(message,0,1000);
	strcpy(message,"123456\n");
	message[strlen(message)] = '\0';
	if (send(sock, (const char*)message, strlen((const char*)message), 0) < 0){
		puts("Send failed");
		return 1;
	}
		memset(message,0,1000);
	strcpy(message,"123\n");
	message[strlen(message)] = '\0';
	if (send(sock, (const char*)message, strlen((const char*)message), 0) < 0){
		puts("Send failed");
		return 1;
	}
		memset(message,0,1000);
	strcpy(message,"abcdefgh\n");
	message[strlen(message)] = '\0';
	if (send(sock, (const char*)message, strlen((const char*)message), 0) < 0){
		puts("Send failed");
		return 1;
	}
		memset(message,0,1000);
	strcpy(message,"ij\n");
	message[strlen(message)] = '\0';
	if (send(sock, (const char*)message, strlen((const char*)message), 0) < 0){
		puts("Send failed");
		return 1;
	}
	return 0;
}

#include "../header/Logger.hpp"
#include "string.h"
#include "ctime"
/*Logger Class*/
void Logger::printE(string const &mystr){
	cout <<"ERROR :"<<mystr<<"\n";
}
void Logger::printW(string const &mystr){
	cout <<"WARNING :"<<mystr<<"\n";
}
void Logger::printV(string const &mystr){
	cout <<"VERBOSITY :"<<mystr<<"\n";
}
string Logger::currentDateTime(){
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/*LoggerConsol class*/
void LoggerConsol::printE(string const &mystr){
	cout <<"\033[1;31m"<<"ERROR :"<< mystr<<"\033[0m\n";	
}
void LoggerConsol::printW(string const &mystr){
	cout <<"\033[1;33m"<<"WARNING :"<< mystr<<"\033[0m\n";	
}
void LoggerConsol::printV(string const &mystr){
	cout <<"\033[1;35m"<<"VERBOSITY :"<< mystr<<"\033[0m\n";	
}

LoggerFile::LoggerFile(string filname){
	this->logfile_name = filname;
	ofstream fout(this->logfile_name.c_str());
}

/*LoggerFile class*/
void LoggerFile::printE(string const &mystr){
	std::ofstream outfile;
	outfile.open(this->logfile_name.c_str(), std::ios_base::app);
	outfile <<"[ "<<this->currentDateTime().c_str()<<" ] "<<"ERROR     : "<<mystr<<"\n";
}
void LoggerFile::printW(string const &mystr){
	std::ofstream outfile;
	outfile.open(this->logfile_name.c_str(), std::ios_base::app);
	outfile <<"[ "<<this->currentDateTime().c_str()<<" ] "<<"WARNING   : "<<mystr<<"\n";
}
void LoggerFile::printV(string const &mystr){
	std::ofstream outfile;
	outfile.open(this->logfile_name.c_str(), std::ios_base::app);
	outfile <<"[ "<<this->currentDateTime().c_str()<<" ] "<<"VERBOSITY : "<<mystr<<"\n";	
}

/*LoggerTCP class*/
LoggerTCP::LoggerTCP(){
	//Create socket
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
	if(this->sock == -1){
		perror("Could not create socket");
	}
	puts("Socket Created");
	
	this->server.sin_addr.s_addr = inet_addr("127.0.0.1");
	this->server.sin_family = AF_INET;
	this->server.sin_port = htons(8888);
	
	//connect to remote server
	if(connect(this->sock, (struct sockaddr*)&(this->server), sizeof(this->server)) < 0){
		perror("connect failed. Error");
	}
	
	puts("Connected");
	puts("\n");
}

void LoggerTCP::printE(string const &mystr){
	char server_reply[2000];
	string output = "[ "+this->currentDateTime()+" ] " + "ERROR     : " + mystr;
	if (send(sock, (const char*)output.c_str(), strlen((const char*)output.c_str()), 0) < 0){
		puts("Send failed");
	}
	if( recv(sock , server_reply , 2000 , 0) < 0){
        puts("recv failed");
    }
}	
void LoggerTCP::printW(string const &mystr){
	char server_reply[2000];
    string output = "[ "+this->currentDateTime()+" ] " + "WARNING   : " + mystr;
	if (send(sock, (const char*)output.c_str(), strlen((const char*)output.c_str()), 0) < 0){
		puts("Send failed");
	}
	if( recv(sock , server_reply , 2000 , 0) < 0){
        puts("recv failed");
    }
}	
void LoggerTCP::printV(string const &mystr){
	char server_reply[2000];
    string output = "[ "+this->currentDateTime()+" ] " + "VERBOSITY : " + mystr;
	if (send(sock, (const char*)output.c_str(), strlen((const char*)output.c_str()), 0) < 0){
		puts("Send failed");
	}
	if( recv(sock , server_reply , 2000 , 0) < 0){
        puts("recv failed");
    }
}	
	
	

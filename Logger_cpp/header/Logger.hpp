#ifndef Bank_HPP
#define	Bank_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

/*Logger Class*/
class Logger{

public:
	virtual void printE(string const &);
	virtual void printW(string const &);
	virtual void printV(string const &);
	
	string currentDateTime();
};

/*LoggerConsol class*/
class LoggerConsol : Logger {
  public:
    void printE(string const &);
	void printW(string const &);
	void printV(string const &); 
};

/*LoggerFile class*/
class LoggerFile : Logger {
  private:
	string logfile_name;
  public:
	LoggerFile(string filename);
    void printE(string const &);
	void printW(string const &);
	void printV(string const &); 
};

//~ /*LoggerTCP class*/
class LoggerTCP : Logger {
  private:
	int sock;
	struct sockaddr_in server;
  public:
	LoggerTCP();
	void printE(string const &);
	void printW(string const &);
	void printV(string const &); 
};


#endif

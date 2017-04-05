#include <iostream>
#include <string>
#include <fstream>
#include "header/Bank.hpp"

using namespace std;

/*Logger Class*/
using namespace std;

class Logger{

public:
	//~ logger();
	virtual void printE(string const &);
	virtual void printW(string const &);
	virtual void printV(string const &);
};

void Logger::printE(string const &mystr){
	cout <<"ERROR :"<<mystr<<"\n";
}
void Logger::printW(string const &mystr){
	cout <<"WARNING :"<<mystr<<"\n";
}
void Logger::printV(string const &mystr){
	cout <<"VERBOSITY :"<<mystr<<"\n";
}

/*LoggerConsol class*/

class LoggerConsol : Logger {
  public:
    void printE(string const &);
	void printW(string const &);
	void printV(string const &); 
};

void LoggerConsol::printE(string const &mystr){
	cout <<"\033[1;31m"<<"ERROR :"<< mystr<<"\033[0m\n";	
}
void LoggerConsol::printW(string const &mystr){
	cout <<"\033[1;33m"<<"WARNING :"<< mystr<<"\033[0m\n";	
}
void LoggerConsol::printV(string const &mystr){
	cout <<"\033[1;35m"<<"VERBOSITY :"<< mystr<<"\033[0m\n";	
}

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

LoggerFile::LoggerFile(string filname){
	this->logfile_name = filname;
	ofstream fout(this->logfile_name.c_str());
}

void LoggerFile::printE(string const &mystr){
	std::ofstream outfile;
	outfile.open(this->logfile_name.c_str(), std::ios_base::app);
	outfile <<"ERROR :"<<mystr<<"\n";
}
void LoggerFile::printW(string const &mystr){
	std::ofstream outfile;
	outfile.open(this->logfile_name.c_str(), std::ios_base::app);
	outfile <<"WARNING :"<<mystr<<"\n";
}
void LoggerFile::printV(string const &mystr){
	std::ofstream outfile;
	outfile.open(this->logfile_name.c_str(), std::ios_base::app);
	outfile <<"VERBOSITY :"<<mystr<<"\n";	
}


int main(){
	LoggerFile lf("Logfile.log");
	Bank b;
	cout <<"compiling using Makefile\n";
	b.bprintE("hello from bank");
	lf.printE("jjdhf set of parameters");
	lf.printW("wrong set dfdof parameters");
	lf.printV("wrong set of parameters");
	return 0;
}

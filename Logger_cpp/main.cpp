#include <iostream>
#include <string>
#include <fstream>

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
	ofstream myfile;
  public:
	void create_file();
    void printE(string const &);
	void printW(string const &);
	void printV(string const &); 
};

void LoggerFile::create_file(){
	
	ofstream myfile("logfile.txt");
}

void LoggerFile::printE(string const &mystr){
	//~ if(this->logfil.is_open()){
	  //~ this->logfil<<"ERROR :"<< mystr;
	//~ }
}
void LoggerFile::printW(string const &mystr){
	cout <<"\033[1;33m"<<"WARNING :"<< mystr<<"\033[0m\n";	
}
void LoggerFile::printV(string const &mystr){
	cout <<"\033[1;35m"<<"VERBOSITY :"<< mystr<<"\033[0m\n";	
}


int main(){
	LoggerFile lc;
	lc.create_file();
	return 0;
}

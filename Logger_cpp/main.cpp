#include <iostream>
#include <string>

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



int main(){
	LoggerConsol Lc;
	l.printE("error message");	
	l.printW("warning message");
	l.printV("verbosity message");
	return 0;
}

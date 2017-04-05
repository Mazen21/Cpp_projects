#ifndef Bank_HPP
#define	Bank_HPP

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*Logger Class*/
class Logger{

public:
	virtual void printE(string const &);
	virtual void printW(string const &);
	virtual void printV(string const &);
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


#endif

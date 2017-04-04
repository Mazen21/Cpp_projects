//logger.hpp
#ifndef LOGGER_HPP
#define	LOGGER_HPP

#include <string>
#include <iostream>

using namespace std;

class Logger{

public:
	//~ logger();
	void printE(string const &);
	void printW(string const &);
	void printV(string const &);
};

#endif

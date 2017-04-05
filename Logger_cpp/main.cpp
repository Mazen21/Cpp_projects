#include <iostream>
#include <string>
#include <fstream>
#include "header/Logger.hpp"

using namespace std;

int main(){
	LoggerFile lf("Logfile.log");
	LoggerConsol lc;
	cout <<"compiling using Makefile\n";
	lf.printE("set of parameters");
	lc.printE("set of parameters");
	lf.printW("set dfdof parameters");
	lc.printW("set dfdof parameters");
	lf.printV("set of parameters");
	lc.printV("set of parameters");
	return 0;
}

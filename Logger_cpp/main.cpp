#include <iostream>
#include <string>
#include <fstream>
#include "header/Logger.hpp"

using namespace std;
 
int main(){
    LoggerFile Lf("Log_file.log");
	
    Lf.printE("big errors");
    Lf.printW("Warning");
    Lf.printV("verbosity");
}


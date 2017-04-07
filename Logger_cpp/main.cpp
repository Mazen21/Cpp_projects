#include <iostream>
#include <string>
#include <fstream>
#include "header/Logger.hpp"

using namespace std;
 
int main(){
    LoggerTCP Lt;
	
    Lt.printE("big errors");
    Lt.printW("Warning");
    Lt.printV("verbosity");
}


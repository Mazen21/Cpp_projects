

#include <iostream>
#include <string>
#include <fstream>
#include "header/Logger.hpp"

using namespace std;

typedef enum log_type {Console = 1,File,TCP} Log_type;

int main(){
    short choice;
    LoggerConsol lc;
    LoggerFile lf("log_file.log");
    LoggerTCP lt;
    cout <<"****************************************\n";
    cout <<"                  MENU                  \n";
    cout <<"****************************************\n";
    cout <<"1 : Log with console                    \n";
    cout <<"2 : Log with file                       \n";
    cout <<"3 : Log with TCP,  Run server before (use : gnome-terminal -e ./out/server)\n";
    
    cout <<"Enter Logging type : ";
    cin >> choice;
    switch(choice){
      case Console:
        cout <<"Printing log infos to Console\n";
        lc.printE("error message");
        lc.printW("warning message");
        lc.printV("verbosity message");
      break;
      case File:
        cout <<"Printing log infos to log_file.log\n";
        lf.printE("error message");
        lf.printW("warning message");
        lf.printV("verbosity message");
      break;
      case TCP:
        cout <<"Printing log infos to localhost\n";
        lt.printE("error message");
        lt.printW("warning message");
        lt.printV("verbosity message");
      break;
      default:
      cout <<"Wrong input";
    }
    return 1;
}


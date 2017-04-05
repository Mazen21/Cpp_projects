#include "../header/Logger.hpp"

/*Logger Class*/
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
void LoggerConsol::printE(string const &mystr){
	cout <<"\033[1;31m"<<"ERROR :"<< mystr<<"\033[0m\n";	
}
void LoggerConsol::printW(string const &mystr){
	cout <<"\033[1;33m"<<"WARNING :"<< mystr<<"\033[0m\n";	
}
void LoggerConsol::printV(string const &mystr){
	cout <<"\033[1;35m"<<"VERBOSITY :"<< mystr<<"\033[0m\n";	
}

LoggerFile::LoggerFile(string filname){
	this->logfile_name = filname;
	ofstream fout(this->logfile_name.c_str());
}

/*LoggerFile class*/
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

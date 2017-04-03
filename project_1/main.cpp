
#include <iostream>
using namespace std;

int main()
{
	string mystr;
	cout << "What's your name? ";
	getline (cin, mystr);
	cout << "what's your favorite team? ";
	getline (cin, mystr);
	cout << "I like " << mystr << " too! \n";
	
	return 1;
}

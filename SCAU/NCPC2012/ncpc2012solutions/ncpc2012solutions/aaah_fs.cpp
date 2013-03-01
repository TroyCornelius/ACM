// Sample solution for the Aaah! problem in NCPC 2012 by Fredrik Svensson.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string jon, doctor;
	cin >> jon >> doctor;
	if (jon.size() >= doctor.size())
		cout << "go" << endl;
	else
		cout << "no" << endl;
	return 0;
}

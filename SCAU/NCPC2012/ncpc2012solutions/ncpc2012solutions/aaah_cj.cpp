#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string aah_jm; cin >> aah_jm;
	string aah_doc; cin >> aah_doc;
	if (aah_jm.size() >= aah_doc.size())
		cout << "go" << endl;
	else
		cout << "no" << endl;
}

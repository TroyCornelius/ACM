#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[2000], s2[2000];
    cin >> s1 >> s2;
    cout << ((strlen(s1)<strlen(s2))?"no":"go") << endl;
}


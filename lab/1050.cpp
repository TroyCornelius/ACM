#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int main()
{
    cin >>s1;
    cin >>s2;
    int loc = s1.find(s2,0);
    cout <<loc+1 <<endl;
    return 0;
    }

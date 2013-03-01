#include <iostream>
#include <string>

using namespace std;

string s;
int main()
{
    cin >>s;
    int c4=0, c7 = 0;
    for (int i=0; i<s.length(); i++)
    if (s[i] == '4') c4++;
    else if (s[i] == '7') c7++;
    if (c4 == c7 && c4 == 0) cout <<-1 <<endl;
    else
    { 
    if (c4 >= c7) cout <<4 <<endl;
    else cout <<7 <<endl;
    }
    return 0;
    }

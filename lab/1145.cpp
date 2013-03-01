#include <iostream>
#include <string>
using namespace std;

string s;
int main()
{
    cin >>s;
    int head=0, tail=int(s.size())-1;
    while (head <= tail)
      {
         if (s[head] != s[tail]) {cout<<"N"<<endl;return 0;}   
         head++; tail--;
      }
    cout <<"Y" <<endl;
 
    return 0;
    }

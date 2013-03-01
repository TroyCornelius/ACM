#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

const int maxlen = 22;
int T, len, t;
string s;
int main()
{
    freopen("data.in", "w", stdout);
    srand(time(NULL));
    T = rand()%10 + 1;
    while (T--)
    {
          s.clear();
          len = rand() % maxlen + 1;
          while (len--)
          {
                t = rand()%26;
                s += 'a' + t;                
          }
          cout <<s <<endl;
    }
    cout <<"#"<<endl;
    return 0;
    }

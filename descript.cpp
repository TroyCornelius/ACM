#include <iostream>
#include <cstdio>
using namespace std;

string s;
unsigned int d[1000];
const unsigned int key = 127;
int conv(char t)
{
    if (t>='0' && t<='9') return t-'0';
    else return t-'a';
    }
int main()
{
    //cin >>s;
    for (int i=0; i<23; i++) scanf("%x", &d[i]);
    s = "3d11131b5e11105f5e301b081b0c5e1917081b5e0b0e5f";
    for (int i=0; i<23; i++)
    {
      //  d[i] = conv(s[i]) * 16 + conv(s[i+1]);
        printf("%c", d[i]^key);
    }
    
    system("pause");
    return 0;
    }
//3c 10 12 1a 5f 10 11 5e 5f 31 1a 9 1a d 5f 18 16 9 1a 5f a f 5e

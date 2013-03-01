#include <iostream>
using namespace std;

bool p[500];
int main()
{
    memset(p, true, sizeof(p));
    for (int i=2; i<=200; i++)
      for (int j=i+i; j<=200; j+=i)
        p[j] = false;
    for (int i=2; i<=200; i++)
      if (p[i]) cout <<i <<endl;

    return 0;
    }

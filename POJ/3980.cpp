#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a, b;
int main()
{
    while (scanf("%d%d", &a, &b) != EOF)
    {
       if (a < b) printf("%d\n", a);
       else printf("%d\n", a-a/b*b);
          
    }
    
    return 0;
    }

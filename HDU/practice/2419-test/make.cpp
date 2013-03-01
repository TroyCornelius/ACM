#include <iostream>
#include <cstime>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 20000;
const int maxq = 300000;
int n, m, q, T;
int main()
{
    srand(time(NULL));
    T = 3;
    while (T--)
    {
          n = rand()%maxn + 1;
          m = rand()%(n*(n-1)/2) + 1;
          q = rand()%maxq + 1;
          printf("%d %d %d\n", n, m, q);
          
    }
    return 0;
    }

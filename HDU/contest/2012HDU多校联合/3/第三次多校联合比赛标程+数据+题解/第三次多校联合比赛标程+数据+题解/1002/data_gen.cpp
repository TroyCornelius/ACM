#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <windows.h>
using namespace std;

#define INF 0x3fffffff
#define LL long long

int main()
{
    freopen("in.txt", "w", stdout);
    srand(GetTickCount());
    int i, t = 20;
    long long a, b, n;
    printf("%d\n", t);
    for(i = 1; i <= 10; i++)
    {
        a = rand() % 10000 + 1;
        b = rand() % 10000 + 1;
        n = rand() % 50000 + 1;
        printf("%I64d %I64d %I64d\n", a, b, n);
    }
    for(i = 1; i <= 5; i++)
    {
        a = rand() % 10000 + 1;
        b = rand() % 1000000 + 1000000;
        b = b * b;
        n = rand() % 10000 + 10000;
        n = n * n;
        printf("%I64d %I64d %I64d\n", a, b, n);
    }
    for(i = 1; i <= 5; i++)
    {
        a = rand() % 10000 + 1;
        b = rand() % 10000000 + 10000000;
        b = b * b;
        n = rand() % 100000 + 100000;
        n = n * n;
        printf("%I64d %I64d %I64d\n", a, b, n);
    }
    return 0;
}

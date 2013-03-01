#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argv, char **argc)
{
    freopen(argc[1], "w", stdout);
    int t = 2;
    printf("%d\n", t);
    while(t--)
    {
        int n = rand() % 6 + 1;
        printf("%d\n", n);
        while(n--)
        {
            int h = rand() % 30;
            int m = rand() % 60;
            printf("%d %d\n", h, m);
        }
    }
    return 0;
}


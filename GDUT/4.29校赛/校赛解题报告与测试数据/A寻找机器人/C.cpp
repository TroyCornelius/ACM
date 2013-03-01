#include <iostream>
#include <cstdio>
#include <time.h>
#include <cstdlib>

int main(int argc, char **argv)
{
    freopen(argv[1], "w", stdout);
    srand(time(0));
    int n = rand() % 99 + 1;
    int op = 0;
    printf("%d\n", n);
    while(n--)
    {
        op = rand() % 150;
        if(op >= 0 && op <= 50)
            op = -1;
        else
            op -= 50;
        printf("%d\n", op);
    }
}

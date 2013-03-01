#include <iostream>
#include <cstdio>

int main(int argc, char **argv)
{
    freopen(argv[1], "r", stdin);
    for(int i = 0; argv[1][i]; ++i)
    {
        if(argv[1][i] == '.')
        {
            argv[1][i + 1] = 'o';
            argv[1][i + 2] = 'u';
            argv[1][i + 3] = 't';
            argv[1][i + 4] = 0;
            break;
        }
    }
    freopen(argv[1], "w", stdout);

    int N;
    int s;
    int d = 1;
    int pos = 0;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &s);
        if(s > 0)
            pos += d * s;
        else
            d = -d;
    }
    printf("%d\n", pos);
    return 0;
}

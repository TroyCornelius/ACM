#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
/*
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
*/
    int t;
    int n, h, m;
    while(scanf("%d", &n) == 1)
    {
        int sh = 0, sm = 0;
        while(n--)
        {
            scanf("%d%d", &h, &m);
            sh += h;
            sm += m;
        }
        sh += sm / 60;
        sm %= 60;
        sh = sh % (22 - 8) + 8;
        printf("%02d:%02d\n", sh, sm);
    }
    return 0;
}



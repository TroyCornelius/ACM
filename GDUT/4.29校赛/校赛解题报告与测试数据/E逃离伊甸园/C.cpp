#include <cstdio>
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Coord
{
    int x, y, b;
};

const int MAX_SIZE = 100 + 1;
const int MAX = 50;
int Grid[MAX_SIZE][MAX_SIZE];
int Monster[MAX_SIZE][MAX_SIZE];
void print(int n, int m)
{
    printf("%d %d\n", n, m);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            printf("%d ", Grid[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int m, n;
    srand(time(0));
    //n = rand() % 100 + 1;
    //m = rand() % 100 + 1;
    printf("Input the n, m: ");
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            Grid[i][j] = (rand() % MAX) + 1;
        }
    }
    int nn = (rand() % (n * m)) + 1;
    int x, y;
    for(int i = 1; i <= nn; ++i)
    {
        x = rand() % n + 1;
        y = rand() % m + 1;
        if((x != 1 && y != 1) && (x != n && y != m))
            Grid[x][y] = - ((rand() % MAX) + 1);
    }
    print(n, m);
    vector<Coord> mvec;
    Coord tmp;
    int L;
    memset(Monster, 0, sizeof(Monster));
    printf("Input the Monster number: ");
    scanf("%d", &L);
    int K = (rand() % MAX);
    for(int i = 1; i <= L; ++i)
    {
        //printf("Input the Pos: ");
        //scanf("%d%d", &tmp.x, &tmp.y);
        tmp.x = rand() % n + 1;
        tmp.y = rand() % m + 1;
        tmp.b = rand() % MAX;

        if((tmp.x <= n && tmp.y <= m) && Grid[tmp.x][tmp.y] > 0 && Monster[tmp.x][tmp.x] == 0)
        {
            mvec.push_back(tmp);
            Monster[tmp.x][tmp.y] = 1;
        }
        else
        {
            //printf("exist wrong!\n");
            --i;
        }
    }

    char file[100];
    printf("Input the file name: ");
    scanf("%s", file);
    freopen(file, "w", stdout);
    printf("%d %d\n", n, m);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            printf("%d ", Grid[i][j]);
        }
        printf("%d\n", Grid[i][m]);
    }
    printf("%d %d\n", L, K);
    vector<Coord>::iterator ix = mvec.begin();
    while(ix != mvec.end())
    {
        printf("%d %d %d\n", ix->x, ix->y, ix->b);
        ++ix;
    }
    return 0;
}



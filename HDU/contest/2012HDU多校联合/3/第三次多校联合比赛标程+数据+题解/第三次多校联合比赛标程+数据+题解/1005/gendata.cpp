#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define SIZE 2000
char g[SIZE][SIZE];
int main()
{
    freopen("tmpdata.txt", "w", stdout);
    int n = 1000;
    memset(g, 0, sizeof(g));
    printf("%d\n", n);
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            g[i][j] = (rand() % 2);
    }
    for(int i = 0; i < n; i++)
        for(int j = i - 1; j >= 0; j--)
            if (g[j][i] == 0) g[i][j] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}

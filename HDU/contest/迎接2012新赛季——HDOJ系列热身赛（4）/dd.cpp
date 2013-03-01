#include <iostream>
#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
using namespace std;

int mat[110][110];
int D;
int gauss (int r, int c)
{
    int i, j, k, col;
    for(k = col = 0; k < r && col < c; k ++, col ++)
    {
        int kk = k;
        for (i = k + 1; i < r; i ++)
            if (mat[i][col] > mat[kk][col])
                kk = i;
        if (kk != k)
            for (j = col; j < c + 1; j ++)
                swap (mat[k][j], mat[kk][j]);
        if (mat[k][col] == 0)
        {
            k --;
            continue;
        }
        for (i = k + 1; i < r; i ++)
            if (mat[i][col])
                for (j = col; j < c + 1; j ++)
                    mat[i][j] ^= mat[k][j];
    }
    for (i = k; i < r; i ++)
        if (mat[i][col] != 0)
            return -1;
    int ans = 1;
    for (i = 0; i < c - k; i ++)
        ans *= 2;
    return ans ;
}

int main ()
{
    int T;
    int n;
    scanf ("%d", &T);
    while (T --)
    {
        int i, j;
        int cnt = 0;
        scanf ("%d%d", &n, &D);
        memset (mat, 0, sizeof (mat));
        for (i = 0; i < n; i ++)
            scanf ("%d", &mat[i][n]);
        for (i = 0; i < n; i ++)
        {
            int temp = 0;
           // scanf ("%d", &temp);
            mat[i][n] ^= temp;
        }
        for (int x = 0; x < n; x++)
        {
            for (int y = max(0, x-D); y<=min(n-1, x+D); y++)
            mat[y][x] = 1;
        }
        for (i = 0; i < n; i ++)
            mat[i][i] = 1;
        int ans = gauss (n, n);
        if (ans == -1)
            printf ("impossible\n");
        else
            printf ("%d\n", ans);
    }
    return 0;
}


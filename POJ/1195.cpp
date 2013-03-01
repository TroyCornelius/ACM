#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#define Maxn 1100
using namespace std;

int op, n;
int tree[Maxn][Maxn];
inline int lowbit(int x){return x&(-x);}
void insert(int x, int y, int val)
{
     for (int i=x; i<=n; i+=lowbit(i))
       for (int j=y; j<=n; j+=lowbit(j))
         tree[i][j] += val;
     }
int sum(int x, int y)
{
      int ret = 0;
     for (int i=x; i>0; i-=lowbit(i))
       for (int j=y; j>0; j-=lowbit(j))
         ret += tree[i][j];
     return ret;
     }
int main()
{
    int x, y, l, r, v;

    while (scanf("%d", &op))
    {
        if (op == 3) break;
        if (op == 0) {scanf("%d", &n);memset(tree, 0, sizeof(tree));}
        if (op == 1)
        {
            scanf("%d%d%d", &x, &y, &v);
            x++; y++;
            insert(x, y, v);               
        }
        else
        if (op == 2)
        {
            scanf("%d%d%d%d", &l, &r, &x, &y);
            x++; y++; l++; r++;
            printf("%d\n", sum(x, y)-sum(l-1, y)-sum(x, r-1)+sum(l-1, r-1));
        }          
    }
    
    
    return 0;
    }

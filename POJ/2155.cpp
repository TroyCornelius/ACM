#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define Maxn 1010
using namespace std;

int T, n, m;
int t[Maxn][Maxn];
inline int lowbit(int x) {return x&-x;}
void insert(int x, int y, int val)
{
     for (int i=x; i>0; i-=lowbit(i))
       for (int j=y; j>0; j-=lowbit(j))
         t[i][j] += val;
     }
int sum(int x, int y)
{
    int ret = 0;
    for (int i=x; i<=n; i+=lowbit(i))
      for (int j=y; j<=n; j+=lowbit(j))
        ret += t[i][j];
    return ret;
    }
int main()
{
    int x1, y1, x2, y2;
    scanf("%d", &T);
    for (;T>0;T--)
    {
       scanf("%d%d%*c", &n, &m);
       memset(t, 0, sizeof(t));
       char ch;
       for (int i=0; i<m; i++)
       {
          scanf("%c", &ch);
          if (ch == 'C') 
          {
             scanf("%d%d%d%d%*c",&x1, &y1, &x2, &y2);
             insert(x2, y2, 1); insert(x1-1, y1-1, 1);
             insert(x1-1, y2, -1); insert(x2, y1-1, -1);
          }
          else
          {
              scanf("%d%d%*c", &x1, &y1);
              printf("%d\n", sum(x1, y1)&1);          
          }           
       } 
       if (T>1) printf("\n");       
    }
    return 0;
    }

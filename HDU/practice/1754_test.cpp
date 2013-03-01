#include <iostream>
#include <cstdio>
#include <vector>
#define Maxn 200010
#define oo 999999999
using namespace std;

int n, m;
int t[Maxn], d[Maxn];

void insert(int idx, int val)
{
     while (idx<=n)
     {
        t[idx] = max(t[idx], val);
        idx += idx & -idx;           
     }
     }
int search(int idx)
{
    int ret = 0;
    while (idx > 0)
    {
       ret = max(ret, t[idx]);
       idx -= idx & -idx;
    }
    return ret;
    }
int query(int l, int r)
{
    return max(search(r), search(l-1));
    }
int gsum(int l, int r)
{
    int s = 0;
    while (true)
    {
       s += t[r];
       if (l == r) break;
       for (r-=1;r-l>=(r&-r); r-=r&-r) s+=t[r];          
    }
    return s;
    }
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
       memset(t, 0, sizeof(t));
       for (int i=1; i<=n; i++) 
       {
          scanf("%d", &d[i]);
          insert(i, d[i]);
       }
       int a, b; 
       char op;
       for (int i=0; i<m; i++)
       {
           getchar();
           scanf("%c %d %d", &op, &a, &b);
           if (op=='Q') printf("%d\n", query(a, b));
           else insert(a, b);
           cout <<"  :" <<gsum(a, b) <<endl;
       }      
          
    }  
    
    system("pause");
    return 0;
    }

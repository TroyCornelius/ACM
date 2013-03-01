#include <iostream>
#include <cstdio>
#include <vector>
#define Maxn 200010
using namespace std;

int n, m, t[Maxn];
int d[Maxn]; 
inline int lowbit(int x) {return x & (-x);}

void Modify(int idx, int val)
{
     d[idx] = val;
     while (idx<=n)
     {
        t[idx] = max(t[idx], val);
        idx += lowbit(idx);           
     }
     }
void init()
{
     for (int i=1; i<=n; i++)
     {
         t[i] = d[i];
         for (int j=1; j<lowbit(i); j<<=1) t[i] = max(t[i], t[i-j]);
     }
     }
int find(int l, int r)
{
    int big=d[r];
    while (true)
    {
        big = max(big, d[r]); 
        if (l == r) break;          
        for (r-=1; r-l>=lowbit(r); r-=lowbit(r)) big = max(big, t[r]);
    }
    return big;
    }
int main()
{
    while (scanf("%d%d", &n, &m)!=EOF){
    for (int i=1; i<=n; i++) scanf("%d", &d[i]);
    init();
    int a, b; 
    char c;
    for (int i=0; i<m; i++) 
    {
        getchar();
        scanf("%c %d %d", &c, &a, &b);
        if (c == 'Q') printf("%d\n", find(a, b));
        else Modify(a, b);
    }
    }
    return 0;
    }

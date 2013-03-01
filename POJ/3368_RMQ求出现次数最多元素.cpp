#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cmath>
#define Maxn 100030
using namespace std;

int k[Maxn+10], num[Maxn+10], id[Maxn*2+10];
int n, m, cnt[Maxn+10], tot;
int rmq[Maxn+10][25], st[Maxn+10];
void init()
{
     int tmp=2, id=0;
     for (int i=1; i<=n; i++)
     {
        if (i >= tmp) {tmp<<=1; id++;}
        k[i] = id;   
     }    
     }
void init_RMQ()
{
     for (int i=1; i<=tot; i++) rmq[i][0] = cnt[i];
     for (int i=1; (1<<i)<=tot; i++)
       for (int j=1; j+(1<<i)-1<=tot; j++)
         rmq[j][i] = max(rmq[j][i-1], rmq[j+(1<<(i-1))][i-1]);
     }
int find(int le, int ri)
{
    int idx1 = id[num[le]], idx2 = id[num[ri]];
    if (idx1 == idx2) return ri - le + 1;
    if (idx1 + 1 == idx2) return max(st[idx2]-le, ri-st[idx2]+1);    
    int ans = max(ri-st[idx2]+1, st[idx1+1]-le);    
    idx1++; idx2--; 
    int i = int(log(idx2-idx1+1.0) / log(2.0));
    ans = max(ans, max(rmq[idx1][i], rmq[idx2-(1<<i)+1][i]));
    return ans;  
    }
int main()
{
    init();
    while (~scanf("%d", &n) && n)
    {
       scanf("%d", &m);
       memset(cnt, 0, sizeof(cnt));
       tot = 0; num[0] = 0; st[0] = 0;
       for (int i=1; i<=n; i++) 
       {
           scanf("%d", &num[i]);
           num[i] += Maxn;
           if (num[i] != num[i-1])
           {
              id[num[i]] = ++tot;
              st[tot] = i;                      
           }
           cnt[tot]++;           
       }
       init_RMQ();
       int a, b;
       for (int i=0; i<m; i++)
       {
           scanf("%d%d", &a, &b);
           printf("%d\n", find(a, b));           
       }          
    }
    return 0;
    }

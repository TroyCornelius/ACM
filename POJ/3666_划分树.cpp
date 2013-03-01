#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define Maxn 100011
using namespace std;

struct Tnode
{
       int num, id;
       bool operator < (const Tnode &b) const
       {
            return num < b.num;
       }      
       }d[Maxn];
int n, stk[Maxn], len[Maxn], c[Maxn];
int t[20][Maxn], s[20][Maxn];
bool cmp(const Tnode &a, const Tnode &b)
{
     return a.num < b.num;
     }
void build(int h, int l, int r)
{
     if (l == r) return ;
     int mid = (l+r)>>1, p = 0;
     for (int i=l; i<=r; i++)
     {
         if (t[h][i] <= mid)
         {
            t[h+1][l+p] = t[h][i];
            s[h][i] = ++p;   
         }
         else
         {
             t[h+1][mid+1+i-l-p] = t[h][i];
             s[h][i] = p;             
         }   
     }
     build(h+1, l, mid);
     build(h+1, mid+1, r);
     }
int find(int h, int l, int r, int le, int ri, int k)
{
    if (le == ri) return t[h][le];
    int mid = (l+r)>>1;
    int ls=0, rs = s[h][ri];
    if (le > l) ls = s[h][le-1];
    if (rs - ls >= k) return find(h+1, l, mid, l+ls, l+rs-1, k);
    else return find(h+1, mid+1, r, mid+1+le-l-ls, mid+ri-l+1-rs, k-(rs-ls));    
    }

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &d[i].num);
        d[i].id = i; c[i] = d[i].num;
    }
    sort(d+1, d+n+1);
    for (int i=1; i<=n; i++) t[0][d[i].id] = i;
    build(0, 1, n);
    int top = 0;
    
    for (int i=1; i<=n; i++)
    {
        int now = c[i], clen = 1;
        while (top && stk[top-1] > now)
        {
            clen += len[top-1];
            now = d[find(0,1,n, i-clen+1, i, (clen+1)/2)].num;  
            top--;
        }
        len[top] = clen;
        stk[top++] = now;        
    }
    
    long long ans = 0;
    int idx = 1;
    for (int i=0; i<top; i++)
      for (;len[i]; len[i]--, idx++)
        ans += abs(stk[i]-c[idx]);
    cout <<ans <<endl;
    return 0;
    }

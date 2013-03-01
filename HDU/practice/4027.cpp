#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 1e-8
#define Maxn 100100
using namespace std;

int n, m;
long long d[Maxn];
struct Tnode
{
       int le, ri;
       long long sum;
       bool dead;
       };
struct segmenttree
{
       Tnode t[Maxn*3];
       void updata(int p)
       {
          t[p].sum = t[p<<1].sum + t[p<<1|1].sum;
          t[p].dead = t[p<<1].dead && t[p<<1|1].dead;              
       }
       void build(int p, int l, int r)
       {
            t[p].le = l; t[p].ri = r;
            if (l == r)
            {
                t[p].sum = d[l];
                if (d[l] <= 1) t[p].dead = true;
                else t[p].dead = false;
                return;
            }
            else
            {
                int mid = (l + r)>>1;
                build(p<<1, l, mid);
                build(p<<1|1, mid+1, r);   
                updata(p);           
            }            
       }
       void attack(int p, int left, int right)
       {
            if (t[p].dead) return;
            if (t[p].le == t[p].ri)
            {
                t[p].sum = (long long)(sqrt(double(t[p].sum))+eps);
                t[p].dead = (t[p].sum <= 1LL);
                return;
            }
            else
            {
                int mid = (t[p].le + t[p].ri)>>1;
                if (left <= mid) attack(p<<1, left, right);
                if (right > mid) attack(p<<1|1, left, right);
                updata(p);                
            }            
       }
       long long query(int p, int left, int right)
       {
            if (left<=t[p].le && t[p].ri <= right) return t[p].sum;
            int mid = (t[p].le + t[p].ri) >>1;
            long long ret = 0;
            if (left<=mid) ret += query(p<<1, left, right);
            if (right > mid) ret += query(p<<1|1, left, right);
            return ret;            
       }
       }tree;

int main()
{
    int ca = 0, op, a, b;
    while (scanf("%d", &n) != EOF)
    {
          printf("Case #%d:\n", ++ca);
          for (int i=1; i<=n; i++) scanf("%I64d", &d[i]);
          tree.build(1, 1, n);
          scanf("%d", &m);
          while (m--)
          {
              scanf("%d%d%d", &op, &a, &b);
              if (a>b) swap(a,b);
              if (op == 0) tree.attack(1, a, b);
              else printf("%I64d\n", tree.query(1, a, b));                
          }          
          printf("\n");
    }
    system("pause");
    return 0;
    }

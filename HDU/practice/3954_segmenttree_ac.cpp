#include <iostream>
#include <cstdio>
#include <cstring>
#define Maxn 10010
using namespace std;

int T, n, need[12], k;
struct Tnode
{
       int le, ri, add;
       int num[12];       
       };
struct segmenttree
{
       Tnode t[Maxn*5];
       void build(int p, int left, int right)
       {
            t[p].le = left; t[p].ri = right;
            t[p].add = 0;
            memset(t[p].num, -1, sizeof(t[p].num));
            t[p].num[1] = 0;
            if (left == right) return;
            int mid = (left + right) >>1;
            build(p<<1, left, mid);
            build(p<<1|1, mid+1, right);      
       }
       void updata(int p)
       {
            for (int i=1; i<=k; i++) t[p].num[i] = max(t[p<<1].num[i], t[p<<1|1].num[i]);   
       }
       void push_down(int p)
       {
            if (t[p].add)
            {
               t[p<<1].add += t[p].add;
               t[p<<1|1].add += t[p].add;
               for (int i=1; i<=k ;i++)
               {
                   if (t[p<<1].num[i] != -1) t[p<<1].num[i] += t[p].add * i;
                   if (t[p<<1|1].num[i] != -1) t[p<<1|1].num[i] += t[p].add * i;                   
               }
               t[p].add = 0;
            }            
       }
       void level_Up(int p, int lvl)
       {            
            if (t[p].le == t[p].ri)
            {
                while (lvl < k && t[p].num[lvl] >= need[lvl])
                {
                      t[p].num[lvl+1] = t[p].num[lvl];
                      t[p].num[lvl++] = -1;                      
                }  
                return ;    
            }
            push_down(p);
            if (t[p<<1].num[lvl] >= need[lvl]) level_Up(p<<1, lvl);
            if (t[p<<1|1].num[lvl] >= need[lvl]) level_Up(p<<1|1, lvl); 
            updata(p);
       }
       void insert(int p, int l, int r, int ei)
       {
            if (l <= t[p].le && t[p].ri <= r)
            {
               t[p].add += ei;
               for (int i=k; i>=1; i--)
               {
                   if (t[p].num[i] != -1) t[p].num[i] += ei * i;
                   if (i < k && t[p].num[i] >= need[i]) level_Up(p, i);  
               }
               return ;     
            }
            push_down(p);
            int mid = (t[p].le + t[p].ri) >>1;
            if (l <= mid) insert(p<<1, l, r, ei);
            if (mid < r) insert(p<<1|1, l, r, ei);    
            updata(p);        
       }
       int query(int p, int l, int r)
       {
           if (l <= t[p].le && t[p].ri <= r)
           {
                 for (int i=k; i>=1; i--)
                 if (t[p].num[i] != -1) return t[p].num[i];                          
           }
           push_down(p);
           int mid = (t[p].le + t[p].ri) >>1;
           int ret = 0;
           if (l <= mid) ret = max(ret, query(p<<1, l, r));
           if (mid < r) ret = max(ret, query(p<<1|1, l, r));
           return ret;     
       }       
       }tree;
int main()
{
   
    int ca=0, Q, a, b, c;
    char op[2];
    scanf("%d", &T);
    while (T--)
    {
          scanf("%d%d%d", &n, &k, &Q);
          for (int i=1; i<k; i++) scanf("%d", &need[i]);
          tree.build(1, 1, n);
          printf("Case %d:\n", ++ca);
          while (Q--)
          {
              scanf("%s", op);
           //   printf("%s\n", op);
              if (op[0] == 'W')
              {
                  scanf("%d%d%d", &a, &b, &c);
                  tree.insert(1, a, b, c);                        
              }  
              else
              {
                  scanf("%d%d", &a, &b);
                  printf("%d\n", tree.query(1, a, b));
              }                              
          }
          printf("\n");
    }
   
    return 0;
    }

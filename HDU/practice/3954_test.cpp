#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#define Maxn 10010
#define pb push_back
using namespace std;
typedef vector<int>::iterator vi;
int T, n, need[12], k;
struct Tnode
{
       int le, ri;
       vector<int> pp;
       int lvl, exp;    
       };
struct segmenttree
{
       Tnode t[Maxn*4];
       void build(int p, int left, int right)
       {
            t[p].le = left; t[p].ri = right;
          //  t[p].pp = 0; 
            t[p].pp.clear();
            t[p].lvl = 1; t[p].exp = 0;
            if (left == right) return;
            int mid = (left + right) >>1;
            build(p<<1, left, mid);
            build(p<<1|1, mid+1, right);      
       }
       void updata(int p)
       {
            //for (int i=1; i<=k; i++) t[p].num[i] = max(t[p<<1].num[i], t[p<<1|1].num[i]);   
            t[p].exp = max(t[p<<1].exp, t[p<<1|1].exp);
            t[p].lvl = max(t[p<<1].lvl, t[p<<1|1].lvl);
       }
       void push_down(int p)
       {
        //    while (!t[p].pp.empty())
            if (t[p].pp.size() > 0)
            {
              // cout <<tei <<endl <<endl;
              for (vi i = t[p].pp.begin(); i!=t[p].pp.end(); i++)
              {
                int tei = *i;
               if (t[p<<1].le != t[p<<1].ri) t[p<<1].pp.pb(*i);
               if (t[p<<1].le != t[p<<1].ri) t[p<<1|1].pp.pb(*i);
            /*   for (int i=1; i<=k ;i++)
               {
                   if (t[p<<1].num[i] != -1) t[p<<1].num[i] += t[p].pp * i;
                   if (t[p<<1|1].num[i] != -1) t[p<<1|1].num[i] += t[p].pp * i;                   
               }*/
               t[p<<1].exp += tei * t[p<<1].lvl;
               t[p<<1|1].exp += tei * t[p<<1|1].lvl;
               if (t[p<<1].lvl < k && t[p<<1].exp >= need[t[p<<1].lvl]) level_Up(p<<1);
               if (t[p<<1|1].lvl < k && t[p<<1|1].exp >= need[t[p<<1|1].lvl]) level_Up(p<<1|1); 
              // t[p].pp = 0;
              }
              t[p].pp.clear();
            }            
       }
       void level_Up(int p)
       {            
            if (t[p].le == t[p].ri)
            {
              /*  while (lvl < k && t[p].num[lvl] >= need[lvl])
                {
                      t[p].num[lvl+1] = t[p].num[lvl];
                      t[p].num[lvl++] = -1;                      
                }  */
                while (t[p].lvl < k && t[p].exp >= need[t[p].lvl]) t[p].lvl++;
                return ;    
            }
            push_down(p);
            if (t[p<<1].lvl < k && t[p<<1].exp >= need[t[p<<1].lvl]) level_Up(p<<1);
            if (t[p<<1|1].lvl < k && t[p<<1|1].exp >= need[t[p<<1|1].lvl]) level_Up(p<<1|1); 
            updata(p);
       }
       void insert(int p, int l, int r, int ei)
       {
            if (l <= t[p].le && t[p].ri <= r)
            {
               t[p].pp.pb(ei);
              /* for (int i=k; i>=1; i--)
               {
                   if (t[p].num[i] != -1) t[p].num[i] += ei * i;
                   if (i < k && t[p].num[i] >= need[i]) level_Up(p, i);  
               }*/
               t[p].exp += ei * t[p].lvl;
               if (t[p].lvl < k && t[p].exp >= need[t[p].lvl]) level_Up(p);
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
              /*   for (int i=k; i>=1; i--)
                 if (t[p].num[i] != -1
                 ) return t[p].num[i];  */
                 return t[p].exp;                        
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
  //  freopen("d.in", "r", stdin);
  //  freopen("test.out", "w", stdout);
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
    system("pause");
    return 0;
    }

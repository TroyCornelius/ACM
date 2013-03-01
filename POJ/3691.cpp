#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define kind 4
#define inf 999999999
#define Maxn 1010
#define Maxnode 1010
using namespace std;

int encode(char ch)
{
    switch (ch)
    {
       case 'A':return 0;
       case 'C':return 1;
       case 'G':return 2;
       case 'T':return 3;           
    }
    }
class AC_machine
{
private:
      int dp[Maxn][Maxnode], tr[Maxnode][kind];  
      struct Tnode
      {
         Tnode *fail, *next[kind];
         int cnt;             
      }memory[Maxnode], *pp, *root, *q[Maxnode];
      int head, tail;
      Tnode *newnode()
      {
         pp -> fail = NULL;
         pp -> cnt = 0;
         memset(pp->next, 0, sizeof(pp->next));
         return pp++;            
      }
      void make_tr(int m)
      {
           memset(tr, -1, sizeof(tr));
           for (int i=0; i<m; i++)
           {
               if (memory[i].cnt) continue;
               for (int j=0; j<kind; j++) 
               {
                   Tnode *p = memory + i;
                   while (p)
                   {
                      if (p->next[j])
                      {
                          p = p->next[j];
                          break;
                      }
                      p = p->fail;                         
                   }
                   if (!p)
                   {
                      p = root;
                      if (p->next[j]) p = p->next[j];      
                   }
                   if (p->cnt == 0) tr[i][j] = p - memory;
               }               
           }
      }

public :
       void init()
       {
           pp = memory;
           root = newnode();            
       }
       void insert(char *s)
       {
            Tnode *now = root;
            while (*s)
            {
                int id = encode(*s);  
                if (!now->next[id]) now->next[id] = newnode();
                now = now->next[id];    
                s++;              
            }
            now->cnt++;
       }
       void build_ac()
       {
           head = tail = 0;
           q[tail++] = root;
           while (head != tail)
           {
                 Tnode *tmp = q[head++], *p;
                 for (int i=0; i<kind; i++)
                 if (tmp->next[i])
                 {
                      if (tmp == root) tmp->next[i]->fail = root;
                      else
                      {
                          p = tmp->fail;
                          while (p)
                          {
                            if (!p->next[i]) 
                            {
                               p = p->fail;
                               continue;
                            }
                            tmp->next[i]->fail = p->next[i];
                            if (p->next[i]->cnt > 0) tmp->next[i]->cnt++;   //if the node's fail is dangerous, so it is
                            break;                                
                          }
                          if (!p) tmp->next[i]->fail = root;
                      }
                      q[tail++] = tmp->next[i];
                 }                 
           }    
       }
       int DP(int n, char *s)
       {
           int m = pp - memory;
           make_tr(m);
           for (int i=0; i<=n; i++) fill(dp[i], dp[i]+m, inf);
           dp[0][0] = 0;
           for (int i=0; i<n; i++)
             for (int j=0; j<m; j++)
             {
                 if (dp[i][j]==inf || memory[j].cnt) continue;
                 for (int k=0; k<kind; k++)
                 {
                     if (tr[j][k] != -1)
                     {
                        dp[i+1][tr[j][k]] = min(dp[i+1][tr[j][k]], dp[i][j] + (encode(s[i])!=k));                                  
                     }
                     
                 }
                 
             }
           int ans = inf;
           for (int i=0; i<m; i++) ans = min(ans, dp[n][i]);
           if (ans == inf) return -1;
           else return ans;          
       }      
      }AC;
char str[Maxn];
int main()
{
    int T = 1, n;
    while (~scanf("%d", &n) && n)
    {
        AC.init();
        for (int i=0; i<n; i++)
        {
            scanf("%s", str);
            AC.insert(str);            
        }
        scanf("%s", str);
        AC.build_ac();
        printf("Case %d: %d\n", T++, AC.DP(strlen(str), str));          
    }
    
    return 0;
    }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#define Maxn 1000000
using namespace std;

struct Tnode
{
       int flag; 
       Tnode *next[26], *fail;
       };
Tnode *t, memory[Maxn];
int T, n, m;
char word[55], text[Maxn];
void creat(Tnode *&p)
{
     p = &memory[m++];
     for (int i=0; i<26; i++) p->next[i] = NULL;
     p->flag=0;     
     }
void insert(Tnode *p, char *s)
{
     while (*s)
     {
        int k = *s++ - 'a';
        if (!p->next[k]) creat(p->next[k]);
        p = p->next[k];           
     }
     p->flag++;     
     }
void bulid_ac(Tnode *root)
{
     queue<Tnode*> q;
     q.push(root);
     Tnode *tmp, *p;
     root->fail = NULL;
     while (!q.empty())
     {
         tmp = q.front();
         q.pop();
         for (int i=0; i<26; i++)
         if (tmp->next[i]){
         if (tmp == root) tmp->next[i]->fail = root;
         else
         {
             p = tmp->fail;
             while (p)
             {
                if (p->next[i])
                {
                   tmp->next[i]->fail = p->next[i];
                   break;                               
                }
                p = p->fail;
             }
             if (!p) tmp->next[i]->fail = root;                          
         }
         q.push(tmp->next[i]);
         }     
     }    
     }
int query(Tnode *root, char *s)
{
    int cnt = 0;
    Tnode *tmp = root, *p;
    while (*s)
    {
       int k = *s++ - 'a';
       while (!tmp->next[k] && tmp != root) tmp = tmp->fail;
       tmp = tmp->next[k];
       if (!tmp) tmp = root;
       p = tmp;
       while (p != root)
       {
          cnt += p->flag;
          p->flag = 0;
          p = p->fail;            
       }          
    }
    return cnt;    
    }
int main()
{
    ios::sync_with_stdio(false);
    cin >>T;
    for (;T>0;T--)
    {
        cin >>n;
        m = 0;
        creat(t);
        for (int i=0; i<n; i++)
        {
            cin >>word;
            insert(t, word);            
        }
        bulid_ac(t);
        cin >>text;
        cout <<query(t, text) <<endl;
    }
    return 0;
    }

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>
using namespace std;

class Treap
{
public:
       struct Tnode
       {
         int key, fix, pro;
         Tnode *le, *ri;   
         Tnode (int a, int b)
         {
            key = a; pro = b;
            fix = rand();
            le = ri = NULL;
         }
       }*root;
       void init(){root=NULL;}
       void Rmove(Tnode *&p)
       {
            Tnode *tmp = p->le;
            p->le = tmp->ri;
            tmp->ri = p;
            p = tmp;            
       }
       void Lmove(Tnode *&p)
       {
            Tnode *tmp = p->ri;
            p->ri = tmp->le;
            tmp->le = p;
            p = tmp;            
       }
       void insert(Tnode *&r, int id, int pp)
       {
            if (!r)
            {
               r = new Tnode(id, pp);
               return ;                   
            }
            else
            {
                if (pp < r->pro)
                {
                   insert(r->le, id, pp);
                   if (r->le->fix > r->fix) Rmove(r);      
                }
                else
                {
                   insert(r->ri, id, pp);
                   if (r->ri->fix > r->fix) Lmove(r);                    
                }     
            }            
       }
       void del(Tnode *&r)
       {
            if (!r->le && !r->ri) 
            {
               delete r;
               r = NULL;                       
            }
            else
            if (!r->le)
            {
               Tnode *tmp = r;
               r = r->ri;
               delete tmp;                       
            }
            else
            if (!r->ri)
            {
               Tnode *tmp = r;
               r = r->le;
               delete tmp;                       
            }
            else
            {
                if (r->le->fix < r->ri->fix)
                {
                   Rmove(r);
                   del(r->ri);                               
                }
                else
                {
                    Lmove(r);
                    del(r->le);                    
                }                
            }            
       }
       int ask_lowest(Tnode *&r)
       {
           if (!r) return 0;
           else
           {
               if (r->le) return ask_lowest(r->le);
               else
               {
                   int ret = r->key;
                   del(r);
                   return ret;                   
               }               
           }                  
       }
       int ask_highest(Tnode *&r)
       {
           if (!r) return 0;
           else
           {
               if (r->ri) return ask_highest(r->ri);
               else
               {
                   int ret = r->key;
                   del(r);
                   return ret;                   
               }               
           }       
       }           
       }tree;
int main()
{
    int op, k, p;
    srand(12345);
    tree.init();
    while (~scanf("%d", &op) && op)
    {
          if (op == 1)
          {
             scanf("%d%d", &k, &p);
             tree.insert(tree.root, k, p);      
          }
          else
          if (op == 2) printf("%d\n", tree.ask_highest(tree.root));      
          else printf("%d\n", tree.ask_lowest(tree.root));          
    }
    return 0;
    }

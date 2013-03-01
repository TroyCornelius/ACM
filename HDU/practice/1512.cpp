#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define Maxn 100100
using namespace std;
const int inf = 0x7fffffff;
struct Tnode
{
       int key, dist;
       Tnode *lc, *rc;
       Tnode (int x)
       :key(x),dist(0),lc(NULL),rc(NULL){}
       };
class leftist
{
private:
        int tot;
        Tnode *root;
        inline int Get_dis(Tnode *x){return x==NULL?-1:x->dist;}
        inline Tnode* Merge(Tnode *a, Tnode *b)
        {
           if (!a) return b;
           if (!b) return a;
           if (a->key < b->key) swap(a, b);
           a->rc = Merge(a->rc, b);
           if (Get_dis(a->lc) < Get_dis(a->rc)) swap(a->lc, a->rc);
           a->dist = Get_dis(a->rc) + 1;
           return a;           
        }
public:
       inline void clr() {root=NULL;}
       inline void insert(int x) {root = Merge(root, new Tnode(x));}
       inline Tnode* groot(){return root;}
       inline int top() {return root==NULL?-inf:root->key;}
       inline void pop()
       {
           Tnode *tmp = root;
           root = Merge(root->lc, root->rc);
           delete tmp;              
       }
       inline void merge(leftist &t)
       {
           root = Merge(root, t.groot());
           //t.clr();              
       }      
      };
leftist tree[Maxn];
int n, m;
int fa[Maxn];
int find(int a)
{
    if (fa[a] == a) return a;
    else return fa[a] = find(fa[a]);    
}
int main()
{
    int a, b, num, ans;
    while (scanf("%d", &n) != EOF)
    {
        for (int i=1; i<=n; i++) {fa[i] = i;tree[i].clr();}
        for (int i=1; i<=n; i++)
        {
           scanf("%d", &num);
           tree[i].insert(num);          
        }
        scanf("%d", &m);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            int ta = find(a);
            int tb = find(b);
            if (ta == tb) printf("-1\n");
            else
            {
                num = tree[ta].top(); tree[ta].pop();tree[ta].insert(num>>1); 
                num = tree[tb].top(); tree[tb].pop();tree[tb].insert(num>>1);
                tree[tb].merge(tree[ta]);
                fa[ta] = tb;
                printf("%d\n", tree[tb].top());                
            }
        }
    }
    return 0;
    }

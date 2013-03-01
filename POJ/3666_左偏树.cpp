/*
左偏树，一个可合并堆.能够从堆中取出最大的元素,然后将两个堆在log n时间内合并.左偏树
为一种可合并堆.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstdlib>
#define Maxn 2500
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
        inline int Get_dis(Tnode *x) {return x==NULL?-1:x->dist;}
        inline Tnode* Merge(Tnode *a, Tnode *b)
        {
            if (!a) return b;
            if (!b) return a;
            if (a->key < b->key) swap(a, b);  // 若求最小堆为 ">" 
            a->rc = Merge(a->rc, b);
            if (Get_dis(a->rc) > Get_dis(a->lc)) swap(a->lc, a->rc); //斜堆只需删掉if 
            a->dist = Get_dis(a->rc) + 1; 
            return a;               
        }
public:
        inline int Size() {return tot;}
        inline bool empty() {return tot==0;}
        inline void clr() {root=NULL;tot=0;}
        inline Tnode* groot(){return root;}
        inline void insert(int x){root = Merge(root, new Tnode(x));tot++;}
        inline int top() {return root!=NULL?root->key:-inf;}
        inline void pop()
        {
            Tnode *tmp = root;
            root = Merge(root->lc, root->rc);
            delete tmp; tot--;
        }
        inline void merge(leftist &t)
        {
            tot += t.Size();
            root = Merge(root, t.groot());
            t.clr();           
        }      
};
int n, d[Maxn], len[Maxn];
leftist stk[Maxn];
int main()
{
    int hi=0;
    scanf("%d", &n);
    for (int i=0; i<=n; i++) stk[i].clr();
    for (int i=0; i<n; i++)
    {
        scanf("%d", &d[i]);
        leftist now;
        now.clr(); now.insert(d[i]);
        int ct = 1;
        while (hi>0 && stk[hi-1].top() > now.top())
        {
            now.merge(stk[--hi]);
            if ((len[hi]+1)/2 + (ct+1)/2 > (len[hi]+ct+1) / 2) now.pop(); 
            ct += len[hi];
        }
        len[hi] = ct;
        stk[hi++] = now;      
        //cout <<hi<<" "<<len[hi-1]<<" "<<stk[hi-1].top()<<" "<<d[i]<<" "<<endl;
    }
    long long ans = 0;
    int idx = 0;
    for (int i=0; i<hi; i++)
    {
      int num = stk[i].top(); //cout <<num <<"   " <<len[i] <<endl;
      for (;len[i]; len[i]--, idx++)
        ans += abs(d[idx] - num);
    }
    cout <<ans <<endl;  // system("pause");
    return 0;
    }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;

int n, k;
struct Tnode
{
    Tnode *le, *ri;
    int val;
}*t;

void insert(Tnode *&r, int v)
{
    if (!r)
    {
        r = new Tnode;
        r->val = v;
        r->le = r->ri = NULL;
    }
    else
        if (v < r->val) insert(r->le, v);
        else insert(r->ri, v);
}
void dfs(Tnode *r)
{
    if (!r) return;
    if(k) printf(" ");
    printf("%d", r->val);
    k = 1;
    dfs(r->le);
    dfs(r->ri);
}
int main()
{
    int num;
    while (~scanf("%d", &n))
    {
        t = NULL;
        REP(i, n)
        {
            scanf("%d", &num);
            insert(t, num);
        }
        k=0;
        dfs(t);
        printf("\n");
    }
    

    return 0;
}

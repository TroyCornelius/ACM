#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

#include <time.h>
#include <cctype>
#include <functional>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
struct node {
    ll key;
    int fix, sum, rep;
    node *lf, *rg;
} *r;
void update(node *&r) {
    if (!r)return;
    r->sum = r->rep;
    if (r->lf)r->sum += r->lf->sum;
    if (r->rg)r->sum += r->rg->sum;
    return;
}
void rotrg(node *&r) {//右旋，提高左儿子 
    node *tmp = r->lf;
    r->lf = tmp->rg;
    tmp->rg = r;
    update(r);
    r = tmp;
    update(r);
    return;
}
void rotlf(node *&r) {//左旋，提高右儿子 
    node *tmp = r->rg;
    r->rg = tmp->lf;
    tmp->lf = r;
    update(r);
    r = tmp;
    update(r);
    return;
}
void insert(ll num, node *&r) {//插入节点 
    if (!r) {//当前树为空，建立新节点 
        r = new node;
        r->lf = r->rg = NULL;
        r->key = num;
        r->sum = 0;
        r->rep = 1;
        r->fix = rand();//随机分配优先级 
    } else if (r->key == num)r->rep++;//本身键值已经存在 
    else {
        if (num < r->key) {
            insert(num, r->lf);
            if (r->lf->fix > r->fix)rotrg(r);//插入后，左儿子的 优先级比父亲结点的大，则进行右旋 
        } else {
            insert(num, r->rg);
            if (r->rg->fix < r->fix)rotlf(r);//插入后，右儿子的 优先级比父亲结点的大，则进行左旋 
        }
    }
    update(r);//更新treap树的数据域 
    return;
}
bool dfs(ll num, node *&r)
{
    if (!r) return false;
    if (r->key == num) return true;
    else
    {
        if (num < r->key) return dfs(num, r->lf);
        else return dfs(num, r->rg);
    }
}
void del(ll num, node *&r)   //删除数值为num的节点
 {
    if (!r)return;
    if (num < r->key)del(num, r->lf);
    else if (num > r->key)del(num, r->rg);
    else {
        if (r->rep > 1)r->rep--;
        else if (r->lf == NULL && r->rg == NULL) {//左右儿子均为空 
            delete r;
            r = NULL;
        } else if (r->lf == NULL) {//左儿子为空 
            node *tmp = r;
            r = r->rg;
            delete tmp;
        } else if (r->rg == NULL) {//右儿子为空 
            node * tmp = r;
            r = r->lf;
            delete tmp;
        } else {//具有左右儿子 
            if (r->lf->fix < r->rg->fix) {//左儿子的优先级比右儿子的小 
                rotlf(r);//将右儿子提高，作为新的根 
                del(num, r->lf);//递归删除左子树 
            } else {
                rotrg(r);
                del(num, r->rg);
            }
        }
    }
    update(r);
    return;
}
ll getKth(int k, node *&r)    //查询树中第K小元素
{
    if (k <= 0 || k > r->sum || !r)return 0;
    int tmp = 0;
    if (r->lf)tmp = r->lf->sum;
    if (k > tmp + r->rep)return getKth(k - tmp - r->rep, r->rg);
    else if (k <= tmp)return getKth(k, r->lf);
    else return r->key;
}

int n, k;
int main()
{
    char op[3];
    int x, cnt;
    while (~sf("%d%d", &n, &k))
    {
        r = NULL;
        cnt = 0;
        while (n--)
        {
            sf("%s", op);
            if(op[0] == 'I')
            {
                sf("%d", &x);
                insert(x, r);
                cnt++;
            }
            else
            {
                pf("%d\n", getKth(cnt-k+1, r));
            }
        }
        
    }
    return 0;
}

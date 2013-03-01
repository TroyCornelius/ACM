/*
 * Author:  Troy
 * Created Time:  2012/6/24 12:02:44
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
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
}
void rotrg(node *&r) {//右旋，提高左儿子 
    node *tmp = r->lf;
    r->lf = tmp->rg;
    tmp->rg = r;
    update(r);
    r = tmp;
    update(r);
}
void rotlf(node *&r) {//左旋，提高右儿子 
    node *tmp = r->rg;
    r->rg = tmp->lf;
    tmp->lf = r;
    update(r);
    r = tmp;
    update(r);
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
}
ll getKth(int k, node *&r)    //查询树中第K小元素
{
    if (!k || k > r->sum || !r)return 0;
    int tmp = 0;
    if (r->lf)tmp = r->lf->sum;
    if (k > tmp + r->rep)return getKth(k - tmp - r->rep, r->rg);
    else if (k <= tmp)return getKth(k, r->lf);
    else return r->key;
}

multiset<ll> d;
multiset<ll>::iterator mid;

void print(int tot)
{
    if (tot == 0) pf("Empty!\n");//cout <<"Empty!" <<endl;
    else
    {
        if (tot % 2 == 0)
        {
            multiset<ll>::iterator it1 = mid;//+ (tot/2);
            //REP(i, tot/2) it1++;
            //multiset<ll>::iterator it2 = d.begin() + (tot/2 - 1);
            //REP(i, tot/2-1) it2++;
            
            ll t1 = *it1;//getKth(tot/2, r);
            ll t2 = *(--it1);//getKth(tot/2 + 1, r);
            long long s = t1 + t2;
            if (s % 2 == 0) pf("%lld\n", s/2);
            else pf("%lld.5\n", s/2);
        }
        else
        {
            //multiset<ll>::iterator it1 = d.begin() ;//+ (tot/2);
            //REP(i, tot/2) it1++;
            //ll tt = *(d + 3);
            ll t = *mid;//getKth((tot+1)/2, r);
            pf("%lld\n", t);
        }
    }
}
int n;
int main() 
{
    //srand(time(NULL));
    //ios::sync_with_stdio(false);
    int T, cnt;
    ll x;
    char op[10];
    //string op;
    sf("%d", &T);
    //cin >>T;
    while (T--)
    {
        sf("%d", &n);
        //r = NULL;
        d.clear();
        cnt = 0;
        mid = d.begin();
        //cin >>n;
        while (n--)
        {
            sf("%s", op);
            sf("%lld", &x);
            //cin >>op;
            //cin >>x;
            //if (op == "remove")
            if (op[0] == 'r')
            {
                multiset<ll>::iterator it = d.find(x);
                if (it == d.end()) pf("Wrong!\n");//cout <<"Wrong!" <<endl;
                else
                {
                    cnt--;
                    //del(x, r);
                    d.erase(it);
                    //if (*mid >= x) mid--;
                    //else mid++;
                    mid--;
                    print(cnt);
                }
            }
            else
            {
                //insert(x, r);
                d.insert(x);
                if (*mid <= x) mid++;
                else mid--;
                    
                cnt++;
                print(cnt);
            }
        }
    }
    
    return 0;
}



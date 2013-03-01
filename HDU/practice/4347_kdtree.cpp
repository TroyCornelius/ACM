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
#define Maxn 50050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int Max = 6; //×î´óÎ¬Êý

struct Tnode
{
    int x[Max], div;
};
Tnode p[Maxn];
int n, k;

int cmpNo; //the cmp dimensions
int cmp(Tnode a, Tnode b)
{
    return a.x[cmpNo] < b.x[cmpNo];
}
void buildKD(int s, int e, Tnode *p, int d)
{
    if (s > e) return;
    int mid = (s+e) >>1;
    cmpNo = d;
    nth_element(p+s, p+mid, p+e+1, cmp);
    p[mid].div = d;
    buildKD(s, mid-1, p, (d+1)%k);
    buildKD(mid+1, e, p, (d+1)%k);
}

struct Qnode
{
    Tnode point;
    long long r;
    Qnode(){}
    Qnode(Tnode _point, long long _r)
    :point(_point), r(_r){}
    bool operator<(const Qnode &b) const
    {
        return r < b.r;
    }
};
long long calc_dis(Tnode &a, Tnode &b)
{
    long long ret = 0;
    REP(i, k)
        ret += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]);
    return ret;
}

priority_queue<Qnode> que;
Tnode ans[15];
void findKD(int s, int e, Tnode tar, Tnode *p, int cnt)
{
    if (s > e) return;
    int mid = (s+e)>>1;
    long long tr = calc_dis(p[mid], tar);
    if (que.size() < cnt) que.push(Qnode(p[mid], tr));
    else if (que.top().r > tr)
    {
        que.pop();
        que.push(Qnode(p[mid], tr));
    }
    
    int tmp = tar.x[p[mid].div] - p[mid].x[p[mid].div];
    if (tmp <= 0)
    {
        findKD(s, mid-1, tar, p, cnt);
        if (que.top().r > tmp*tmp) findKD(mid+1, e, tar, p, cnt);
    }
    else
    {
        findKD(mid+1, e, tar, p, cnt);
        if (que.top().r > tmp * tmp) findKD(s, mid-1, tar, p, cnt);
    }
}


int main() 
{
    int m, a, b, tot;
    Tnode q;
    while (~sf("%d%d", &n, &k))
    {
        REP(i, n)
            REP(j, k)
            sf("%d", &p[i].x[j]);
        
        buildKD(0, n-1, p, k-1);
        sf("%d", &m);
        
        while (m--)
        {
            while (!que.empty()) que.pop();
            REP(i, k) sf("%d", &q.x[i]);
            sf("%d", &tot);
            
            findKD(0, n-1, q, p, tot);
            REP(i, tot)
            {
                ans[i] = que.top().point;
                que.pop();
            }
            pf("the closest %d points are:\n", tot);
            FORD(i, tot-1, 0)
            {
                REP(j, k)
                    pf("%d%c", ans[i].x[j], j == k-1 ? '\n' :' ');
            }
        }
    }
    return 0;
}


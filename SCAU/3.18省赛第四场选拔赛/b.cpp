/*
 * Author:  Troy
 * Created Time:  2012/3/18 15:02:23
 * File Name: c.cpp
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
#include <cctype>
#include <functional>
#include <ctime>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define inf 1LL<<50
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int lim = 3000000;
typedef pair<long long,int> pii;
typedef vector<long long> vi;
typedef vector<int>::iterator vit;

int n;
long long ans, cnt;
long long s1[40], s2[40];
vi neg, d;
int sn, sd, st;
inline long long ABS(long long x)
{
    return x > 0 ? x : -x;
}
void dfs(int p1, int p2, pii t)
{
    if (t.se > 0)
    {
        if (ABS(t.fi) < ans)
        {
            ans = ABS(t.fi);
            cnt = t.se;
        }
        else
        if (ABS(t.fi) == ans && t.se < cnt)
        {
            ans = ABS(t.fi);
            cnt = t.se;
        }
    }
    if (p1 >= sn && p2 >= sd) return;
    if (ans == 0) return ;
  //  st++;
   // if (st > lim) return;
   // if (clock() - st > 0.8 * CLOCKS_PER_SEC) return;
    if (t.fi < 0 && p2 < sd)
    {
        long long tmp = s2[sd] - s2[p2] + t.fi;
        if (tmp < 0 && ABS(tmp) > ans) return;
        else
        if (tmp < 0 && ABS(tmp) < ans)
        {
            
        }
    }
    if (t.se > 0 && p1 < sn)
    {
        long long tmp = s1[sn] - s1[p1] + t.fi;
        if (tmp > 0 && tmp > ans) return;
    }
    if (p1 < sn)
    {
        dfs(p1 + 1, p2, mp(t.fi+neg[p1], t.se+1));
        dfs(p1+1, p2, t);
    }
    if (p2 < sd)
    {
        dfs(p1, p2+1, mp(t.fi+d[p2], t.se+1));
        dfs(p1, p2+1, t);
    }
    
}
int main() 
{
    srand(12345);
    long long x;
    ios::sync_with_stdio(false);
    while (cin >>n)
    {
        if (!n) break;
        st = clock();
        ans = inf; cnt = 100;
        neg.clear();
        d.clear();
        REP(i, n)
        {
            cin >>x;
            if (x > 0) d.pb(x);
            else 
            if (x < 0) neg.pb(x);
            if (ABS(x) < ans)
            {
                ans = ABS(x);
                cnt = 1;
            }
        }
        if (ans == 0)
        {
            cout <<ans <<" "<<1<<endl;
            continue;
        }
        else
        {
            sort(all(neg));
            sort(all(d));
            if (d.size() == 0)
            {
                cout <<ABS(neg[0]) <<" "<<1 <<endl;
                continue;
            }
            else
            if (neg.size() == 0)
            {
                cout <<ABS(d[0]) <<" "<<1 <<endl;
            }
            else
            {
                random_shuffle(all(neg));
                random_shuffle(all(d));
                s1[0] = 0; s2[0] = 0;
                FOR(i, 1, neg.size()) s1[i+1] = s1[i] + neg[i];
                FOR(i, 1, d.size()) s2[i+1] = s2[i] + d[i];
                sn = neg.size(); sd = d.size();
                dfs(0, 0, mp(0, 0));                               
                cout <<ans <<" "<<cnt <<endl;
            }
        }
    }
    return 0;
}


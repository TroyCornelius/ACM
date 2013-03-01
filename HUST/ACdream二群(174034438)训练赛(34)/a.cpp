/*
 * Author:  Troy
 * Created Time:  2012/5/25 19:05:32
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
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef pair<int,string> pis;
int n, m;
map<string,int> rid;
int dis[110], dist[110], earti, sc, tc;
struct Edge
{
    int u, v, st, et;
    Edge(int _u, int _v, int _st, int _et)
    :u(_u),v(_v), st(_st), et(_et){}
};
vector<Edge> g[110], ng[110];
string scity, ecity;
int spfa()
{
    REP(i, n) dis[i] = inf;
    dis[sc] = earti;
    bool hash[110];
    memset(hash, false, sizeof(hash));
    queue<int> que;
    que.push(sc);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        hash[now] = false;
        REP(i, g[now].size())
        {
            int v = g[now][i].v, st = g[now][i].st, et = g[now][i].et;
            //cout <<now <<" "<<v <<" "<<st <<" "<<et <<endl;
            if (st < dis[now]) continue;
            if (et < dis[v])
            {
                dis[v] = et;
                if (!hash[v])
                {
                    hash[v] = true;
                    que.push(v);
                }
            }
        }
    }
    //REP(i, n) cout <<dis[i] <<" ";
    //cout <<endl;
    if (dis[tc] == inf) return -1;
    while (!que.empty()) que.pop();
    memset(hash, false, sizeof(hash));
    memset(dist, 0, sizeof(dist));
    dist[tc] = dis[tc];
    que.push(tc);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        hash[now] = false;
        
        REP(i, ng[now].size())
        {
            int u = ng[now][i].u, st = ng[now][i].st, et = ng[now][i].et;
            //cout <<now <<" "<<u <<" "<<st <<" "<<et <<" "<<dist[now] <<endl;
            if (et > dist[now]) continue;
    //REP(p, n) cout <<dist[p] <<" ";
    //cout <<endl;
            if (st > dist[u])
            {
                dist[u] = st;
                if (!hash[u])
                {
                    hash[u] = true;
                    que.push(u);
                }
            }
        }
    }
    //REP(i, n) cout <<dist[i] <<" ";
    //cout <<endl;
    return dist[sc];
}
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0, tot;
    string s;
    cin >>T;
    while (T--)
    {
        rid.clear();
        tot = 0;
        cin >>n;
        REP(i, n)
        {
            cin >>s;
            rid[s] = tot++;
            g[i].clear();
            ng[i].clear();
        }
        cin >>m;
        int q;
        int ti;
        vector<pis> tmp;
        REP(i, m)
        {
            cin >>q;
            tmp.clear();
            while (q--)
            {
                cin >>ti >>s;
                tmp.pb(pis(ti, s));
            }
            sort(all(tmp));
            REP(j, tmp.size()-1)
            {
                //cout <<i <<" "<<rid[tmp[j]<F4>
                g[rid[tmp[j].se]].pb(Edge(rid[tmp[j].se], rid[tmp[j+1].se], tmp[j].fi, tmp[j+1].fi));
                ng[rid[tmp[j+1].se]].pb(Edge(rid[tmp[j].se], rid[tmp[j+1].se], tmp[j].fi, tmp[j+1].fi));
            }
        }
        cin >>earti;
        cin >>scity; sc = rid[scity];
        cin >>ecity; tc = rid[ecity];
        int ans = spfa();
        cout <<"Scenario " <<++ca <<endl;
        if (ans < 0) cout <<"No connection" <<endl;
        else
        {
            cout <<"Departure "<<setw(4)<<setfill('0') <<ans <<" "<<scity <<endl;
            cout <<"Arrival   "<<setw(4)<<setfill('0') <<dis[tc] <<" "<<ecity<<endl;
        }
        cout <<endl;


    }
    return 0;
}


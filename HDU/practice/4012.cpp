#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <cstring>
#define Maxn 1<<18
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
typedef pair<int,int> pii;
int n, ans;
string maz;
bool vis[Maxn];
int bfs()
{
    int aim = (1 << (n+n)) - 1;
    queue<pii> q;
    q.push(mp(0, 0));
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    
    while (!q.empty())
    {
        pii now = q.front();
        q.pop();
        int st = now.fi, step = now.se;
        REP(i, n+n)
        {
           int tmp = st; 
           if (st & (1<<i)) continue;
           FOR(j, i, (i/n+1)*n)
           {
               if (st & (1<<j)) break;
               if (maz[i] == maz[j]) tmp |= (1<<j);           
           }
           for(int j=i-1; j>=(i/n)*n; j--)
           {
               if (st & (1<<j)) break;
               if (maz[i] == maz[j]) tmp |= (1<<j);           
           }
           if (!vis[tmp])
           {
               vis[tmp] = true;
               if (tmp == aim) return step+1;
               q.push(mp(tmp, step+1));
           }
           
           if (i < n)
           {
               if (st & (1<<(i+n))) continue;
               tmp = st;
               FOR(j, i, n)
               {
                   if ((st&(1<<j)) | (st&(1<<(j+1)))) break;
                   if (maz[i] == maz[j]) tmp |= (1<<j);
                   if (maz[i] == maz[j+n]) tmp |= (1<<(j+n));               
               }
               for (int j=i-1; j>=0; j--)
               {
                   if (st&(1<<j) | (st&(1<<(j+n)))) break;
                   if (maz[i] == maz[j]) tmp |= (1<<j);
                   if (maz[i] == maz[j+n]) tmp |= (1<<(j+n));               
               }
               if (!vis[tmp])
               {
                   vis[tmp] = true;
                   if (tmp == aim) return step + 1;
                   q.push(mp(tmp, step+1));               
               }              
           }
        }
    }
    return -1;
}

int main()
{
    string s;
    int T;
    cin >>T;
    while (T--)
    {
        cin >>n;
        cin >>maz;
        cin >>s;
        maz += s;
        cout <<maz <<endl;
        ans = bfs();
        cout <<ans <<endl;
    }

    return 0;
}

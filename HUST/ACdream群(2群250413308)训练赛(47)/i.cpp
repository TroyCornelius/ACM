#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <numeric>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>
#define pb push_back
#define mp make_pair
#define inf 999999999
#define Maxn 10100
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, less<int> > PQ;

int n, m;
struct Tnode
{
    int sou, des;
    int st, et;
}d[Maxn];
multiset<pii> vis;
int main()
{
    int a, b, s, t, ans;
    while (~scanf("%d%d", &n, &m) && m)
    {
        for (int i=0; i<n; i++)
        {
            scanf("%d%d%d%d", &d[i].sou, &d[i].des, &d[i].st, &d[i].et);
            d[i].et = d[i].st + d[i].et - 1;
           
        }
        for (int i=0; i<m; i++)
        {
            ans = 0;
            vis.clear();
            scanf("%d%d", &s, &t);
            t = s + t - 1;

            for (int j=0; j<n; j++)
            {
                if ((s >= d[j].st && s <= d[j].et) || (t >= d[j].st && t <= d[j].et) || (d[j].st>=s && d[j].et<=t) )
                {
                    if (vis.find(mp(d[j].sou, d[j].des)) == vis.end())
                    {
                        ans++;
                        vis.insert(mp(d[j].sou, d[j].des));
                    }
                }

            }
            printf("%d\n", ans);
        }       

    }
    return 0;
}


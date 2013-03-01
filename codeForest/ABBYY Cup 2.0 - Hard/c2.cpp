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
#define Maxn 200010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int h, m, n; 
long long ans;
map<int,int> id;
int pat[Maxn], tot;
set<int> tree[Maxn];
int ord[Maxn];
vi rec[Maxn];
int main() 
{
        //freopen("c.in", "r", stdin);
    //freopen("cc.out", "w", stdout);
    ios::sync_with_stdio(false);
    char op;
    int x, y;
    
    cin >>h >>m >>n;
    ans = 0;
    tot = 0;
    memset(pat, -1, sizeof(pat));
    memset(ord, 0, sizeof(ord));
    
    REP(i, h)
        if (pat[i] == -1)
        {
            for (int j = i, t = 0; pat[j] == -1; j = (j + m)%h, t++) 
            {
                pat[j] = tot;
                ord[j] = t;
                rec[tot].pb(j);
                tree[tot].insert(t);
            }
            tot++;
        }
    
    while (n--)
    {
        cin >>op;
        if (op == '+')
        {
            cin >>x >>y;            
            set<int>::iterator it = tree[pat[y]].lower_bound(ord[y]);
            if (it == tree[pat[y]].end()) it = tree[pat[y]].begin();            
            int tmp = (*it);
            //cout <<tmp <<" "<<ord[y] <<endl;
            //cout <<rec[pat[y]][tmp] <<" "<<y <<endl;
            //cout <<"------------" <<endl;
            if (ord[y] <= tmp) ans += (tmp - ord[y]) ;
            else
            {
                int st = rec[pat[y]].size();
                ans += st - ord[y] + tmp ;
            } 
            id[x] = rec[pat[y]][tmp];
            tree[pat[y]].erase(it);
            //cout <<ans <<" "<<rec[pat[y]][tmp] <<endl;
        }
        else
        {
            cin >>x;
            int tmp = id[x];
            tree[pat[tmp]].insert(ord[tmp]);
        }
    }
    cout <<ans <<endl;
    return 0;
}


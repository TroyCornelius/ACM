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
#define Maxn 1510
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, ans;
char g[Maxn][Maxn];
int f[Maxn][Maxn], c[Maxn][Maxn][2];


void work(char ch)
{
    FOR(i, 1, m+1)
    {
        f[1][i] = (g[1][i] == ch?1:0);
        FOR(j, 2, n+1)
            f[j][i] = (g[j][i] == ch ? (f[j-1][i] + 1) : 0);
    }
    
    FOR(i, 1, m+1) cout <<f[7][i] <<" ";
    cout <<endl;
    
    int le = 1, ri = 1, mi;
    int que[Maxn*4], head = 0, tail = 0;
    FOR(i, 1, n+1)
    {
        mi = f[i][1];
        ans = max(ans, 2 + 2 * (g[i][1] == ch ? f[i][1] : 0));
        le = ri = 1;
        head = tail = 0;
        if (g[i][1] == ch) {que[tail] = 1;++tail;}
        else le = ri = 2;
        FOR(j, 2, m+1)
        {
            if (f[i][j] == 0)
            {
                while (le < ri)
                {
                    le++;
                    while (head < tail && que[head] < le) head++;
                    mi = f[i][que[head]];
                    ans = max(ans, 2 * (ri - le + 1) + 2 * mi);
                }
                le = ri = j + 1;
                while (head < tail) tail--;
            }
            else
            {
                while (head < tail && f[i][que[tail-1]] > f[i][j]) tail--;
                que[tail] = j;
                tail++;
                mi = f[i][que[head]];
                ri = j;
                ans = max(ans, (ri - le + 1) * 2 + mi * 2);                
            }
        }
        if (i == 7)
        cout <<le <<" "<<ri <<endl;
                while (le < ri)
                {
                    le++;
                    while (head < tail && que[head] < le) head++;
                    mi = f[i][que[head]];
                    ans = max(ans, 2 * (ri - le + 1) + 2 * mi);
                }
    }
}
void calc()
{
    // 0 for R, 1 for B
    FOR(j, 1, m+1)
    {
        c[1][j][0] = (g[1][j] == 'R' ? 1 : 0);
        c[1][j][1] = (g[1][j] == 'B' ? 1 : 0);
        
        FOR(i, 2, n+1)
        {
            if (g[i][j] == 'R')
            {
                c[i][j][1] = 0;
                c[i][j][0] = c[i-1][j][1] + 1;
            }
            else if (g[i][j] == 'B')
            {
                c[i][j][1] = c[i-1][j][0] + 1;
                c[i][j][0] = 0;
            }
        }
    }
    //cout <<c[3][4][0] <<" "<<c[3][5][1] <<" "<<c[3][6][0] <<" "<<c[3][3][1] <<endl;
    
    int le, ri, mi;
    int que[Maxn*4], head, tail;
    
    FOR(i, 1, n+1)
    {
        mi = c[i][1][g[i][1] == 'R'?0:1];
        le = ri = 1;
        ans = max(ans, 4 * (min(ri-le+1, mi)));
        head = tail = 0;
        que[tail++] = 1;
        
        FOR(j, 2, m+1)
        {
            if (g[i][j] == g[i][j-1])
            {
                while (le < ri)
                {
                    le++;
                    while (head < tail && que[head] < le) head++;
                    mi = c[i][j][g[i][que[head]] == 'R'? 0 : 1];
                    ans = max(ans, 4 * (min(ri-le+1, mi)));
                    //if (i == 3) cout <<le <<" "<<ri <<" "<<mi <<endl;
                }
                le = ri = j;
                while (head < tail) tail--;
                que[tail] = j;
                tail++;
            }
            else
            {
                while (head < tail && c[i][que[tail-1]][g[i][que[tail-1]] == 'R' ? 0 : 1] > c[i][j][g[i][j]=='R'?0:1]) tail--;
                que[tail] = j;
                tail++;
                mi = c[i][que[head]][g[i][que[head]] == 'R' ? 0 : 1];
                ri = j;
                ans = max(ans, 4 * min((ri - le + 1), mi));
            }
        }
    }
}
int main() 
{
    //freopen("a.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    int T, cas = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &n, &m);
        FOR(i, 1, n+1)
            sf("%s", g[i]+1);
        ans = 4;
        work('R');
        //cout <<ans <<endl;
        work('B');
        //cout <<ans <<endl;
        calc();
        pf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}


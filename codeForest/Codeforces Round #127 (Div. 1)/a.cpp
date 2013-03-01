/*
 * Author:  Troy
 * Created Time:  2012/6/29 23:33:57
 * File Name: a.cpp
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
/*
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
//int x;
int ans[110];
int a[20][20];

bool check(int x, int y, int n)
{
    if (a[x][y] == 1) return false;
    REP(i, 4)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && a[tx][ty] == 1) return false;
    }
    return true;    
}


void dfs(int tot, int n)
{
    if (tot > 100) return;
    if (ans[tot] == -1 || ans[tot] > n) ans[tot] = n;
    FOR(i, 1, n+1)
        FOR(j, 1, n+1)
        if (check(i, j, n))
        {
            int tmp = 1, x, y;
            a[i][j] = 1;
            x = n - i + 1; y = j;
            if (x != i) a[x][y] = 1, tmp++;
            x = i; y = n - j + 1;
            if (y != j) a[x][y] = 1, tmp++;
            x = n - i + 1, y = n - j + 1;
            if (x != i && y!= j) a[x][y]++, tmp++;
            dfs(tot + tmp, n);
            a[i][j] = a[n-i+1][j] = a[i][n-j+1] = a[n-i+1][n-j+1] = 0;           
                                    
        }
}
void calc(int xx)
{
    memset(ans, -1, sizeof(ans));
    int cnt = 0;
    memset(a, 0, sizeof(a));
    dfs(0, xx);

}*/
int main() 
{
    int x, ans = 1;
    cin >>x;
    if (x == 3) cout <<5 <<endl;
    else
    {
        for (ans=1;;ans += 2)
            if ((ans*ans+1)/2 >= x) break;
        cout <<ans <<endl;
    }
    
    return 0;
}


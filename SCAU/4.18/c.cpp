/*
 * Author:  Troy
 * Created Time:  2012/4/19 0:27:01
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

int a1, b1, c1, d1;
double dp[18][18][18][18][4];
int check(int a, int b, int x, int y)
{
    int tot = 0;
    if (a+1>=a1 && b>=b1 && x>=c1 && y>=d1) tot++;
    if (a>=a1 && b+1>=b1 && x>=c1 && y>=d1) tot++;
    if (a>=a1 && b>=b1 && x+1>=c1 && y>=d1) tot++;
    if (a>=a1 && b>=b1 && x>=c1 && y+1>=d1) tot++;
    return tot;
}
bool check2(int a, int b, int x, int y)
{
    int arr[4], tot = 0;
    arr[0] = a, arr[1] = b, arr[2] = x, arr[3] = y;
    REP(i, 4)
        FOR(j, i, 4)
        {
            arr[i]++; arr[j]++;
            if (arr[0]>=a1 && arr[1]>=b1 && arr[2]>=c1 && arr[3]>=d1) tot++;
            arr[i]--; arr[j]--;
        }
    return tot;
}
double dfs(int a, int b, int x, int y, int z)
{
    double &ret = dp[a][b][x][y][z];
    if (ret != -1.0) return  ret;
    if (a+b+x+y > z + 52) ret = 0.0;
    else
    if (z == 0 && a >= a1 && b >= b1 && x >= c1 && y >= d1)
    {
        int sum = a + b + x + y;
        ret = (double)sum;
        return ret;
    }
    //else
    ret = 0.0;
    if (z == 1 && check(a,b,x,y) > 0)
    {
        ret = (double)(a+b+x+y+z) ;//* (double)check(a, b, x, y);
        //cout <<check(a, b,x,y) <<"--" <<a << " "<<b <<" "<<x <<" "<<y <<" " <<endl;
    }
    else
    if (z == 2 && check2(a, b, x, y) > 0)
    {
        ret = (double)(a+b+x+y+z) ; //* (double)check2(a, b, x, y);
        //cout <<check2(a, b,x,y) <<"----" <<a << " "<<b <<" "<<x <<" "<<y <<" " <<endl;
    }
    else
    {
        int sum = a + b + x + y + z;
        double tmp = 1e100;
        if (a+1 <= 13+z)
        {
            ret += dfs(a+1, b, x, y, z) * 1.0 * (13+z - a) / (double)(54 - sum);
            if (z + 1 <= 2) tmp = min(tmp, dfs(a+1, b, x, y, z+1) * 1.0 * (2 - z) / (54 - sum));
        }
        if (b+1 <= 13+z)
        {
            ret += dfs(a, b+1, x, y, z) * 1.0 * (13+z - b) / (double)(54 - sum);
            if (z + 1 <= 2) tmp = min(tmp, dfs(a, b+1, x, y, z+1) * 1.0 * (2 - z) / (54 - sum));
        }
        if (x+1 <= 13+z)
        {
            ret += dfs(a, b, x+1, y, z) * 1.0 * (13+z - x) / (double)(54 - sum);
            if (z + 1 <= 2) tmp = min(tmp, dfs(a, b, x+1, y, z+1) * 1.0 * (2 - z) / (54 - sum));
        }
        if (y+1 <= 13+z)
        {
            ret += dfs(a, b, x, y+1, z) * 1.0 * (13+z - y) / (double)(54 - sum);
            if (z + 1 <= 2) tmp = min(tmp, dfs(a, b, x, y+1, z+1) * 1.0 * (2 - z) / (54 - sum));
        }
        //if (z + 1 <= 2) ret += dfs(a, b, x, y, z+1) * 1.0 * (2-z)/(54 - sum);
        if (tmp != 1e100) ret += tmp;
    }
    //cout <<a <<" "<<b <<" "<<x <<" " <<y << " "<<z <<" "<<ret <<endl;
    return ret;
}
int main() 
{
    //freopen("c.out", "w", stdout);
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d%d%d", &a1, &b1, &c1, &d1);
        REP(i, 17)
            REP(j, 17)
            REP(x, 17)
            REP(y, 17)
            REP(t, 3) dp[i][j][x][y][t] = -1.0;
        double ans = dfs(0,0,0,0,0);
        pf("%.3f\n", ans);
        
    }
    return 0;
}


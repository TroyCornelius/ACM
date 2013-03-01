/*
 * Author:  Troy
 * Created Time:  2012/2/23 19:20:33
 * File Name: 
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
#define Maxn 55
#define Maxm 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


struct Tnode
{
    int d, g;
    double wi;
    Tnode() {}
    Tnode(int _d, int _g, double _wi)
    :d(_d), g(_g), wi(_wi){}
    bool operator<(const Tnode &b) const
    {
        return d < b.d;
    }
}witch[Maxn];

int n, m;
double dp[Maxn][Maxm];
double dfs(int k, int hp)
{
    double &ret = dp[k][hp];
    if (ret != -1.0) return ret;
    if (k == n || hp - (witch[k+1].d - witch[k].d) <= 0)
    {
        ret = (double)(hp + witch[k].d);        
    }
    else
    {
        double s1 = dfs(k+1, hp - (witch[k+1].d - witch[k].d));
        int tmp = min(m, hp - (witch[k+1].d - witch[k].d) + witch[k+1].g);
        double s2 = witch[k+1].wi * dfs(k+1, tmp) + (1.0 - witch[k+1].wi) * witch[k+1].d;
        ret = max(s1, s2);
    }
    return ret;
}
class MagicalGirl
{
    public:
    double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain)
    {
        n = day.size();
        m = M;
        REP(i, n) witch[i+1] = Tnode(day[i], gain[i], 1.0*win[i]/100.0);
        witch[0] = Tnode(0, 0, 0.0);
        sort(witch+1, witch+n+1);
        REP(i, n+1)
            REP(j, M+1)
              dp[i][j] = -1.0;
        double ans = dfs(0, M);
        return ans;
    }
};

int main() 
{
    return 0;
}


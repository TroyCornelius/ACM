/*
 * Author:  Troy
 * Created Time:  2012/5/4 23:30:04
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
const long long mod = 1000000007;
typedef long long ll;
const int maxn = 5;
const int n = 2;
const ll m = 1000000007LL;

struct Mat 
{
    ll val[maxn][maxn];
    void unit() 
    {        
        zero();
        for(int i = 0; i < maxn; i++) val[i][i] = 1;
    }
    void zero()
    {
        memset(val, 0, sizeof(val));
    }
};
Mat operator *(const Mat &a, const Mat &b) 
{ 
    Mat tmp;
    tmp.zero();
    for(int k = 1; k <= n; k++) 
    {
        for(int i = 1; i <= n; i++)
            if(a.val[i][k])
                for(int j = 1; j <= n; j++) 
                {
                    tmp.val[i][j] += a.val[i][k] * b.val[k][j];
                    if(tmp.val[i][j] >= m) tmp.val[i][j] %= m;
                }
    }
    return tmp;
}

Mat operator ^(Mat x, ll n)
{    
    Mat tmp;
    tmp.unit();
    while(n)
    {
        if(n & 1) tmp = tmp * x;
        x = x * x;
        n >>= 1;
    }
    return tmp;
}

int main() 
{
    ll k;
    Mat A, B;
    A.zero(), B.zero();
    A.val[1][1] = 3;
    A.val[1][2] = 4;
    B.val[1][1] = 2, B.val[2][1] = 1, B.val[2][2] = 4;

    cin >>k;
    if (k == 0)
    {
        cout <<1 <<endl;
        return 0;
    }
    else
    {
        k--;
        Mat tmp = B ^ k;
        Mat ans = A * tmp;
        cout << ans.val[1][1] << endl;
    }
    return 0;
}


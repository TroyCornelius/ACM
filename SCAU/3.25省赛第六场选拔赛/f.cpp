/*
 * Author:  Troy
 * Created Time:  2012/3/25 14:57:48
 * File Name: f.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const long long lim = 2000000000;
const int max_len = 31;
int s, t;
vi d;
/*void dfs(int num, int val, int now)
{
    if (1LL * num * 2 > lim) return;
    if (val + now < 0) return;
    d.pb(num);
    dfs((num<<1|1), val-1, now-1);
    dfs(num<<1, val+1, now-1);
}*/
long long f[33][2][64];
void init()
{
    memset(f, 0, sizeof(f));
    f[0][0][max_len+1] = f[0][1][max_len-1] = 1;
    FOR(i, 1, max_len+1)
    {
        REP(j, max_len+max_len+1)
            REP(t, 2)
            if (f[i-1][t][j] != 0)
            {
                f[i][0][j+1] += f[i-1][t][j];
                f[i][1][j-1] += f[i-1][t][j];            
            }
    }
    cout <<f[1][0][max_len+2]<<endl;
}
long long getid(int num)
{
    int ph = 0, tot = max_len;
    while ((1LL<<ph) <= num)
    {
        if ((1<<ph)&num) tot--;
        else tot++;
        ph++;        
    }
   // cout <<ph <<" "<<tot <<endl;
    ph--;
    long long ret = f[ph][1][tot], tmp;
    tot++;
    cout <<ret <<" "<<tot <<endl;
    FORD(i, ph-1, 0)
    {
        if ((1<<i)&num)
        {
            tmp = f[i][0][tot];
            tot++;
        }
        else
        {
            tmp = f[i][1][tot];
            tot--;
        }
        ret -= tmp;        
        cout <<ret <<" "<<tmp <<" "<<tot <<endl;
    }
    return tmp;
}
int main() 
{
    init();
    cout <<getid(12) <<endl;
    while (cin >>s >>t)
    {
        
        
    }
    return 0;
}


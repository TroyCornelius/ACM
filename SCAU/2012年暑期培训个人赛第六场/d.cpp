/*
 * Author:  Troy
 * Created Time:  2012/7/28 14:25:07
 * File Name: d.cpp
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
const int Maxn = 1024*10;
const int mm = (1<<16)-1;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int a[20];
long long cnt[(1<<16) + 10];
vector<int> st[Maxn+100];
bool check(int num)
{
    int tot = 0;
    while (num)
    {
        num -= num&-num;
        tot++;
    }
    return tot == 4;
}
int main() 
{
    int ca = 0;
    while (cin >>a[0], a[0])
    {
        FOR(i, 1, 16) cin >>a[i];
        REP(i, Maxn+1) st[i].clear();
        FOR(i, 1, 1<<16)
        {
            if (check(i))
            {
                int sum = 0, p[5];
                for (int t = 0, j = 0; j<16; j++)
                    if ((1<<j)&i) p[t++] = j;
                do
                {
                    sum = 4 * a[p[0]] + 3 * a[p[1]] + 2 * a[p[2]] + a[p[3]];                    
                    st[sum].pb(i);
                }while (next_permutation(p, p+4));
            }
        }
        memset(cnt, 0, sizeof(cnt));
        FOR(i, 10, Maxn+1)
        {
            if (st[i].size() == 0) continue;
            REP(j, st[i].size()-1)
                FOR(k, j+1, st[i].size())
                {
                    if ((st[i][j] & st[i][k]) == 0)
                    {
                        cnt[st[i][j] | st[i][k]]++;
                    }
                }
        }
        long long ans = 0;
        FOR(i, 1, 1<<16)
            ans += cnt[i] * cnt[i ^ mm];
        cout <<"Case " <<++ca <<": " <<ans/2 <<endl;
        
    }
    
    return 0;
}


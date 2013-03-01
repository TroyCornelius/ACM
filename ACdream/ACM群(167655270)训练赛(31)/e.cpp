/*
 * Author:  Troy
 * Created Time:  2012/5/4 21:10:24
 * File Name: e.cpp
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
const int lim = 1000001;
int cnt[lim+10];
int ans[lim];
void init()
{
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            cnt[j]++;
    }
    FOR(i, 1, lim)
        if (ans[cnt[i]] == 0) ans[cnt[i]] = i;    
}
int main() 
{
    int T, n;
    init();
    cin >>T;
    while (T--)
    {
        cin >>n;
        if (n > lim || ans[n] == 0) cout <<"Too big" <<endl;
        else cout <<ans[n] <<endl;
    }
    return 0;
}

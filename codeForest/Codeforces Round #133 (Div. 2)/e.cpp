/*
 * Author:  Troy
 * Created Time:  2012/8/15 1:06:25
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int k, b, n;
map<int,int> cnt;
int main() 
{
    int x;
    ios::sync_with_stdio(false);
    cin >>k >>b >>n;
    int tot = 0, c0 = 0;
    long long ans = 0;
    cnt[0]++;
    k--;
    REP(i, n)
    {
        cin >>x;
        if (!x) c0++;
        else c0 = 0;
        tot += x;
        tot %= k;
        if (b == 0) ans += c0;
        else
        {
            int tmp = (tot + k - b) % k;
            ans += cnt[tmp];
            if (b == k) ans -= c0;
        }
        cnt[tot]++;
    }
    cout <<ans <<endl;
    return 0;
}


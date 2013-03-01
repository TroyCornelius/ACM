/*
 * Author:  Troy
 * Created Time:  2012/3/10 0:15:03
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
string s;
int n;
long long cnt[2048], sum[2048]; //cnt is ) sum is (
void calc(int x, int y)
{
    while (x >= 0 && y < n && s[x] == s[y])
    {
        cnt[y]++; sum[x]++;
        x--; y++;
    }
}
int main() 
{
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    cin >>s;
    n = s.length();
    REP(i, n)
    {
        calc(i, i);
        if (i+1 < n) calc(i, i+1);
    }
    FOR(i, 1, n) sum[i] += sum[i-1];
    long long ans = 0;
    REP(i, n-1)
    {
        ans += cnt[i] * (sum[n-1] - sum[i]);
    }
    cout <<ans <<endl;
    return 0;
}


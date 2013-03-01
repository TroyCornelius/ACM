/*
 * Author:  Troy
 * Created Time:  2012/2/17 15:20:53
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
#define Maxn 1100000
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

string s1, s;
int ans, z[Maxn], t;
void zfunction()
{
    int len = s.length();
    REP(i, len) z[i] = 0;
    for (int i=1, l=0, r=0; i<len; ++i)
    {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < len && s[z[i]] == s[i+z[i]]) ++z[i];
        if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }
    ans = 0;
    //FOR(i, t+1, len) cout <<z[i] <<" ";
    //cout <<endl;
    FOR(i, t+1, len)
        if (z[i] == t) ans++;
    cout <<ans <<endl;
    //cout <<s1 <<" "<<s <<endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>s;
        t = s.length();
        cin >>s1;
        s = s + '#' + s1;
        zfunction();        
    }
    return 0;
}


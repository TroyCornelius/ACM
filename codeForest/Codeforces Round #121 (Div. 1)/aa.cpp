/*
 * Author:  Troy
 * Created Time:  2012/5/28 0:13:59
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, cnt[50], cnt2[50], ans;
string s;

int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    ans = 0;
    REP(i, n)
    {
        cin >>s;
        if (s[0] == s[s.size()-1]) ans = max(ans, (int)s.length());
        char ch = s[s.size()-1]-'a';
        if (cnt[ch] > 0) ans = max(ans, cnt[ch] + (int)s.length()+cnt2[ch]);
        //if (s.length() > cnt[s[0]-'a']) cnt[s[0]-'a'] = s.length();
        cnt[s[0]-'a'] += s.length();
        cnt2[ch] += s.length();
    }
    cout <<ans <<endl;
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/3/1 20:38:51
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
string s, t;
int main() 
{
    cin >>s;
    cin >>t;
    s = string(2010, '#') + s + string(2010, '@');
    int ans = maxint;
    int len1 = s.length(), len2 = t.length();
    for (int i = 0; i + len2 <= len1; i++)
    {
        int cnt = 0;
        REP(j, len2)
             cnt += (s[i+j] != t[j]);
        ans = min(ans, cnt);
    }
    cout <<ans <<endl;
    return 0;
}


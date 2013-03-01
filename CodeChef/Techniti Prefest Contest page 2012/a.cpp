/*
 * Author:  Troy
 * Created Time:  2012/2/27 20:15:49
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
#define Maxn 20100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, ans[Maxn];
map<string, int> cnt;
string s;
int main() 
{
    ios::sync_with_stdio(false);
    while (cin >>n >>m)
    {
        if (!n && !m) break;
        cnt.clear();
        REP(i, n)
        {
            cin >>s;
            cnt[s]++;
        }
        REP(i, n+1) ans[i] = 0;
        for (map<string,int>::iterator it = cnt.begin(); it != cnt.end(); it++)
            ans[it->se]++;
        FOR(i, 1, n+1) cout <<ans[i] <<endl;
    }
    
    return 0;
}


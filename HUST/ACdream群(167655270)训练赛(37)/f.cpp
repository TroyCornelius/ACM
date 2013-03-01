/*
 * Author:  Troy
 * Created Time:  2012/6/15 19:54:22
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
string s;
int cnt[300];
bool vis[300];
int main() 
{
    int T;
    cin >>T;
    while (T--)
    {
        cin >>n;
        cin >>s;
        memset(vis, false, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        REP(i, n) cnt[s[i]]++;
        
        int ans = 0, tot = 0;
        FORD(i, n-1, 0)
        if (!vis[s[i]])
        {
            ans += cnt[s[i]] * (tot - n + i + 1);
            tot += cnt[s[i]];
            vis[s[i]] = true;            
        }
        cout <<5 * ans <<endl;
    }
    return 0;
}


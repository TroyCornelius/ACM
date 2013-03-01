/*
 * Author:  Troy
 * Created Time:  2012/7/14 15:45:20
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

string s;
map<long long, int> cnt;
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>s;
        cnt.clear();
        int i = 0, ans = 0, mx = 0, dep = 0;
        long long num;
        while (i < s.size())
        {
            if (s[i] == ',')
            {
                i++;continue;
            }
            else if (s[i] == '[')
            {
                dep++; i++;
                continue;                
            }
            else if (s[i] == ']')
            {
                dep--; i++;
                continue;
            }
            else
            {
                ans++;
                num = 0;
                while (i < s.size() && isdigit(s[i])) num = num * 10 + s[i++] - '0';
                //cout <<num <<endl;
                cnt[(num) << dep] ++;
                mx = max(mx, cnt[(num) << dep]);
            }
        }
        pf("%d\n", ans - mx);
        
    }
    return 0;
}


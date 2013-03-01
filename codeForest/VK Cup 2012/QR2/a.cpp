/*
 * Author:  Troy
 * Created Time:  2012/3/9 21:46:02
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
struct Msg
{
    string to, from;
    int t;
}d[1010];
int n, k;
set<pair<string,string> > ans;
int main() 
{
    ans.clear();
    cin >>n >>k;
    REP(i, n)
    {
        cin >>d[i].from >>d[i].to >>d[i].t;        
        bool flag = false;
        FOR(j, 0, i)
        {
            if (d[j].from == d[i].to && d[j].to == d[i].from && (d[i].t - d[j].t <= k) && d[i].t - d[j].t > 0)
            {
                pair<string,string> tmp = mp(d[i].from, d[i].to);
                if (tmp.fi > tmp.se) swap(tmp.fi, tmp.se);
                if (ans.find(tmp) == ans.end()) ans.insert(tmp);
                flag = true;
            }
            if (flag) break;
        }
    }
    cout <<ans.size() <<endl;
    for (set<pair<string,string> >::iterator it = ans.begin(); it != ans.end(); it++)
        cout <<it->fi <<" "<<it->se <<endl;
    return 0;
}


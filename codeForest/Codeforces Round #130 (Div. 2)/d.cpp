/*
 * Author:  Troy
 * Created Time:  2012/7/23 23:56:21
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
long long p[110], cnt[100];
pair<long long, int> a[100];

int main() 
{
    cin >>n;
    REP(i, n) cin >>p[i];
    REP(i, 5)
    {
        cin >>a[i].fi;
        a[i].se = i;
    }
    memset(cnt, 0, sizeof(cnt));
    sort(a, a+5);
    //REP(i, 5) cout <<a[i].fi <<" "<<a[i].se <<endl;
    long long sum = 0;
    REP(i, n)
    {
        sum += p[i];
        FORD(j, 4, 0)
        {
            //if (a[i].fi > sum) continue;
            cnt[a[j].se] += sum / a[j].fi;
            sum %= a[j].fi;
        }
    }
    REP(i, 5)
    {
        cout <<cnt[i];
        if (i == 4) cout <<endl;
        else cout <<" ";
    }
    cout <<sum <<endl;
    
    return 0;
}


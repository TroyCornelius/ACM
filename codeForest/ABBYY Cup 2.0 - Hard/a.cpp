/*
 * Author:  Troy
 * Created Time:  2012/4/28 20:15:28
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
#define sf scanf
#define pf printf
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn];
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    FOR(i, 1, n+1) cin >>a[i];
    long long ans = 0;
    
    FOR(i, 1, n)
    {
        if (a[i] == 0) cout <<ans <<endl;
        else
        {
            int tmp = n - i;
            while (tmp - (tmp&-tmp) > 0) tmp -= tmp & - tmp;
            ans += a[i];
            a[i+tmp] += a[i];         
            cout <<ans <<endl;
        }
    }
    return 0;
}


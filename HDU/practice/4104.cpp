/*
 * Author:  Troy
 * Created Time:  2012/2/9 23:04:14
 * File Name: 4104.cpp
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
#define REP(i,b) FOR(i,0,b)
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn];
int sum[Maxn];
int main() 
{
    while (~scanf("%d", &n))
    {
        sum[0] = 0;
        REP(i, n) scanf("%d", &a[i]);            
        sort(a, a+n);
        REP(i, n)  sum[i+1] = sum[i] + a[i];
        int ans = n;
        REP(i, n)
        {
            if (a[i] > sum[i]+1) ans = i;
        }
        printf("%d\n", sum[ans]+1);
    
    }
    return 0;
}


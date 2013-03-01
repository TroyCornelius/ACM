/*
 * Author:  Troy
 * Created Time:  2012/3/17 0:08:48
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
#define Maxn 1000100
#define k 22
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n, a[Maxn];
int b[1<<k];
int main() 
{
    memset(b, -1, sizeof(b));
    scanf("%d", &n);
    int x, lim = (1<<k) - 1;
    REP(i, n)
    {
        scanf("%d", &a[i]);
        x = (a[i] ^ ((1<<k)-1));
        b[x] = a[i];
    }
    FORD(i, lim-1, 1)
        if (b[i] != -1)
        {
            REP(j, k)
                if ((1<<j)&i)
                {
                    x = i ^ (1<<j);
                    b[x] = b[i];
                }
        }
    REP(i, n) printf("%d%c", b[a[i]], i==n-1?'\n':' ');
    return 0;
}


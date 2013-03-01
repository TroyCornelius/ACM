/*
 * Author:  Troy
 * Created Time:  2012/2/27 23:39:07
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
#define Maxn 500001
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int ans[Maxn+100];
int main() 
{
    memset(ans, 0, sizeof(ans));
    FOR(i, 2, Maxn)
        for (int j=i+i; j<Maxn; j+=i) ans[j] += i;
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]+1);
    }
    return 0;
}


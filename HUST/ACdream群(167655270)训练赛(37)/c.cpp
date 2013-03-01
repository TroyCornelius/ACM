/*
 * Author:  Troy
 * Created Time:  2012/6/15 21:09:22
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
#define sf scanf
#define pf printf
#define Maxn 10100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int a, b, len;
char ans[Maxn];
int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d/%d", &a, &b);
        len = 0;
        while (a > 1 || b > 1)
        {
            if (a < b)
            {
                ans[len++] = 'L';
                swap(a, b);
                a -= b;
            }
            else
            {
                ans[len++] = 'R';
                a -= b;
                swap(a, b);
            }
        }
        REP(i, len) pf("%c", ans[i]);
        pf("\n");
    }
    return 0;
}


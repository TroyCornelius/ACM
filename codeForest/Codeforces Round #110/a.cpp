/*
 * Author:  Troy
 * Created Time:  2012/3/1 20:08:40
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

int n, a[50][50];
int main() 
{
    cin >>n;
    REP(i, n)
        REP(j, n)
            cin >>a[i][j];
    int ans = 0;
    REP(i, n)
        REP(j, n)
        {
            int s1 = 0, s2 = 0;
            REP(x, n) s1 += a[x][j];
            REP(x, n) s2 += a[i][x];
            if (s1 > s2) ans++;
        }
    cout <<ans <<endl;
    return 0;
}


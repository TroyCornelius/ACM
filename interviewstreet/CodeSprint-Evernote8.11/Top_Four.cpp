/*
 * Author:  Troy
 * Created Time:  2012/8/11 23:03:01
 * File Name: Top_Four.cpp
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

long long ans[5];
int n;
int main() 
{
    cin >>n;
    long long num;
    REP(i, 4) ans[i] = -(1LL<<60);
    while (n--)
    {
        cin >>num;
        int mi = 0;
        FOR(i, 1, 4)
            if (ans[i] < ans[mi]) mi = i;
        if (num > ans[mi]) ans[mi] = num;
    }
    sort(ans, ans+4);
    FORD(i, 3, 0)
        if (ans[i] != -(1LL<<60)) cout <<ans[i] <<endl;
    return 0;
}


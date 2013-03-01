/*
 * Author:  Troy
 * Created Time:  2012/6/12 21:15:35
 * File Name: aa.cpp
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

char s[Maxn];
char mx[Maxn];
int main() 
{
    cin >>s;
    int len = strlen(s);
    mx[len] = 0;
    FORD(i, len-1, 0)
        mx[i] = max(s[i], mx[i+1]);
    string ans = "";
    REP(i, len)
        if (mx[i] == s[i]) ans += s[i];
    cout <<ans <<endl;
    
    return 0;
}


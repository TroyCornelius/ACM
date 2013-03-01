/*
 * Author:  Troy
 * Created Time:  2012/5/18 19:05:37
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s;
long long a, b;
int main() 
{
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>s;
        cin >>b;
        if (b < 0) b *= -1;
        a = 0;
        REP(i, s.length())
        {
            if (!isdigit(s[i])) continue;
            a = a * 10 + (s[i] - '0');
            a %= b;
        }
        if (a == 0) cout <<"Case " <<++ca <<": divisible" <<endl;
        else cout <<"Case " <<++ca <<": not divisible" <<endl;
    }
    return 0;
}


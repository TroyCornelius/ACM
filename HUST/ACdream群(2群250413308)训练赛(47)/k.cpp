/*
 * Author:  Troy
 * Created Time:  2012/7/30 19:01:37
 * File Name: k.cpp
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

long long n;
vi d;

int main() 
{
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n;
        d.clear();
        long long tmp = n;
        while (tmp)
        {
            d.insert(d.begin(), tmp%2==0?0:1);
            tmp/=2;
        }
        d.insert(d.begin(), 0);
        next_permutation(all(d));
        long long ans = 0;
        REP(i, d.size())
        {
            if (i == 0 && d[i] == 0) continue;
            ans <<=1;
            if (d[i] == 1) ans |= 1;
        }
        cout <<"Case " <<++ca <<": " <<ans <<endl;
    }
    return 0;
}


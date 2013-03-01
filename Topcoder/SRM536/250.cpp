/*
 * Author:  Troy
 * Created Time:  2012/3/7 19:57:53
 * File Name: 250.cpp
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

class BinaryPolynomialDivTwo
{
    public:
    int countRoots(vector <int> a)
    {
        int ans = 0, cnt=0;
        if (a[0] == 0) ans++;
        REP(i, a.size()) cnt += a[i];
        if (cnt %2 == 0) ans++;
        return ans;
    }
};



int main() 
{
    return 0;
}


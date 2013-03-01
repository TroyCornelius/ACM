/*
 * Author:  Troy
 * Created Time:  2012/3/23 23:28:24
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, x, d[550];
int ans;
bool flag;
int main() 
{
    ans = 0;
    flag = false;
    cin >>n >>x;
    REP(i, n)
    {
        cin >>d[i];
        if (d[i] == x) flag = true;
    }
    if (!flag) d[n++] = x, ans++;
    sort(d, d+n);
    int p1 = -1, p2 = -1;
    REP(i, n)
    if (d[i] == x)
    {
        if (p1 == -1) p1 = i+1;
        p2 = i+1;
    }
    if (p1 <= (n+1)/2 && p2 >= (n+1)/2)
    {
        cout <<ans <<endl;
        return 0;
    }
    else
    {
        int x1 = n+1 - 2 * p2;
        int x2 = 2 * p1 - n -1;
      //  cout <<x1 <<" "<<x2 <<" "<<(n+1)/2 <<endl;
        if (p2 < (n+1)/2) 
        {
            ans += x1;
            if (x1 > 1 && (x1 - 1) + p2 == (n+x1)/2) ans--;
        }
        else
        if (p1 > (n+1)/2)
        { 
            ans += x2;
            if (p1 == (n+x2)/2) ans--;
        }
        cout <<ans <<endl;
        return 0;
    }
    
    
    return 0;
}


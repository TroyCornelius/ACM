/*
 * Author:  Troy
 * Created Time:  2012/2/10 22:49:16
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
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int k, a[15];
int main() 
{
    cin >>k;
    REP(i, 12) scanf("%d", &a[i]);
    sort(a, a+12);
    int ans = 0, sum = 0;
    for (int i=11; i>=0 && sum < k; i--)
    {
        ans++;
        sum += a[i];
    }
    if (sum < k) cout <<-1 <<endl;
    else  cout <<ans <<endl;
    return 0;
}


/*
 * Author:  Troy
 * Created Time:  2012/3/6 23:15:27
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

int n;
int a[1010];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    cin >> n;
    int summ=0;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        summ += a[i];
    }
    sort(a,a+n,cmp);
    int cnt=0, sum1=0;
    for (int i=0; i<n; i++)
    {
        sum1+=a[i];
        summ-=a[i];
        cnt++;
        if (sum1>summ) break;
    }
    cout << cnt << endl;
    return 0;
}



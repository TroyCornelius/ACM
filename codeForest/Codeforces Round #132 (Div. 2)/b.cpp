/*
 * Author:  Troy
 * Created Time:  2012/8/7 0:04:14
 * File Name: b.cpp
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

int n1, n2, n3;
double a[5050], b[5050], c[5050], aa, bb;
int main()
{
    cin >>n1;
    for(int i = 0; i < n1; i++) cin >> a[i];
    cin >> n2;
    for(int i = 0; i < n2; i++) cin >> b[i];
    cin >> n3;
    for(int i = 0; i < n3; i++) cin >> c[i];
    cin >> aa >> bb;
    double res = 1e30;
    for(int i = 0; i < n3; i++)
        for(int j = 0; j < n2; j++)
            res = min(res, c[i] / b[j]);
    res = aa / bb * res + 1.0;
    double r1 = *max_element(a, a + n1);
    printf("%.12f\n", sqrt(r1 * r1 / res));
    return 0;
}


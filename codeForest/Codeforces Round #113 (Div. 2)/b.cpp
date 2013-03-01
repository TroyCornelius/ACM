/*
 * Author:  Troy
 * Created Time:  2012/3/24 0:33:10
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
struct point
{
    int x, y ;
} ;

point h[100100], p[20100] ;
int n, m ;


double area(point a,point b,point c)
{
    double dx1 = a.x - b.x ;
    double dy1 = a.y - b.y ;
    double dx2 = a.x - c.x ;
    double dy2 = a.y - c.y ;
    return ( dx1 * dy2 - dy1 * dx2 ) / 2;
}
int isinside(point q)
{
    int i;
    double area1 = 0, area2 = 0;
    point a ;
    int flag=0;
    a.x = 0 , a.y = 0;
    for( i = 0 ; i < n ; i++ )
    {
       double tmp;
       tmp= area(q,h[i],h[(i+1)%n]);
       if (tmp==0) flag=1;
       area1 += fabs( area(q,h[i],h[(i+1)%n]) );
       area2 += area(a,h[i],h[(i+1)%n]);
    }

    area2 = fabs(area2);
    if( area1 == area2 && flag==0) return 1;
    return 0;
}

void work()
{
    int totalvalue = 0 ;
    for( int i = 0 ; i < m ; i++ )
    {
        if( isinside( p[i] ) ) totalvalue += 1 ;
    }

    if (totalvalue==m) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >>n;
    REP(i, n) cin >>h[i].x >>h[i].y;
    cin >>m;
    REP(i, m) cin >>p[i].x >>p[i].y;
    work();
    return 0;
}


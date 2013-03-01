/*
 * Author:  Troy
 * Created Time:  2012/12/13 13:46:31
 * File Name: tst.cpp
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

typedef struct
{
    double j,f;
    double c;
}mouse;
mouse mm[1100];
int main()
{
    int n,m,i;
    while(scanf("%d%d",&m,&n),m!=-1||n!=-1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&mm[i].j,&mm[i].f);
            mm[i].c=mm[i].j/mm[i].f;
        }
    }
    return 0;
}

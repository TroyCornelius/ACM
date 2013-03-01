/*
 * Author:  Troy
 * Created Time:  2012/5/2 19:18:03
 * File Name: f.cpp
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
int n,i,k,p,p1,t,t1;
int main()
{
    while (cin>>n){
        t = t1 = 0;
    for(i=0;i<n;i++)
    {
        cin>>k;
        if(k%2==0){p=i;t++;}else {p1=i;t1++;}
    }
    if(t==1) cout<<p+1<<endl;
    else cout<<p1+1<<endl;
    }
    return 0;
}


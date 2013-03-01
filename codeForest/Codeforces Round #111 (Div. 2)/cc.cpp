/*
 * Author:  Troy
 * Created Time:  2012/3/7 0:28:00
 * File Name: 
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
long long a[110000],b[110000],c[110000],d[110000];
long long n,k,tmp,cnt,l,i,j,f;

int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    tmp=a[0];
    b[0]=tmp;
    l=0;
    cnt=1;
    for (int i=1; i<n; i++)
    {
        if (tmp!=a[i]){
            c[l]=cnt;
            l++;
            b[l]=a[i];
            tmp=a[i];
            cnt=1;
        }
        else {
            cnt++;
        }
    }
    c[l]=cnt;
    d[0]=c[0];
    for (int i=1; i<=l; i++)
    {
        d[i]=d[i-1]+c[i];
    }
    f=0; j=0;
    while (k-c[f]*d[l]>0 && f<=l)
    {
        k=k-c[f]*d[l];
        f++;
        //if (j>l) {j=0; f++;}
    }
    for (int i=0; i<=l; i++)
    {
        if (k-c[f]*c[i]>0) k=k-c[f]*c[i];
        else {j=i; break;}
    }
    cout << b[f] << " " << b[j] << endl;

}



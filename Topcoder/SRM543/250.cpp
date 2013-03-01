/*
 * Author:  Troy
 * Created Time:  2012/5/20 0:04:15
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


long long calc(long long x)
{
    if (x==3) return 0;
    if (x==2) return 3;
    if (x==1) return 1;
    if (x==0) return 0;
    long long ret = 0;
    int p = 0;
    while ((1LL<<p) <= x) p++;
    p--;
    long long t = 1LL<<p;
    while (t > 0)
    {
        if ((x & t) == 0) {t /= 2;continue;}
        //if (t == 1 && x == 1) ret += 1;
        //else
        //{
            if ((x-t+1)%2==1) ret +=t;
        //}
        if (x == 2) return ret^1;
        x -= t;
        t /= 2;
        //cout <<x <<" " <<t <<" "<<ret <<endl;
    }
    return ret;
}
class EllysXors
{
    public:
        long long getXor(long long L, long long R)
        {
            long long a = calc(R), b = calc(L-1);
            long long ret = a^b;
            cout <<a <<" "<<b <<endl;
            return ret;        
        }
        long long work(long long x)
        {
            long long ret = 0;
            FOR(i, 1, x+1) ret ^= i;
            return ret;
        }

}test;


int main() 
{
    long long a, b;
    while (cin >>a >>b) 
    {
        cout <<test.getXor(a, b) <<endl;
        cout <<"---"<<endl;
        cout <<test.work(a-1) <<" "<<test.work(b) <<endl;   
    }
    return 0;
}


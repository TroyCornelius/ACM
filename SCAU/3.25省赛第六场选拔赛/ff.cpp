/*
 * Author:  Troy
 * Created Time:  2012/3/25 14:57:48
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
const long long lim = 2000000000;
const int max_len = 31;
long long s, t;

long long c[35][35];
long long f[35];
void init()
{
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    FOR(i, 1, 33)
        REP(j, i+1)
            c[i][j] = (j == 0 ? 1 : c[i-1][j-1] + c[i-1][j]);
    f[1] = 0;
    FOR(i, 2, 33) f[i] = c[i-1][i/2-1];
}
long long getid(long long num)
{
    if (num == 1) return 0;
    int len = 0, tot = 0;
    while ((1LL << len) <= num) len++;
    long long ret = 0, tmp;
    FOR(i, 1, len) ret += f[i];
    int zero = len, one = len/2;
    zero--;
    one--;
    FORD(i, len-2, 0)
    {
        if ((1LL<<i)&num)
        {
            int ct = one;
            long long tmp = 0;
            FOR(j,0, ct+1) tmp += c[i+1][j];
            one--;
            ret += tmp ;
           // if (one >= 0) ret++;
        }
    }
   // cout <<ret <<" : "<<zero <<endl;
    return ret;

    
}
int main() 
{
    init();
    while (cin >>s >>t)
    {
      //  cout <<getid(t) <<" "<<getid(s-1) <<"---" <<endl;
        cout <<getid(t+1) - getid(s) <<endl;
       // cout <<getid(s-1) <<endl;
   //    cout <<getid(t) <<endl;
        
    }
    return 0;
}


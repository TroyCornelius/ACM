/*
 * Author:  Troy
 * Created Time:  2012/3/23 23:59:30
 * File Name: e.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int MOD = 1000000007;
int n;
int f[4][2];
int main() 
{
    cin >>n;
    memset(f, 0, sizeof(f));
    f[3][0] = 1;
    int p = 0;
    FOR(i, 1, n+1)
    {
        p ^= 1;
        REP(j, 4)
        {
            f[j][p] = 0;
            REP(k, 4)
            if (j != k)
            {
                f[j][p] += f[k][p^1];
                if (f[j][p] >= MOD) f[j][p] -= MOD;
            }
        }
    }
    cout <<f[3][n%2] <<endl;
    return 0;
}


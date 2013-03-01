/*
 * Author:  Troy
 * Created Time:  2012/2/9 23:50:49
 * File Name: 1000.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;


const int MOD = 1000000007;
int f[101][258][258], n, m, full;
int dfs(int c, int st, int pre)
{
    if (f[c][pre][st] != -1) return f[c][pre][st];
    if (c == n)
    {
        int tot;
        bool flag = true;
        REP(i, m)
        if ((1<<i) & st)
        {
            tot = ((1<<i)&pre)>0?1:0;
            if (i+1<m)
            {
                tot += ((1<<(i+1))&st)>0?1:0;                 
            }
            if (i-1>=0) tot += ((1<<(i-1))&st)>0?1:0;
            if (tot & 1 != 0) {flag = false; break;}
        }

        if (!flag) return f[c][pre][st] = 0;   
        else return f[c][pre][st] = 1;
    }
    else
    {
        f[c][pre][st] = 0;
        REP(i, full)
        {
           bool flag = true;
           REP(j, m)
           if ((1<<j)&st)
           {
            int tot = ((1<<j)&i)>0?1:0;
            tot += ((1<<j)&pre)>0?1:0;
            if (j+1<m) tot += ((1<<(j+1))&st)>0?1:0;                 
            if (j-1>=0) tot += ((1<<(j-1))&st)>0?1:0;
            if (tot & 1 != 0) {flag = false;break;}            
            }
            if (flag) f[c][pre][st] += dfs(c+1, i, st);
            if (f[c][pre][st] >= MOD) f[c][pre][st] -= MOD;
        }
        return f[c][pre][st];
    
    
    }    
}
class DengklekPaintingSquares
{
    public:
    int numSolutions(int N, int M)
    {
        full = (1 << M) ;
        n = N, m = M;
        memset(f, -1, sizeof(f));
        int ans = 0;
        REP(i, full) 
        {
            ans += dfs(1, i, 0);
            if (ans >= MOD) ans -= MOD;
        }
        return ans;    
    }
};
DengklekPaintingSquares t;
int main() 
{
    int a, b;
    while (cin >>a >>b)
    {
          cout <<t.numSolutions(a, b) <<endl;
          REP(i, full) cout <<f[1][0][i] <<" ";
          cout <<endl;
          REP(i, full) cout <<f[2][2][i] <<" ";
          cout <<endl;
    }
    return 0;
}


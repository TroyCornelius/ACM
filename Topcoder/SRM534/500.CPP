/*
 * Author:  Troy
 * Created Time:  2012/2/24 10:17:06
 * File Name: 500.CPP
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
#define Maxn 1<<21
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


int f[Maxn], n;
bool check(int st, int k)
{
    if (!((1<<(k-3))& st) && (1<<(k-1)&&st) && (1<<(k-2))&st) return true;
    else return false;
}
int dfs(int st, int who)
{
    cout <<st <<" "<<who <<endl;
    if (f[st] != -1) return f[st];
    int ret = 0;
    bool flag = false;
    FOR(i, 1, n)
    {
        if ((1<<i) & st)
        {
            if (!((1<<(i-1))&st))
            {
                flag = true;
                int next = st - (1<<i);
                if (i-1 > 0) next += (1<<(i-1));
                ret |= dfs(next, 1 - who);                
            }
            if (i >= 3 && check(st, i))
            {
                int next = st - (1<<i);
                if (i - 3 > 0) next += (1 << (i-3));
                flag = true;
                ret |= dfs(next, 1 - who);
            }            
        }        
    }
    cout <<st <<" "<<who <<" " <<ret <<" "<<flag <<endl;
    if (!flag) f[st] = 0; //(who == 0 ? 0 : 1);
    else 
    {
    /*    if (ret)
        {
            f[st] = 1;
            
        }
        else
        {
            f[st] = 0;
           // if (who == 0) f[st] = 1;
           // else f[st] = 0;
        }*/
        f[st] = ret ^ 1;
    }
    cout <<st <<" "<<who <<" " <<f[st] <<endl;
    return f[st];
}
class EllysCheckers
{
    public:
    string getWinner(string board)
    {
        int now = 0;
        n = board.size();
        if (board[n-1] == 'o') board[n-1] = '.';
        REP(i, n) now = (now<<1) + (board[i] == '.'?0:1);
        
        memset(f, -1, sizeof(f));
        int ans = dfs(now, 0);
        cout <<ans <<endl;
        FOR(i, 0, 10) cout <<f[i] <<" " <<i <<endl;
        cout <<endl;
        if (ans) return "YES";
        else return "NO";
        
    }
}t;
 
int main() 
{
    string s = ".o...";
    cout <<t.getWinner(s) <<endl;
    return 0;
}


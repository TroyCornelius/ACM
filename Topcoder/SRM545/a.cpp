/*
 * Author:  Troy
 * Created Time:  2012/6/7 23:08:23
 * File Name: a.cpp
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

int need;
int n;

int calc(int used, int now)
{
    used |= (1 << now);
    int ret = 0;
    FORD(j, n-1, 0)
        if (!((1<<j)&used))
        {
            REP(k, j)
                if (!((1<<k)&used)) ret++;
        }
    return ret;
}
string dfs(string s, int tot, int vis)
{
    if (s.size() == n)
    {
        if (tot >= need) return s;
        else return "";
    }
    
    REP(i, n)
        if (!((1<<(i))&vis))
        {
            int cnt = i;
            REP(j, n)
                if ((1<<j)&vis) cnt--;
            int tmp = calc(vis, i);
            if (tot + cnt + tmp >= need) 
            {
                char ch = 'a' + i;
                return dfs(s + ch, tot + cnt, vis | (1<<i));
            }
        }
    return "";
    
}
string work(string s)
{
    string s1 = "";
    while (s.size() < n) s += '-';
    int tot = 0, used = 0;
    bool chg = false;
    REP(i, n)
    {
        int st = (s[i] == '-') ? 0 : s[i] - 'a';
        if (chg) st = 0;
        FOR(j, st, n)
        if (!((1<<j)&used))
        {
            int t1 = calc(used, j);
            int c1 = 0;
            REP(k, j)
                if (!((1<<k) & used)) c1++;
            if (tot + c1 + t1 >= need)
            {
                tot += c1;
                s1 += (char)('a' + j);
                cout <<s1 <<" "<< j <<endl;
                if (!chg && j > (s[i]-'a')) chg = true;
                used |= (1<<j);
                break;
            }
        }
        if (s1.size() != i+1) return "";
    }
    return s1;
}
class StrIIRec
{
    public:
    string recovstr(int nn, int minInv, string minStr)
    {
        string ret = "";
        need = minInv; n = nn;
        string tt = work(minStr);
        if (tt != "") return tt;
        FOR(i, minStr[0]-'a'+1, 26)
        {
            ret = dfs(""+(char)i, i, (1<<(i)));
            if (ret != "") break;
        }
        return ret;
        
    }
    

}test;


int main() 
{
    cout <<test.recovstr(2, 1, "ab") <<endl;;
    return 0;
}


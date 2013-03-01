/*
 * Author:  Troy
 * Created Time:  2012/2/10 0:09:36
 * File Name: 500.cpp
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
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int getval(string s, int op)
{
    int ret = 0;
    if (op == 1) {
        REP(i, s.length()) 
        if (isdigit(s[i])) ret += s[i] - '0';
        else break;
        }
    else
    if (op == 2)
    {
        for (int i=s.length()-1; i>=0; i--)
            if (isdigit(s[i])) ret += s[i] - '0';
            else break;
    }
    else
    if (op == 3)
    {
        int cnt = 0;
        REP(i, s.length()) 
        if (isdigit(s[i])) cnt += s[i] - '0', ret = max(ret, cnt);
        else cnt = 0;                               
    }
    return ret;
}
class DengklekMakingChains
{
    public:
    int maxBeauty(vector <string> c)
    {
        int ans = 0, tmp, ret = 0;
        vector<string> d;
        REP(i, c.size())
        {
            if (isdigit(c[i][0]) && isdigit(c[i][1]) && isdigit(c[i][2])) ret += getval(c[i], 3);
            else d.pb(c[i]);     
            ans = max(ans, getval(c[i], 3));
        }
        ans = max(ans, ret);
        REP(i, d.size())
        {
            int t1 = getval(d[i], 1), k1 = getval(d[i], 2), t2 = 0, k2 = 0;
            tmp = max(t1 + ret + t2, k2 + ret + k1);
            if (tmp > ans) ans = tmp;           
            FOR(j, i+1, d.size())
            {
                 t2 = getval(d[j], 2);
                 k2 = getval(d[j], 1);
                tmp = max(t1 + ret + t2, k2 + ret + k1);
                if (tmp > ans) ans = tmp;        
                //cout <<ans <<" "<<tmp <<" "<<d[i]<<" "<<d[j]<<endl;
            }
        }
        return ans;
    }

};
int main() 
{
    return 0;
}


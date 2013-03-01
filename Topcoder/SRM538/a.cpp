/*
 * Author:  Troy
 * Created Time:  2012/3/20 22:50:15
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int ans, len;
void dfs(string s, int loc)
{
    if (loc >= len)
    {
        int tmp = 0;
        cout <<s <<endl;
        REP(i, len)
        {
            if (s[i] == 'L') tmp--;
            else tmp++;
            cout <<tmp<<endl;
            ans = max(ans, abs(tmp));
        }
        return;
    }
    else
    {
        if (s[loc] != '?') dfs(s, loc+1);
        else
        {
            int i = loc;
            string t = s;
            while (i < len && s[i] == '?') {t[i] = 'L'; i++;}
            dfs(t, i);
            i = loc;
            while (i < len && s[i] == '?') {t[i] = 'R'; i++;}
            dfs(t, i);
        }
    }
}
class LeftOrRight
{
    public:
    int maxDistance(string program)
    {
        ans = 0;
        len = program.length();
        dfs(program, 0);
        return ans;
    }

};

int main() 
{
    return 0;
}


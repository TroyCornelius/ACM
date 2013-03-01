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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, tot, m, now;
string ans;
string s[Maxn];
bool flag;
string dfs()
{
    string ret = "";
    //if (tot >= n) return ret;
    //string st;
    //cin >>st;
    if (now >= m) return ret;
    //char st[5];
    //if (sf("%s", st) == EOF) return ret;
    if (s[now][0] == 'i')
    {
        //tot++;
        //now++;
        return s[now];
    }
    else
    {
        now++;
        string s1 = dfs();
        now++;
        string s2 = dfs();
        if (s1 == "" || s2 == "") 
        {
            flag = false;
            return ret;
        }
        else
        {
            ret = "pair<" + s1 + "," + s2 + ">";
            return ret;
        }
        
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    //sf("%d", &n);
    tot = 0;  m = 0;
    while (cin >>s[m]) m++;
    //cin >>s;
    //sf("%s", s);
    if (n == 1 && s[0][0] == 'p') pf("Error occurred\n");//cout <<"Error occurred" <<endl;
    else
    if (n == 1 && s[0][0] == 'i') pf("int\n");
    else
    {
        flag = true;
        now = 1;
        string s1 = dfs();
        now++;
        string s2 = dfs();
        if (s1 == "" || s2 == "" || !flag) pf("Error occurred\n");//cout <<"Error occurred" <<endl;cout <<"Error occurred" <<endl;
        else 
        {
            ans = "pair<" + s1 + "," + s2 + ">";
            //cout <<ans <<endl;
            pf("%s\n", ans.c_str());
        }
    } 
    return 0;
}


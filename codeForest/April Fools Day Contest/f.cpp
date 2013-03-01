/*
 * Author:  Troy
 * Created Time:  2012/4/1 23:31:32
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
#define Maxn 1000000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
string s;
char c[256];
void init()
{
    c['q'] = 'a';
    c['d'] = 'n';
    c['y'] = 'i';
    c['j'] = 't';
    c['u'] = 'e';
    c['w'] = 'g';
    c['h'] = 'r';
    c['x'] = 'h';
    c['k'] = 'u';
    c['e'] = 'o';
    c['f'] = 'p';
    c['c'] = 'm';
    c['r'] = 'b';
    c['v'] = 'f';
    c['i'] = 's';
    c['b'] = 'l';
    c['s'] = 'c';
    c['t'] = 'd';
    c['n'] = 'x';
    c['m'] = 't';
    c['l'] = 'v';
    c['a'] = 'k';
    c['o'] = 'y';
}
int n;
bool b[Maxn+10];
vi p, em;
bool check(int num)
{
    int ret = 0, tmp = num;
    while (num)
    {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
    return  tmp != ret && b[ret];
}
void work()
{
    memset(b, true, sizeof(b));
    FOR(i, 2, Maxn+1)
        if (b[i])
        {
            p.pb(i);
            for (int j=i+i; j<=Maxn; j+=i) b[j] = false;
        }
    REP(i, p.size())
    {
        if (em.size() > 11184) break;
        if (check(p[i])) em.pb(p[i]);
    }
}
int main() 
{
  /*  init();
    getline(cin, s);
    REP(i, s.length())
        if (s[i] != ' ') s[i] = c[s[i]];
    
    cout <<s <<endl;*/
    work();
    cin >>n;
    cout <<em[n-1] <<endl;
    return 0;
}


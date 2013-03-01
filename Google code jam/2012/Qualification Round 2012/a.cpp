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
int n;
void init()
{
    c['z'] = 'q';
    c['q'] = 'z';
    c['d'] = 's';
    c['y'] = 'a';
    c['j'] = 'u';
    c['u'] = 'j';
    c['w'] = 'f';
    c['h'] = 'x';
    c['x'] = 'm';
    c['k'] = 'i';
    c['e'] = 'o';
    c['f'] = 'c';
    c['c'] = 'e';
    c['r'] = 't';
    c['v'] = 'p';
    c['i'] = 'd';
    c['b'] = 'h';
    c['s'] = 'n';
    c['t'] = 'w';
    c['n'] = 'b';
    c['m'] = 'l';
    c['l'] = 'g';
    c['a'] = 'y';
    c['o'] = 'k';
    c['p'] = 'r';
    c['g'] = 'v';
}
int main() 
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    int ca = 0;
    init();
    cin >>n;
    getline(cin, s);
    while (n--)
    {
        getline(cin, s);
        cout <<"Case #" <<++ca <<": ";
        REP(i, s.length()) 
            if (s[i] == ' ') cout <<s[i];
            else cout <<c[s[i]];
        
        cout <<endl;        
    }
    return 0;
}


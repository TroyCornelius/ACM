#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

string s, p;
int n, m, tot;
int cnt[30], now[30];
inline bool check()
{
    int sum = 0;
    REP(i, 26)
    {
        if (now[i] > cnt[i]) return false;
        else sum += cnt[i] - now[i];    
    }
    return sum == tot;
}
int main()
{
    //while (1){
    int ans = 0;
    ios::sync_with_stdio(false);
    cin >>s;
    cin >>p;
    int len1 = s.length(), len2 = p.length();
    if (len2 > len1) {cout <<0 <<endl; return 0;}
    memset(cnt, 0, sizeof(cnt));
    memset(now, 0, sizeof(now));
    REP(i, p.length()) cnt[p[i]-'a']++;
    tot = 0;
    REP(i, len2)
    {
        if (s[i] == '?') tot++;
        else now[s[i]-'a']++;    
    }
    if (check()) ans++;
    FOR(i, len2, len1)
    {
        if (s[i-len2] == '?') tot--;
        else now[s[i-len2]-'a']--;        
        if (s[i] == '?') tot++;
        else now[s[i]-'a']++;  
        if (check()) ans++;
    }
    cout <<ans <<endl;
//}
    return 0;
}

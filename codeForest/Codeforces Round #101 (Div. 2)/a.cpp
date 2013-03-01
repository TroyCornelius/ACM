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

string s1, s2, s3;
int b[50];
int main()
{
    
    cin >>s1 >>s2 >>s3;
    memset(b, 0, sizeof(b));
    for (int i=0; i<s1.length(); i++) b[s1[i]-'A']++;
    for (int i=0; i<s2.length(); i++) b[s2[i]-'A']++;
    for (int i=0; i<s3.length(); i++) b[s3[i]-'A']--;
    bool ans = true;
    for (int i=0; i<=26; i++)
       if (b[i] != 0) {ans=false;break;} 
    if (ans) cout <<"YES" <<endl;
    else cout <<"NO" <<endl;

    return 0;
}

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

int A, B, ans;
void calc(int a)
{
    //cout <<a <<" is: " ;
    map<int,int> dic;
    dic.clear();
    int tmp = 10, p = 1;
    while (p <= a) p *= 10;
    p /= 10;
    while (tmp <= a)
    {
        int b = a / tmp + (a % tmp) * p;
        tmp *= 10; p /= 10;
        //if ((a/(tmp/10))%10 == 0) continue;
        if (b > a && b > A && b <= B && dic.find(b) == dic.end()) 
        {
            ans++;
            dic[b] = 1;
        }
        //cout <<b <<" ";}
    }    
    //cout <<endl;
}
int main() 
{
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);
    int T, ca = 0;
    cin >>T; 
    while (T--)
    {
        cin >>A >>B;
        ans = 0;
        FOR(i, A, B)
            calc(i);
        cout <<"Case #" <<++ca <<": " <<ans <<endl;
    }
    return 0;
}


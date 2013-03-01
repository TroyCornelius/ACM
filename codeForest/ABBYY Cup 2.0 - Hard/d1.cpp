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

int n, num[20];

bool check(vi a)
{
    int sum = 0, tmp;
    REP(i, n) sum += num[a[i]];
    
    int p = 0, k = 1;
    while (p < n*n)
    {
        tmp = 0;
        for (p; p<k*n; p++) tmp += num[a[p]];
        k++;
        if (tmp != sum) return false;
    }
    REP(i, n)
    {
        tmp = 0;
        for (int j = i; j < n*n; j += n) tmp += num[a[j]];
        if (tmp != sum) return false;
    }
    
    tmp = 0;
    for(p = 0; p < n*n; p += n+1) tmp += num[a[p]];
    if (tmp != sum) return false;
    
    tmp = 0;
    if (n == 1) tmp = num[a[0]];
    else for (p = n-1; p <= n*(n-1); p += n - 1) tmp += num[a[p]];
    
    return tmp == sum;    
    
}
void bf()
{
    vi a;
    REP(i, n*n) a.pb(i);
    do
    {
        //REP(i, a.size()) cout <<a[i] <<endl;
        if (check(a)) 
        {
            //cout <<a[0] <<endl;
            int sum = 0;
            REP(i, n) sum += num[a[i]];
            cout <<sum <<endl;;
            REP(i, n*n)
            {
                cout <<num[a[i]];
                if (i % n == n - 1) cout <<endl;
                else cout <<" ";
            }
            return;
        }
        
        //REP(i, a.size()) cout <<a[i] <<endl;
    }while (next_permutation(all(a)));
}
int main() 
{
    cin >>n;
    REP(i, n*n) cin >>num[i];
    if (n <= 3) bf();
    else
    {
        
    }
    return 0;
}


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

int n, len, k;
long long a[Maxn];
multiset<long long> neg, pos;
inline long long ABS(long long x)
{
    return x > 0 ? x : -x;
}
inline long long MAX(long long a, long long b)
{
    return a > b ? a : b;
}
int main() 
{
    sf("%d%d", &n, &len);
    REP(i, n) sf("%I64d", &a[i]);
    sf("%d", &k);
    neg.clear();
    pos.clear();
    long long s1 = 0, s2 = 0;
    long long sum = 0, ans = -(1LL<<60);
    REP(i, len)
    {
        sum += a[i];
        if (a[i] > 0) 
        {
            pos.insert(a[i]);
            s1 += a[i];
        }
        else 
            if (a[i] < 0)
            {
                s2 += a[i];
                neg.insert(a[i]);
            }
        
        if (pos.size() > k) 
        {
            s1 -= *pos.begin();
            pos.erase(pos.begin());
        }
        if (neg.size() > k) 
        {
            multiset<long long>::iterator it = neg.end();
            it--;
            s2 -= *it;
            neg.erase(it);
        }
    }
    //cout <<ans <<" "<<sum-s1-s1 << " " <<sum - s2 - s2 <<" " << sum <<" "<<s1 <<" "<<s2 <<endl;
    ans =MAX( ABS(sum - s1 - s1), ABS(sum - s2 - s2));

    FOR(i, len, n)
    {
        sum -= a[i - len];
        sum += a[i];
        //cout <<sum <<endl;
        if (a[i-len] > 0)
        {
            multiset<long long>::iterator it = pos.find(a[i-len]);
            if (it != pos.end())
            {
                s1 -= *it;
                pos.erase(it);
            }
        }
        else
        if (a[i-len] < 0)
        {
            multiset<long long>::iterator it = neg.find(a[i-len]);
            if (it != neg.end())
            {
                s2 -= *it;
                neg.erase(it);
            }   
        }
        //cout <<"----------------------------------" <<endl;
        if (a[i] > 0)
        {
            pos.insert(a[i]);   
            s1 += a[i];
            if (pos.size() > k) 
            {
                s1 -= *pos.begin();
                pos.erase(pos.begin());
            }
        }
        else if (a[i] < 0) 
        {
            neg.insert(a[i]);
            s2 += a[i];
            if (neg.size() > k) 
            {
                multiset<long long>::iterator it = neg.end();
                it--;
                s2 -= *it;
                neg.erase(it);
            }  
        }      
        ans =MAX(ans, MAX( ABS(sum - s1 - s1), ABS(sum - s2 - s2)));
    //cout <<ans <<" "<<sum-s1-s1 << " " <<sum - s2 - s2 <<" " << sum <<" "<<s1 <<" "<<s2 <<endl;
    }
    cout <<ans <<endl;
    return 0;
}


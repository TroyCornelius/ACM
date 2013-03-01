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
using namespace std;

string s;
vector<int>a, b;
int main()
{
    while (1){
          a.clear();
          b.clear();
    cin >>s;
    cout <<s <<endl;
    int n = s.length();
    for (int i=0; i<n; i++)
    {
        a.pb(s[i]-'0');
        b.pb(s[i]-'0');    
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0, cnt;
    vector<int> ansa, ansb;
    ansa = a, ansb = b;
    do
    {
        sort(b.begin(), b.end());
        do
        {
            int cnt = 0, c=0;
            for (int i=n-1; i>=0; i--)
            {
                c += a[i] + b[i];
                if (c%10 == 0) cnt++;
                c/=10;            
            }
            if (cnt > ans) 
            {
                ans = cnt;
                ansa = a;
                ansb = b;            
            }           
        }while (next_permutation(b.begin(), b.end()));

    }while (next_permutation(a.begin(), a.end()));
    
    for (int i=0; i<n; i++) cout <<ansa[i];
        cout <<endl;
    for (int i=0; i<n; i++) cout <<ansb[i];
    cout <<endl;
    }
    return 0;
}

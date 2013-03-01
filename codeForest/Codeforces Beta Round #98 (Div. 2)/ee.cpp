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
#define Maxn 201000
using namespace std;

string s;
int que[Maxn], sum[Maxn], ans, cnt;
inline bool isvow(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
int main()
{
   // while (1){
    ans = cnt = 0;
    cin >>s;
    int n = s.length();
    for (int i=0; i<n; i++) s[i] = tolower(s[i]);
    sum[0] = 0;
    for (int i=0; i<n; i++) sum[i+1] = sum[i] + (isvow(s[i]) ? -1 : 2);
    int ri = 0;
    que[ri++] = 0;
    int maxp;
    for (int i=0; i<n; i++)
    {
        if (sum[i+1] - sum[que[ri-1]] >= 0)
        {
            int lo = 0, hi = ri-1, mid;
            while (lo+1 < hi)
            {
                mid = (lo + hi) >>1;
                if (sum[i+1] - sum[que[mid]] >= 0) hi = mid;
                else lo = mid;            
            }
            if (sum[i+1] - sum[que[lo]] >= 0)  maxp = que[lo];
            else maxp = que[hi];
            if (i-maxp+1 > ans) ans = i-maxp+1, cnt = 1;
            else if (i-maxp+1 == ans) cnt++;
        }
        if (sum[i+1] < sum[que[ri-1]]) que[ri++] = i+1;
    }
    if (ans == 0) cout <<"No solution" <<endl;
    else  cout <<ans <<" "<<cnt <<endl;
//}
    return 0;
}

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
#define all(a) (a).begin(),(a).end()
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m;
int a1, a2, a3, a4;
string ans;

void work()
{
    if (a3 < a4)
    {
        while (a3--)
        {
            ans += "74";
            a1--; a2--; a4--;        
        }
        ans += "74"; 
        a1--;a2--;a4--;
        if (a4) {cout <<"-1" <<endl; return;}    
    }
    else
        if (a3 == a4)
        {
            while (a3--)
            {
                ans += "47";
                a1--; a2--; a4--;            
            }
            ans += "4";
            a1--;        
        }
        else
            if (a4 < a3)
            {
                while (a4--)
                {
                    ans += "47";
                    a1--; a2--; a3--;                
                }
                ans += "47";
                a1--; a2--; a3--;
                if (a3) {cout <<"-1" <<endl; return;}            
            }
    if (a1 < 0 || a2 < 0) {cout <<"-1" <<endl; return;}
    
    string p1, p2;
    while (a1--) p1 += "4";
    while (a2--) p2 += "7";
    
    string tmp;
    int len = ans.size();
    
    int t1, t2;
    for (t1 = len-1; t1>=0; t1--)
        if (ans[t1] == '7') break;
    for (t2=0; t2<len; t2++)
        if (ans[t2] == '4') break;
    
    REP(i, t2+1) tmp += ans[i];
    tmp += p1;
    FOR(i, t2+1, t1+1) tmp += ans[i];
    tmp += p2;
    
    FOR(i, t1+1, len) tmp += ans[i];
    
    cout <<tmp <<endl;
}
int main()
{
   // while (1){
    cin >>a1 >>a2 >>a3 >>a4;
    ans = "";
    work();
//}
   
    return 0;
}

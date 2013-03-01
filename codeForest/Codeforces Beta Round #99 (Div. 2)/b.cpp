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
const int inf = 1<<29;
int n, m;
struct Room
{
        int wid, len, hei;
}r[800];
struct Tnode
{
    int p;
    double len, wid; 
}pa[800];
int main()
{
   // while (1){
    cin >>n;
    for (int i=0; i<n; i++) cin >>r[i].len >>r[i].wid >>r[i].hei;
    cin >>m;
    for (int i=0; i<m; i++) cin >>pa[i].len >>pa[i].wid >>pa[i].p;
    
    int ans = 0, tmp;
    double area;
    for (int i=0; i<n; i++)
    {
        area = 2.0 * (r[i].len + r[i].wid);
        tmp = inf;
        for (int j=0; j<m; j++)
        {
            double t = ceil(area/(floor((pa[j].len/(double)r[i].hei))*pa[j].wid));
            int cnt = pa[j].p * int(t);
          //  cout <<t <<" "<<area <<" "<<pa[j].len*pa[j].wid <<endl;
            if (cnt < tmp) tmp = cnt;
         //   cout <<cnt <<" "<<tmp <<endl;
        }
        ans += tmp;    
    }
    cout <<ans <<endl;
//}

    return 0;
}

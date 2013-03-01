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

int xa,xb,ya,yb,n;
int x[1010],y[1010],r[1010];
int dis,cnt;
bool flag;
void init()
{
     scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
     scanf("%d",&n);
     REP(i, n) scanf("%d%d%d",&x[i],&y[i],&r[i]);      
}
inline bool check(int tx, int ty, int k)
{
       int x1 = tx - x[k], y1 = ty - y[k];
       return x1*x1 + y1*y1 <= r[k]*r[k];
       }
int main()
{
    //while (1){
    init();
    cnt=0;
    if (xa>xb) swap(xa,xb);
    if (ya>yb) swap(ya,yb);
    for (int j=ya; j<=yb; j++)
    {
        flag=false;
        for (int l=0; l<n; l++)
        {
            dis=(xa-x[l])*(xa-x[l])+(j-y[l])*(j-y[l]);
            if (dis<=r[l]*r[l]) {flag=true; break;}
        }
       if (flag==false) {cnt++;}
    }
    for (int j=ya; j<=yb; j++)
    {
        flag=false;
        for (int l=0; l<n; l++)
        {
            dis=(xb-x[l])*(xb-x[l])+(j-y[l])*(j-y[l]);
            if (dis<=r[l]*r[l]) {flag=true; break;}
        }
  if (flag==false) {cnt++;}
    }
    for (int j=xa; j<=xb; j++)
    {
        flag=false;
        for (int l=0; l<n; l++)
        {
            dis=(j-x[l])*(j-x[l])+(ya-y[l])*(ya-y[l]);
            if (dis<=r[l]*r[l]) {flag=true; break;}
        }
        if (flag==false) {cnt++;}
    }
    for (int j=xa; j<=xb; j++)
    {
        flag=false;
        for (int l=0; l<n; l++)
        {
            dis=(j-x[l])*(j-x[l])+(yb-y[l])*(yb-y[l]);
            if (dis<=r[l]*r[l]) {flag=true; break;}
        }
        if (flag==false) {cnt++;}
    }
    flag=false;
    for (int l=0; l<n; l++)
    {
        dis=(xa-x[l])*(xa-x[l])+(ya-y[l])*(ya-y[l]);
        if (dis<=r[l]*r[l]) {flag=true; break;}
    }
   if (flag==false) {cnt--;}
    flag=false;
    for (int l=0; l<n; l++)
    {
        dis=(xa-x[l])*(xa-x[l])+(yb-y[l])*(yb-y[l]);
        if (dis<=r[l]*r[l]) {flag=true; break;}
    }
    if (flag==false) { cnt--;}
    flag=false;
    for (int l=0; l<n; l++)
    {
        dis=(xb-x[l])*(xb-x[l])+(ya-y[l])*(ya-y[l]);
        if (dis<=r[l]*r[l]) {flag=true; break;}
    }
    if (flag==false) {cnt--;}
    flag=false;
    for (int l=0; l<n; l++)
    {
        dis=(xb-x[l])*(xb-x[l])+(yb-y[l])*(yb-y[l]);
        if (dis<=r[l]*r[l]) {flag=true; break;}
    }
    if (flag==false) { cnt--;}
    cout << cnt << endl;
    return 0;
//}
    return 0;
}

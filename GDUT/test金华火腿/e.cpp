#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-16
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

struct Point{
    double x,v;
}a[1001000];
int n,tmp1;

bool check(double mid){
    double minn,tmp;
    minn=1e50;
    tmp=-1e50;
    for (int i=0; i<n; i++) {
        if (a[i].v>0) {
            if (a[i].x+mid*a[i].v>tmp) tmp=a[i].x+mid*a[i].v;
        }
        else {
            if (a[i].x+mid*a[i].v-tmp<minn) minn=a[i].x+mid*a[i].v-tmp;
        }
    }
    //if (abs(minn)<eps) tmp1=0;
    if (minn<0) return true;
    else return false;
}

int main() {
    while (~scanf("%d",&n)) {
        for (int i=0; i<n; i++) {
            //cin >> a[i].x >> a[i].v;
            scanf("%lf%lf", &a[i].x, &a[i].v);
        }
        double l,r,mid;
        l=eps; r=1e10;
        for (int t=0; t<100; t++) {
            mid=(l+r)/2.0;
            if (check(mid)) r=mid-eps;
            else l=mid+eps;
        }
        int tmp1=-1;
        int flag=0; 
        for (int i=0; i<n; i++) {
            if (a[i].v>0) flag=1;
            else if (flag!=0) tmp1=0;
        }
        if (tmp1==-1) printf("-1\n");//cout << tmp1 << endl;
        else printf("%.13f\n",l);
        
    }
    return 0;
}


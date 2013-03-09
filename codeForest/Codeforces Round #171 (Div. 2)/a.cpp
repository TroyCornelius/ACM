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
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define fi first
#define se second

int x,y;

int main() {
    while (cin >> x >> y) {
        int ans=0;
        if ((x==1 && y==0)  || (x==0 && y==0)) {
            cout << 0 << endl;
            continue;
        }
        if (x==0 && y==1) {
            cout << 2 << endl;
            continue;
        }
        if (x>0 && x==y) y--;
        if (x<0 && -x==y) x++;
        if (x<0 && x==y) y++;
        if (x>0 && -x==y) x--;
        if (x>0 && abs(y)<x) {
            ans=1;
            for (int i=0; i<(x-1); i++) ans+=4;
        }
        else {
            if (x<0 && abs(y)<-x) {
                ans=3;
                for (int i=0; i<-x-1; i++) ans+=4;
            }
            else {
                if (y>0 && abs(x)<y) {
                    ans=2;
                    for (int i=0; i<y-1; i++) ans+=4;
                }
                else {
                    if (y<0 && abs(x)<-y) {
                        ans=4;
                        for (int i=0; i<-y-1; i++) ans+=4;
                    }
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}

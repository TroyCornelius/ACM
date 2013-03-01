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
#include <ctime>
                   
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

int a[110],now[110];
int n,ans,tmp,d;

int main(){ 
    //freopen("d.in", "r", stdin);
    //freopen("test2.txt", "w", stdout);
    //int st = clock();
    int T;
    cin >> T;
    while (T--){
          scanf("%d%d",&n,&d);
          for (int i=0; i<n; i++) scanf("%d",&a[i]);           
          ans=inf; 
          for (int i=0; i<=(1<<min(d,n))-1; i++){ 
              tmp=0;
              for (int j=0; j<n; j++) now[j]=a[j];
              for (int j=0; j<n; j++)
                  if ((j-d<0 && (i&(1<<j))) || (j-d>=0 && now[j-d])){ 
                     tmp++;
                     for (int l=max(0,j-d); l<=j+d && l<n; l++) now[l]=!now[l];//now[l]^=1;//
                  }
              for (int j=n-d; j<n; j++) if (now[j]) {tmp=inf; break;}
              ans=min(ans,tmp);
          }
          if (ans==inf)printf("impossible\n");
          else printf("%d\n",ans);
  }
    //cout <<clock() - st <<endl;
  return 0;
}


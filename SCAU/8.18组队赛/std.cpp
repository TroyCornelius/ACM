#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif 

#include<iostream>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define ref(x,y) if(x+=y,x>=MC)x-=MC;
const int maxn=51,maxm=5,maxb=1<<maxm,MC=1000000007;
int N,M;
unsigned map[maxn];
int f[2][maxb][maxb][maxb];
int can[maxb][maxb+1];
unsigned all;
  
  void init(){
    char ch;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i){
      map[i]=0;
      for(int j=0;j<M;++j){
        for(ch=getchar();ch!='#'&&ch!='.';ch=getchar());
        if(ch=='.')map[i]+=(1<<j);
      }
    }
    bool flag;
    unsigned i,j,p;
    int k;
    all=(1<<M)-1;
    for(i=0;i<=all;++i){
      can[i][0]=0;
      for(j=0;j<=all;++j)if((j|i)==i){
        flag=true; p=j;
        for(k=1;k<M;++k){
          p=(p>>1)&i;
          if(p&j){flag=false;break;}
        }
        if(flag)can[i][++can[i][0]]=j;
      }
    }
  }
  
  void dp(){
    int step,ans;
    unsigned x,y,i,j,k,ti,tj,tk,pos,p;
    int ii;
    memset(f[0],0,sizeof(f[0]));
    f[0][0][0][0]=1;
    for(step=0;step<N;++step){
      y=step&1; x=!y;
      memset(f[x],0,sizeof(f[x]));
      for(i=0;i<=all;++i)
        for(j=0;j<=all;++j)
          for(k=0;k<=all;++k)if(f[y][i][j][k]){
            ti=i&map[step],tj=(j&map[step])>>1,tk=((k&map[step])<<1)&all;
            pos=(~(ti|tj|tk))&map[step+1]&all;
            for(ii=1;ii<=can[map[step+1]][0];++ii){
              p=can[map[step+1]][ii];
              if((p|pos)==pos)
                ref(f[x][ti|p][tj|p][tk|p],f[y][i][j][k]);
            }
          }
    }
    ans=0;
    N=N&1;
    for(i=0;i<=all;++i)
      for(j=0;j<=all;++j)
        for(k=0;k<=all;++k)
          ref(ans,f[N][i][j][k]);
    ref(ans,MC-1);
    printf("Case %d%d\n",ans);
  }

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
  int T, ca = 0;
  scanf("%d",&T);
  while(T--){
    init();
    dp();
  }
  return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#define MAXN 200100
#define __Tbegin clock_t _t_=clock();
#define __Tdis std::cout<<"Time:"<<clock()-_t_<<std::endl;
char s[MAXN];
void chkmax(int& a,int b){if(a<b)a=b;}
void chkmin(int& a,int b){if(a>b)a=b;}
template<class Type>
struct cmp{
    Type* a;
    cmp(Type* _a):a(_a){};
    bool operator()(int x,int y){
        return a[x]<a[y]||a[x]==a[y]&&x<y;
    }
};
int k,n;
int sa[MAXN],rank[MAXN],orank[MAXN],height[MAXN];
bool cmpi(int a,int b){
    return rank[a]<rank[b]||rank[a]==rank[b]&&rank[a+k]<rank[b+k];
}
void SuffixArray(){
    int i;
    for(i=0;i<n;++i)sa[i]=i;
    std::sort(sa,sa+n,cmp<char>(s));
    for(rank[sa[0]]=0,i=1;i<n;++i){
        rank[sa[i]]=rank[sa[i-1]];
        if(s[sa[i]]!=s[sa[i-1]])rank[sa[i]]++;
    }
    for(k=1;rank[n-1]<n-1&&k<n;k<<=1){
        std::sort(sa,sa+n,cmpi);
        memcpy(orank,rank,n*sizeof(rank[0]));
        for(rank[sa[0]]=0,i=1;i<n;++i){
            rank[sa[i]]=rank[sa[i-1]];
            if(orank[sa[i]]!=orank[sa[i-1]]||orank[sa[i]+k]!=orank[sa[i-1]+k])
                rank[sa[i]]++;
        }
    }
}
void GetLCP(){
    int i,dt,j;
    for(i=dt=0;i<n;++i){
        if(rank[i]==n-1){
            height[rank[i]]=dt=0;
        }else{
            if(dt>0)dt--;
            for(j=sa[rank[i]+1];s[i+dt]==s[j+dt];++dt);

            height[rank[i]]=dt;
        }
    }
}
int RMQ[MAXN][18],RMQ2[MAXN][18];
int to[]={  1,2,4,8,16,
            32,64,128,256,512,
            1024,2048,4096,8192,16384,
            32768,65536,131072
        };
void init(){
    int i,k;
    for(i=0;i<n-1;++i)RMQ[i][0]=height[i];
 for(i=0;i<n;++i)RMQ2[i][0]=i;
    for(k=1;to[k]<=n-1;++k){
        for(i=0;i<n-1;++i){
            RMQ[i][k]=std::min(RMQ[i][k-1],RMQ[i+to[k-1]][k-1]);
   if(rank[RMQ2[i][k-1]]<rank[RMQ2[i+to[k-1]][k-1]])RMQ2[i][k]=RMQ2[i][k-1];
   else RMQ2[i][k]=RMQ2[i+to[k-1]][k-1];
  }
    }
}
int lcp(int s,int t){
    s=rank[s],t=rank[t];
    if(s>t){int tt=s;s=t;t=tt;}
    if(s==--t)return height[s];
    int k;
    for(k=0;to[k]<=t-s;++k);
    --k;
    return std::min(RMQ[s][k],RMQ[t-to[k]+1][k]);
}
int fcp(int s,int t){
 if(s>t){int tt=s;s=t;t=tt;}
 int k;
 for(k=0;to[k]<=t-s+1;++k);
 --k;
 if(rank[RMQ2[s][k]]<rank[RMQ2[t-to[k]+1][k]])return RMQ2[s][k];
 else return RMQ2[t-to[k]+1][k];
}
bool strcmp_(int a,int b){
    return rank[a]<rank[b];
}
int find(int s,int len,int k){

 if(s<0)s=0;
    int t=s+len;
 if(s==t)return s;
 while(s<t){
  int mid=(s+t)>>1;
  if(mid+lcp(mid,mid+len)>=k)t=mid;
  else s=mid+1;
 }
 return s;
}

int main(){

    freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
    int Cas=0,i;
    while(scanf("%s",s),s[0]!='#'){
        printf("Case %d: ",++Cas);

        n=strlen(s);
        s[n++]=0;

        SuffixArray();

        GetLCP();

        init();

        int mx=0,len,mx_i=sa[1],mx_j=1;
        for(len=1;len<n/2+1;++len){
            for(i=0;i<n-len*(mx+1);i+=len){
                int k=lcp(i,i+len);
    if(k>=len){
     int now=k/len;
     int j=i-(len-(k-now*len));
                    int bg=find(i-len+1,len,i+k);
     int mn;
                    if(lcp(bg,bg+len)>=(now+1)*len){
                        now++;
                        mn=fcp(bg,j);
                    }else mn=fcp(bg,i);
                    if(now>mx||now==mx&&strcmp_(mn,mx_i)){
      mx=now;
      mx_j=(now+1)*len;
      mx_i=mn;
       }
    }
            }
        }
        for(int i=mx_i,cont=0;cont<mx_j;++cont,++i)putchar(s[i]);
        putchar(10);
    }
    return 0;
}

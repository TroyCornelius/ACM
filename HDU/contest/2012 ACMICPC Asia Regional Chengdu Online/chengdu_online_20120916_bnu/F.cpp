#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    int a,b,k;
}data[1000];
int a[1000];
bool cmp(const node &a,const node &b){
    if(a.a!=b.a)return a.a<b.a;
    return a.b<b.b;
}
int dp[510][510];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&data[i].a,&data[i].b);
            data[i].k=n-data[i].a-data[i].b;
        }
        sort(data,data+n,cmp);
        int cur=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                cur=1;
            }else{
                if(data[i].a==data[i+1].a && data[i].b==data[i+1].b)cur++;
                else cur=1;
            }
            a[i]=cur;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++){
                if(i!=n)dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                if(j!=n)dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
                if(j+data[i].k<=n && i!=n && data[i].k>=1 && j==data[i].a){
                    dp[i+min(data[i].k,a[i])][j+data[i].k]=max(dp[i+min(data[i].k,a[i])][j+data[i].k],dp[i][j]+min(data[i].k,a[i]));
                }
            }
        int ans=0;
        for(int i=0;i<=n;i++)ans=max(ans,dp[i][n]);
        printf("%d\n",ans);
    }
    return 0;
}
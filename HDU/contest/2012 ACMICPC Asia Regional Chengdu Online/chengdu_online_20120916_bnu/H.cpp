#include<stdio.h>
#include <iostream>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int oo = 1000000000;
char str[5000];
int data[5000];
int b[4];
int c[100];
char a[100];
int dp[4100][16][64];
int main(){
    while(scanf("%s",str)!=EOF){
        int l =  strlen(str);
        memset(data,0,sizeof(data));
        memset(c,0,sizeof(c));
        for(int i=0;i<4;i++){
            scanf("%s",a);
            b[i]=strlen(a);
            for(int j=0;j<l;j++){
                int pd=1;
                for(int k=0;a[k];k++)
                    if(j+k>=l || a[k]!=str[j+k]){
                        pd=0;
                        break;
                    }
                if(pd)data[j]|=1<<i;
            }
        }
        for(int i=0;i<16;i++){
            for(int j=0;j<4;j++)
                if(i&(1<<j))c[i]=max(c[i],b[j]);
        }

        for(int i=0;i<=l;i++)
            for(int j=0;j<16;j++)
                for(int k=0;k<64;k++)dp[i][j][k]=oo;

        dp[0][0][0]=0;
        for(int i=0;i<l;i++)
            for(int j=0;j<16;j++)
                for(int k=0;k<64;k++){
                    if(dp[i][j][k]==oo)continue;
                    cout <<i <<" : " <<endl;
                    int nk =max(0,k-1);
                    dp[i+1][j][nk]=min(dp[i+1][j][nk],dp[i][j][k]);
                    int cur = 15^j;
                    cur=cur&data[i];
                    cout <<cur <<" "<<j <<"!"<<endl;
                    for(int pt=cur;pt;pt=(pt-1)&cur){
                        int tmp = max(k,c[pt])-1;
                        if(tmp<0)tmp=0;
                        dp[i+1][j|pt][tmp]=min(dp[i+1][j|pt][tmp],dp[i][j][k]+max(c[pt]-k,0));
                          //cout <<i+1 <<" " <<(j|pt) <<" "<<tmp <<" "<<dp[i+1][j|pt][tmp] <<endl;
                    }
                }
        printf("%d ",dp[l][15][0]);

        for(int i=0;i<=l;i++)
            for(int j=0;j<16;j++)
                for(int k=0;k<64;k++)dp[i][j][k]=-oo;

        dp[0][0][0]=0;
        for(int i=0;i<l;i++)
            for(int j=0;j<16;j++)
                for(int k=0;k<64;k++){
                    if(dp[i][j][k]==-oo)continue;
                    int nk =max(0,k-1);
                    dp[i+1][j][nk]=max(dp[i+1][j][nk],dp[i][j][k]);
                    int cur = 15^j;
                    cur=cur&data[i];
                    for(int pt=cur;pt;pt=(pt-1)&cur){
                        int tmp = max(k,c[pt])-1;
                        if(tmp<0)tmp=0;
                        dp[i+1][j|pt][tmp]=max(dp[i+1][j|pt][tmp],dp[i][j][k]+max(c[pt]-k,0));
                    }
                }
        printf("%d\n",dp[l][15][0]);
    }
    return 0;
}

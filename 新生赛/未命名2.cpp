#include<cstdio>
#include<algorithm>
using namespace std;
#define N 105
int a[N][N];
long long dp[N][N];
const int inf = 1<<30;
int main(){
    int T;
    int n,m,K;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&K);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){
                scanf("%d",&a[i][j]);
                dp[i][j] = -inf;
            }
        for(int i = 0;i<n;i++){
            dp[i][0] = a[i][0];
        }
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                for(int y = 0;y<n;y++){
                    for(int x = i-1;x>=0;x--){
                        if(K<(i-x)*(i-x)+(j-y)*(j-y))break;
                        dp[j][i] = max(dp[j][i],dp[y][x] + a[j][i]);
                    }
                }
            }
        }
        long long M = dp[0][m-1];
        for(int i = 1;i<n;i++)
            M = max(M,dp[i][m-1]);
        printf("%lld\n",M);
    }
}

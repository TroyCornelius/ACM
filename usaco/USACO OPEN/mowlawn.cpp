/* 
PROG: mowlawn
LANG: C++
ID: hacker_ja3
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a > b ? b : a)
#define clr(x,a) memset(x, a ,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; i++ )
#define fro(j,a,b) for(int j = a; j > b ; j--)
#define LL long long
#define maxn 100100
int data[maxn];
long long  dp[maxn];
long long dp2[maxn];
int queue[maxn];
long long G[maxn];
using namespace std;
int n,k;
long long DP(){
	int left  =0,right =1;
	dp[0] =0;
	dp2[0] =0;
	queue[0] = 0;
	fr(i,1,n+1){
		if(i-left>k)left++;
		dp[i] =G[i] - G[queue[left]] +dp2[queue[left]];
		dp2[i] = max(dp[i-1],dp2[i-1]);
		while(left<right){
			if(dp2[i]>dp2[queue[right-1]]+G[i]-G[queue[right-1]])right--;
			else break;
		}
		queue[right++] = i;
	}
	return dp[n]>dp2[n]?dp[n] : dp2[n];
}
int main(){
    freopen("mowlawn.in", "r", stdin);
    freopen("mowlawn.out", "w", stdout);
	while(cin>>n>>k){
		G[0] =0;
		fr(i,1,n+1){
			scanf("%d",&data[i]);
			G[i]+=( G[i-1]+data[i]);
		}
		cout<<DP()<<endl;
	}
	return 0;
}

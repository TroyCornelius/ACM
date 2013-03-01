#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define inf 1<<30

int n,d;
int a[105];

int solve_dfs(int now) {
	if (now==n) {
		for (int i=max(n-d,0); i<n; i++) if (a[i]==1) return inf;
		return 0;
	}
	int ans=inf;
	if (now-d<0 || a[now-d]==0) ans=min(ans,solve_dfs(now+1));
	if (now-d<0 || a[now-d]==1) {
		for (int i=max(now-d,0); i<=min(now+d,n-1); i++) a[i]=!a[i];
		ans=min(ans,solve_dfs(now+1)+1);
		for (int i=max(now-d,0); i<=min(now+d,n-1); i++) a[i]=!a[i];
	}
	
	return ans;
}

int main() 
{
	int T;
	scanf("%d",&T);
	while(T--){
       scanf("%d%d",&n,&d);
	   for (int i=0; i<n; i++) scanf("%d",&a[i]);
	   int ans;
       ans=solve_dfs(0);
	   if (ans<=n) printf("%d\n",ans);
	   else printf("impossible\n");        
    } 
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn=1003;
char mp[maxn][maxn];
int rit[maxn],lef[maxn];
int h[maxn][maxn];

int n,m;

int get1(){
	int tmp,mx,i,j,k;
	mx=0;
	for(j=1;j<=m;j++)
		h[0][j]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(mp[i][j]=='B') h[i][j]=h[i-1][j]+1;
			else h[i][j]=0;
			rit[j]=lef[j]=j;
		}
		rit[m+1]=m+1;
		lef[0]=0;
		for(j=1;j<=m;j++)
			while(h[i][j]<=h[i][lef[j]-1])
				lef[j]=lef[j]-1;
		for(j=m;j>=1;j--)
			while(h[i][j]<=h[i][rit[j]+1])
				rit[j]=rit[j]+1;
		for(j=1;j<=m;j++){
			if(rit[j]-lef[j]+1==0 || h[i][j]==0) continue;
			tmp=(rit[j]-lef[j]+1+h[i][j])<<1;
			if(tmp>mx) mx=tmp;
		}
	}
	return mx;
}

int get2(){
	int tmp,mx,i,j,k;
	mx=0;
	for(j=1;j<=m;j++)
		h[0][j]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(mp[i][j]=='R') h[i][j]=h[i-1][j]+1;
			else h[i][j]=0;
			rit[j]=lef[j]=j;
		}
		rit[m+1]=m+1;
		lef[0]=0;
		for(j=1;j<=m;j++)
			while(h[i][j]<=h[i][lef[j]-1])
				lef[j]=lef[j]-1;
		for(j=m;j>=1;j--)
			while(h[i][j]<=h[i][rit[j]+1])
				rit[j]=rit[j]+1;
		for(j=1;j<=m;j++){
			if(rit[j]-lef[j]+1==0 || h[i][j]==0) continue;
			tmp=(rit[j]-lef[j]+1+h[i][j])<<1;
			if(tmp>mx) mx=tmp;
		}
	}
	return mx;
}

int get3(){
	int tmp,mx,i,j,k;
	mx=0;
	for(j=1;j<=m;j++)
		h[0][j]=0,mp[0][j]='N';
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(mp[i][j]==mp[i-1][j]) h[i][j]=1;
			else h[i][j]=h[i-1][j]+1;
			rit[j]=lef[j]=j;
		}
		rit[m+1]=m+1;
		lef[0]=0;
		mp[i][0]=mp[i][m+1]='N';
		for(j=1;j<=m;j++)
			while(h[i][j]<=h[i][lef[j]-1] && mp[i][lef[j]]!=mp[i][lef[j]-1])
				lef[j]=lef[j]-1;
		for(j=m;j>=1;j--)
			while(h[i][j]<=h[i][rit[j]+1] && mp[i][rit[j]]!=mp[i][rit[j]+1])
				rit[j]=rit[j]+1;
		for(j=1;j<=m;j++){
			tmp=min(rit[j]-lef[j]+1,h[i][j]);
			tmp<<=2;
			if(tmp>mx) mx=tmp;
		}
	}
	return mx;
}

int main(){
	int tt,t;
	int i,mx,tmp1,tmp2,tmp3;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			h[i][0]=h[i][m+1]=-1;	
		}
		tmp1=get1();
		tmp2=get2();
		tmp3=get3();
		mx=0;
		mx=max(tmp1,mx);
		mx=max(tmp2,mx);
		mx=max(tmp3,mx);
	//	cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
		printf("Case #%d: %d\n",tt,mx);
	}
	return 0;
}


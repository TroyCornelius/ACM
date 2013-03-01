#include<cstdio>
#include<cassert>
#define MAXA 5000000
#define MAXN 100000
int w[MAXA+1],a[MAXN];
inline void prepare(){
	int i,j;
	for(i=2;i<=MAXA;++i)
		if(!w[i])
			for(j=i*2;j<=MAXA;j+=i)w[j]=i;
	w[1]=0;
	for(i=2;i<=MAXA;++i)
		if(!w[i])w[i]=1;
		else	w[i]=w[i/w[i]]+1;
}
int main() {
	int n,i,T=0,xsum;
	prepare();
	while(scanf("%d",&n)==1){
		assert(1 <= n && n <= 100000);
		xsum=0;
		for(i=0;i<n;++i){
			scanf("%d",a+i);
			assert(0 < a[i] && a[i] <= 5000000);
			a[i]=w[a[i]];
			xsum^=a[i];
		}
		printf("Test #%d: ",++T);
		if(xsum){
			printf("Alice ");
			for(i=0;i<n;++i)
				if((xsum ^a[i])<a[i]){
					printf("%d\n",1+i);
					break;
				}
		}else{
			printf("Bob\n");
		}
	}
	return 0;
}

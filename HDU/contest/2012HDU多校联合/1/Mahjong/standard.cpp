#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int x,y;
    node(){}
    node(int p,int q):x(p),y(q){}
};
struct edge{
	int k,next,pre;
};
edge e[1800000];
int a[310][310],b[310][310];
int first[200003],z[200003],low[200003];
int now[200003],id[200003],dfn[200003];
bool bi[200003],flag[200003];
int t1[100003],t2[100003],rank[100003];
int f1[100003],f2[100003];
node pos1[100003][2],pos2[100003][2];
vector<int> may[310][310];
int n,m,vertex,sum,nn,mm;
int CA,CB;

void addedge(int p,int q){
//    printf("--%d %d\n",p,q);
	e[++nn].k=q;
	e[nn].next=first[p];
	first[p]=nn;
}

void dfs(int k){
	bi[k]=false;
	z[++z[0]]=k;
	flag[k]=true;
	low[k]=now[k]=(++mm);
	for (int i=first[k];i;i=e[i].next){
		if (bi[e[i].k]) dfs(e[i].k);
		if (flag[e[i].k]) low[k]=min(low[k],low[e[i].k]);
	}
	if (low[k]==now[k]){
		++sum;
		z[z[0]+1]=1999999;
		while (z[z[0]+1]!=k){ 
			flag[z[z[0]]]=false;
			id[z[z[0]--]]=sum;
		}
	}
}	 

bool check0(){
    sort(t1+1,t1+n*n+1);
    sort(t2+1,t2+n*n+1);
    rank[0]=0;
    t1[0]=-1;
    for (int i=1;i<=n*n;++i)
        if (t1[i]!=t1[i-1]) rank[t1[i]]=(++rank[0]);
    for (int i=1;i<=n*n;++i)
        if (t1[i]!=t2[i]) return true;
    return false;
}

bool check1(){
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j) t1[j]=a[i][j];
        for (int j=1;j<=n;++j) t2[j]=b[i][j];
        sort(t1+1,t1+n+1);
        sort(t2+1,t2+n+1);
        for (int j=1;j<=n;++j)
            if (t1[j]!=t2[j]) return false;
    }
    return true;
}

bool check2(){
    memset(first,0,sizeof(first));
  	memset(bi,true,sizeof(bi));
    memset(flag,false,sizeof(flag));
    nn=mm=sum=vertex=z[0]=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) 
            may[i][j].clear();
        
    node p1;
    for (int i=1;i<=n*n;++i)
        if (f1[i]==1){
            may[pos1[i][0].x][pos2[i][0].y].push_back(rank[i]*2+1);
            may[pos1[i][0].x][pos2[i][0].y].push_back(rank[i]*2);
        }else
        if (f1[i]==2){
            may[pos1[i][0].x][pos2[i][0].y].push_back(rank[i]*2+1);
            may[pos1[i][1].x][pos2[i][1].y].push_back(rank[i]*2+1);
            may[pos1[i][0].x][pos2[i][1].y].push_back(rank[i]*2);
            may[pos1[i][1].x][pos2[i][0].y].push_back(rank[i]*2);
        }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int p=0;p<may[i][j].size();++p)
                for (int q=p+1;q<may[i][j].size();++q){
                    if ((may[i][j][p]^1)==may[i][j][q]) continue;
                    addedge(may[i][j][p],may[i][j][q]^1);
                    addedge(may[i][j][q],may[i][j][p]^1);
                }
    for (int i=2;i<=rank[0]*2+1;++i)
        if (bi[i]) dfs(i);
    for (int i=1;i<=rank[0];++i)
        if (id[i*2]==id[i*2+1]) return false;
    return true;
}

void change(){
    for (int i=1;i<n;++i)
        for (int j=i+1;j<=n;++j){
            swap(a[i][j],a[j][i]);
            swap(b[i][j],b[j][i]);
        }
}

void pre(){
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j){
            pos1[a[i][j]][f1[a[i][j]]++]=node(i,j);
            pos2[b[i][j]][f2[b[i][j]]++]=node(i,j);
        }
}       

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

    int _,cas=0;
    scanf("%d",&_);
    while (_--){
        bool ans0=true;
        scanf("%d%d%d",&n,&CA,&CB);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j){
                scanf("%d",&a[i][j]);
                t1[(i-1)*n+j]=a[i][j];
            }

        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j){
                scanf("%d",&b[i][j]);
                t2[(i-1)*n+j]=b[i][j];
                if (a[i][j]!=b[i][j]) ans0=false;
            }
        
        if (ans0){
            printf("Case #%d: %d\n",++cas,0);
            continue;
        }
        
        if (check0()){
            printf("Case #%d: Take off the shoes!\n",++cas);
            continue;
        }
        
        int ans=min(CA*2+CB,CB*2+CA);
        
        if (check1()) ans=min(ans,CA);
        change();
        if (check1()) ans=min(ans,CB);

        change();
        pre();
        if (check2()) ans=min(ans,CA+CB);
        else{
            change();
            pre();
            if (check2()) ans=min(ans,CA+CB);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
      

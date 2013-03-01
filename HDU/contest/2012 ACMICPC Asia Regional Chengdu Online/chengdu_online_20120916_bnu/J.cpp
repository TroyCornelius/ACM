#pragma comment(linker, "/STACK:102400000,102400000")
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
vector<int>adj[500010];
int mark[500010];
int hash[500010];
int stack[500010];
int sf[500010];
int fc[500010];
int id[500010];
int depth[500010];
int lenc[500010];
int fa[500010][20];
int __=1;
int top;
int num;
void dfs(int k){
    stack[top++]=k;
    mark[k]=__;
    if(k==fa[k][0]){
        hash[k]=1;
        return;
    }
    if(mark[fa[k][0]]==__){
        num++;
        int sum=1;

       // printf("======%d %d\n",num,fa[k][0]);
        while(stack[top-1]!=fa[k][0]){
            //printf("======%d %d\n",num,stack[top-1]);
            hash[stack[top-1]]=1;
            fc[stack[top-1]]=num;
            id[stack[top-1]]=sum;
            sum++;
            top--;
        }
        id[fa[k][0]]=sum;
        hash[fa[k][0]]=1;
        fc[fa[k][0]]=num;
        lenc[num]=sum;
        return;
    }
    if(mark[fa[k][0]])return;
    dfs(fa[k][0]);
}
void dfs(int u,int deep,int fa){
    depth[u]=deep;
    sf[u]=fa;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(hash[v])continue;
        dfs(v,deep+1,fa);
    }
}
int jump(int k,int len){
    for(int i=19;i>=0 && len;i--){
        if((1<<i)<=len){
            k=fa[k][i];
            len-=(1<<i);
        }
    }
    return k;
}
int f(int x,int y,int len){
    if(x<=y)return y-x;
    return y+len-x;
}
int main(){
    int n,q;

    while(scanf("%d%d",&n,&q)!=EOF){
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&fa[i][0]);
            adj[fa[i][0]].push_back(i);
        }


        memset(mark,0,sizeof(mark));
        memset(hash,0,sizeof(hash));
        memset(sf,0,sizeof(sf));
        memset(fc,0,sizeof(fc));
        num=0;
        for(int i=1;i<=n;i++){
            if(mark[i]==0){
                __++;
                top=0;
                dfs(i);
            }
        }
        for(int i=1;i<=n;i++)
            if(hash[i]){
                fa[i][0]=i;
                dfs(i,0,i);
            }

        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                fa[j][i]=fa[fa[j][i-1]][i-1];

        while(q--){
            int s,t;
            scanf("%d%d",&s,&t);
            int a=0,b=0;
            if(sf[s]!=sf[t]){

                int fs = jump(s,depth[s]);
                int ft = jump(t,depth[t]);
                //printf("~~~%d %d\n",fs,ft);
                a=depth[s];
                b=depth[t];
                if(fc[fs]!=fc[ft] || fc[fs]==0)printf("-1 -1\n");
                else{
                    int len = lenc[fc[fs]];
                    int x=id[fs]-1,y=id[ft]-1;
                    //printf("[%d %d]~~~~%d %d %d %d %d == %d %d\n",fc[fs],fc[ft],fs,ft,x,y,len,a,b);
                    swap(x,y);
                    //printf("aaaaaa");
                    //printf("~~~~~%d\n",f(y,x,len));
                    int x0=a,y0=b+f(y,x,len);
                    int x1=a+f(x,y,len),y1=b;
                    //printf("%d %d %d %d\n",x0,y0,x1,y1);
                    if(max(x0,y0)>max(x1,y1))printf("%d %d\n",x1,y1);
                    else if(max(x0,y0)<max(x1,y1))printf("%d %d\n",x0,y0);
                    else {
                        if(x0+y0<x1+y1)printf("%d %d\n",x0,y0);
                        else if(x0+y0>x1+y1)printf("%d %d\n",x1,y1);
                        else printf("%d %d\n",max(x0,y0),min(x0,y0));
                    }
                }
            }else{
                //printf("===%d %d %d\n",depth[s],depth[t],fa[s][2]);
                int a=0,b=0;
                if(depth[s]>depth[t]){
                    a = depth[s]-depth[t];
                    s=jump(s,depth[s]-depth[t]);
                }else{
                    b = depth[t]-depth[s];
                    t=jump(t,depth[t]-depth[s]);
                }
                //printf("~~~%d %d\n",s,t);
                int ret=0;
                for(int i=19;i>=0;i--)
                    if(fa[s][i]!=fa[t][i]){
                        ret+=(1<<i);
                        s=fa[s][i];
                        t=fa[t][i];
                    }
                while(s!=t){
                    s=fa[s][0];
                    t=fa[t][0];
                    ret++;
                }
                printf("%d %d\n",a+ret,b+ret);
            }
        }
    }
    return 0;
}
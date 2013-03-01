#include <cstdio>
#include <iostream>
#include <cstring>
#define SIZE 1000000
#define HASH 100007
#define MAXD 15
#define mod 1000000007
typedef long long LL;
using namespace std;
int maze[MAXD][MAXD],code[MAXD],ch[MAXD],N,M,K;
char b[MAXD];
struct Hashmap
{
    LL state[SIZE];
    int f[SIZE];
    int size,head[HASH],next[SIZE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(LL st,int ans)
    {
        int h=st%HASH;
        for(int i=head[h];i!=-1;i=next[i])
            if(state[i]==st)
            {
                f[i]+=ans;
                f[i]%=mod;
                return;
            }
        state[size]=st;
        f[size]=ans;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];
int c;
void decode(int *code,int m,LL st) {
    c=st&63;
    st>>=6;
    for(int i=m;i>=0;i--) {
        code[i]=st&7;
        st>>=3;
    }
}
LL encode(int *code ,int m) {
    LL res=0;
    int cnt=1;
    memset(ch,-1,sizeof(ch));
    ch[0]=0;
    for(int i=0;i<=m;i++) {
        if(ch[code[i]]==-1)
            ch[code[i]]=cnt++;
        code[i]=ch[code[i]];
        res<<=3;
        res|=code[i];
    }
    res<<=6;
    res|=c;
    return res;
}
void dpblank(int i,int j,int now,int pre) {
    int left,up,t,l;
    for(int k=0;k<hm[pre].size;k++) {
        decode(code,M,hm[pre].state[k]);
        left=code[j-1],up=code[j];
        if(left && up) {
            if(left==up) {
                if(c>=K)continue;
                l=0;
                for(t=0;t<j-1;t++)
                    if(code[t])l++;
                if(l&1)continue;
                code[j-1]=code[j]=0;
                c++;
                hm[now].push(encode(code,j==M?M-1:M),hm[pre].f[k]);
            }else {
                code[j-1]=code[j]=0;
                for(t=0;t<=M;t++)
                    if(code[t]==up)
                        code[t]=left;
                hm[now].push(encode(code,j==M?M-1:M),hm[pre].f[k]);
            }
        }else if(left || up)
        {
            if(left)t=left;
            else t=up;
            if(maze[i][j+1]) {
                code[j-1]=0,code[j]=t;
                hm[now].push(encode(code,j==M?M-1:M),hm[pre].f[k]);
            }
            if(maze[i+1][j]) {
                code[j-1]=t,code[j]=0;
                hm[now].push(encode(code,j==M?M-1:M),hm[pre].f[k]);
            }
        }else
        {
            if(c>=K)continue;
            if(maze[i+1][j] && maze[i][j+1]) {
                code[j-1]=code[j]=13;
                hm[now].push(encode(code,j==M?M-1:M),hm[pre].f[k]);
            }
        }
    }
}
void dpblock(int i,int j,int now,int pre) {
    for(int k=0;k<hm[pre].size;k++) {
        decode(code,M,hm[pre].state[k]);
        code[j-1]=code[j]=0;
        hm[now].push(encode(code,j==M?M-1:M),hm[pre].f[k]);
    }
}
void solve() {
    int now=1,pre=0;
    hm[now].init();
    hm[now].push(0,1);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++) {
            swap(now,pre);
            hm[now].init();
            if(maze[i][j])dpblank(i,j,now,pre);
            else dpblock(i,j,now,pre);
        }
    int ans=0;
    for(int i=0;i<hm[now].size;i++) {
        if(hm[now].state[i]==K)
            ans=hm[now].f[i];
    }
    printf("%d\n",ans);
}
void input() {
    scanf("%d %d %d",&N,&M,&K);
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=N;i++) {
        scanf("%s",b+1);
        for(int j=1;j<=M;j++)
            if(b[j]=='.')maze[i][j]=1;
    }
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        input();
        solve();
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max 20010
#define Hash 3007
int n,m,ex,ey,cur,mp[15][15],a1,a2,a3,b1,b2,b3,ans;
int stack[15],f[15];
char str[15];
struct node{    
    int size,next[Max],p[Hash],state[Max];    
    int f[Max];    inline void init()    {      
        memset(p,-1,sizeof(p));        size=0;  
    }   
    inline void push(int st,int val)    {   
        int i,u=st%Hash;     
        for(i=p[u];i!=-1;i=next[i])     
        {         
            if(state[i]==st)       
            {       
                if(f[i]<val) f[i]=val;    
                return;        
            }     
        }     
        state[size]=st;f[size]=val;  
        next[size]=p[u];    
        p[u]=size++;   
    }
}dp[2];
inline void decode(int st){   
    int top=0;    for(int i=0;i<=m;i++)  
    {        if((st&3)==1)    
        stack[top++]=i;     
        else if((st&3)==2)    
        {            
            f[stack[top-1]]=i;      
            f[i]=stack[top-1];          
            top--;    
        }       
        st>>=2;    
    }
}
inline void shift(){   
    for(int k=0;k<dp[cur].size;k++)       
        dp[cur^1].push((dp[cur].state[k]<<2),dp[cur].f[k]);
}
inline void dpblank(int i,int j){   
    int k,left,up;  
    for(k=0;k<dp[cur].size;k++)  
    {     
        int st=dp[cur].state[k];  
        int tmp=dp[cur].f[k]+mp[i][j];     
        left=st&a3;up=st&b3;      
        if(left&&up)       
        {         
            decode(st);     
            if(left==a2&&up==b1)           
                dp[cur^1].push(st^left^up,tmp);        
            else if(left==a1&&up==b1)               
               
                dp[cur^1].push(st^left^up^(3<<(2*f[j])),tmp);       
            else if(left==a2&&up==b2)               
                dp[cur^1].push(st^left^up^(3<<(2*f[j-1])),tmp);            
            else if(left==a3&&up==b3)           
            {              
                if((st^left^up)==0&&ans<tmp) ans=tmp;           
            }            else if(left==a3)          
                dp[cur^1].push((st^left^up)|(3<<(2*f[j])),tmp);           
            else if(up==b3)             
                dp[cur^1].push((st^left^up)|(3<<(2*f[j-1])),tmp);      
        }      
        else if(left)   
        {          
            if(mp[i][j+1])     
                dp[cur^1].push((st^left)|(left<<2),tmp);      
            if(mp[i+1][j])            
                dp[cur^1].push(st,tmp);         
            if(left!=a3)            {                decode(st);                dp[cur^1].push((st^left^up)|(3<<(2*f[j-1])),tmp);            }            if(left==a3)            {                if((st^left^up)==0&&ans<tmp) ans=tmp;            }        }        else if(up)        {            if(mp[i][j+1])                dp[cur^1].push(st,tmp);            if(mp[i+1][j])                dp[cur^1].push((st^up)|(up>>2),tmp);            if(up!=b3)            {                decode(st);                dp[cur^1].push((st^left^up)|(3<<(2*f[j])),tmp);            }            if(up==b3)            {                if((st^left^up)==0&&ans<tmp) ans=tmp;            }        }        else        {            dp[cur^1].push(st^left^up,dp[cur].f[k]);            if(mp[i][j+1]&&mp[i+1][j])                dp[cur^1].push(st|a1|b2,tmp);            if(mp[i][j+1])                dp[cur^1].push((st|b3),tmp);            if(mp[i+1][j])                dp[cur^1].push((st|a3),tmp);        }    }}inline void solve(){    int i,j;    cur=0;    dp[0].init();    dp[0].push(0,0);    for(i=1;i<=n;i++)    {        dp[cur^1].init();        shift();        cur^=1;        b1=1;b2=2;        for(j=1;j<=m;j++)        {            a1=b1;a2=b2;a3=a1|a2;            b1<<=2;b2<<=2;b3=b1|b2;            if(mp[i][j])            {                dp[cur^1].init();                dpblank(i,j);                cur^=1;            }        }    }    printf("%d\n",ans);}int main(){    int i,j,t;   //freopen("D:/out2.txt","w",stdout);    scanf("%d",&t);    while(t--)    {        ans=0;        scanf("%d%d",&n,&m);        memset(mp,0,sizeof(mp));        for(i=1;i<=n;i++)           for(j=1;j<=m;j++)           {                scanf("%d",&mp[i][j]);                if(ans<mp[i][j]) ans=mp[i][j];           }        solve();    }    return 0;}



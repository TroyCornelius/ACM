#include<cstdio>
#include<cstring>

const int MAXN = 32768;//最接近30000的2^n

/*
    a b
    c d
*/
struct Ma{ int a,b,c,d; }x[(MAXN<<1)+1];

int R,N,M;

inline int LC(int i){return i<<1;}
inline int RC(int i){return LC(i)^1;}

void product(Ma &ret,Ma A,Ma B)
{
    ret.a = (A.a*B.a+A.b*B.c)%R;
    ret.b = (A.a*B.b+A.b*B.d)%R;
    ret.c = (A.c*B.a+A.d*B.c)%R;
    ret.d = (A.c*B.b+A.d*B.d)%R;
}
Ma query(int p,int left,int right,int l,int r)
{
    if(left==l&&right==r)return x[p];
    int mid = (left+right)>>1;
    if(r<=mid)return query(LC(p),left,mid,l,r);
    else if(l>mid)return query(RC(p),mid+1,right,l,r);
    Ma ret;
    product(ret,query(LC(p),left,mid,l,mid),query(RC(p),mid+1,right,mid+1,r));
    return ret;
}
int main()
{
    //freopen("in","r",stdin);
    bool blank = 0;
    while(~scanf("%d%d%d",&R,&N,&M))
    {
        int S = 1;
        while(S<N)S<<=1;//n<=S = 2^k
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d%d",&x[S+i].a,&x[S+i].b,&x[S+i].c,&x[S+i].d);//read in S+i
        }
        //build  画一下完全二叉树就知道了
        for(int i=S-1;i;i--)
        {
            product(x[i],x[LC(i)],x[RC(i)]);
        }
        while(M--)
        {
            if(blank)puts("");
            else blank = 1;
            int a,b;
            scanf("%d%d",&a,&b);
            Ma ret = query(1,1,S,a,b);
            printf("%d %d\n%d %d\n",ret.a,ret.b,ret.c,ret.d);
        }
    }
    return 0;
}

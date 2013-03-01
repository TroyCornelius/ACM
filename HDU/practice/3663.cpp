#include<cstdio>
#include<algorithm>
using namespace std;
#include<cstdlib>
#include<cstring>
 
bool mm[60][60];
int dd[60][2];
int q[16][2],top;
 
#define MAX 0x7fffffff
#define MAXR 4000
#define MAXC 700
bool arr[MAXR][MAXC];
#define SIZE MAXR*MAXC
int L[SIZE], R[SIZE], U[SIZE], D[SIZE],
    Col[SIZE], Row[SIZE];//所在列 所在行
int S[MAXC]; //列元素数
int sel[MAXR],seln;//选择的行
 
struct Dancer
{
    void init(int height,int width)
    {
        int p, x, y, last;
        for (p = 1; p <= width; p++)
        {
            L[p] = p - 1; R[p] = p + 1;
            U[p] = D[p] = p;
            S[p] = 0;
        }
        p = width + 1;
        for (y = 1; y <= height; y++)
        {
            last = R[0] = L[0] = 0;
            for (x = 1; x <= width; x++)
            {
                if (arr[y][x] != 0)
                {
                    L[p] = last; R[last] = p;
                    U[p] = U[x]; D[p] = x; U[x] = D[U[x]] = p;
                    Row[p]=y; Col[p]=x;
  
                    S[x]++; last=p++;
                }
            }
            R[last] = R[0]; L[R[0]] = last;
        }
        R[width] = 0; L[0] = width; R[0] = 1;
        S[0] = MAX;
    }
   
    void remove(const int &c)
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i])
            for (int j = R[i]; j != i; j = R[j])
            {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }
   
    void resume(const int &c)
    {
        for (int i = U[c]; i != c; i = U[i])
            for (int j = L[i]; j != i; j = L[j])
            {
                U[D[j]] = j;
                D[U[j]] = j;
                ++S[Col[j]];
            }
        L[R[c]] = c; R[L[c]] = c;
    }
   
    bool dance()
    {
        if (R[0] == 0) return true;
        int c=0, i, j;
        for (i = R[0]; i != 0; i = R[i])
            if (S[i] < S[c]) c = i;
        remove(c);
        for (i = D[c]; i != c; i = D[i])
        {
            for (j = R[i]; j != i; j = R[j])
                remove(Col[j]);
            sel[seln]=Row[i];
            seln++;
            if (dance()) return true;
            seln--;
            for (j = L[i]; j != i; j = L[j])
                resume(Col[j]);
        }
        resume(c); return false;
    }
} dc;
/////////////////////////////////////////////////////////////
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    int n,m,d;
    while(scanf("%d%d%d",&n,&m,&d)!=EOF)
    {
        //all internals
        top=1;
        for(int i=1;i<=5;i++) for(int j=i;j<=5;j++)
            q[top][0]=i,q[top++][1]=j;
         
        memset(mm,false,sizeof(mm));
        for(int i=0;i<n;i++) mm[i][i]=1;
        for(int i=0;i<m;i++)
        {
            int a,b; scanf("%d%d",&a,&b);
            a--;b--;
            mm[a][b]=mm[b][a]=1;
        }
         
        for(int i=0;i<n;i++)
            scanf("%d%d",&dd[i][0],&dd[i][1]);
        //转化
        memset(arr,false,sizeof(arr));
        for(int i=0;i<n;i++)//each power station
        {
            for(int k=0;k<top;k++)//each internal
            {
                int r=i*top+k+1;//station i work on internal k
                arr[r][n*d+i+1]=1;//station collision
                int d1=q[k][0],d2=q[k][1];
                if(k==0) continue;//not work
                if(d1<dd[i][0] || d2>dd[i][1])//bad date
                    continue;
                for(int j=0;j<n;j++) if(mm[i][j])//each city
                    for(int di=d1;di<=d2;di++)
                    {
                        int c=j*d+di;
                        arr[r][c]=1;//soga
                    }
            }
        }
        //dance
        seln=0; dc.init(n*top,n*d+n);
        if(!dc.dance())
            puts("No solution");
        else
        {
            for(int i=0;i<seln;i++)//get data from line number
            {
                int s=(sel[i]-1)/top;//station
                int k=(sel[i]-1)%top;
                dd[s][0]=q[k][0]; dd[s][1]=q[k][1];//record
            }
            for(int i=0;i<n;i++)
                printf("%d %d\n",dd[i][0],dd[i][1]);
        }
        putchar('\n');
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int xia(char cc[8][10])
{
    bool bo[8][8];
    memset(bo,0,sizeof(bo));
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(i+2<8 && cc[i][j]!='5' && cc[i][j]==cc[i+1][j] && cc[i][j]==cc[i+2][j])
                bo[i][j]=bo[i+1][j]=bo[i+2][j]=true;
            if(j+2<8 && cc[i][j]!='5' && cc[i][j]==cc[i][j+1] && cc[i][j]==cc[i][j+2])
                bo[i][j]=bo[i][j+1]=bo[i][j+2]=true;
        }
    int ret=0.0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(bo[i][j])
            {
                cc[i][j]='5';
                ret++;
            }

    for(int j=0;j<8;j++)
        for(int i=7;i>=0;i--)
        {
            if(cc[i][j]=='5')
            {
                for(int k=i-1;k>=0;k--)
                {
                    if(cc[k][j]!='5')
                    {
                        swap(cc[k][j],cc[i][j]);
                        break;
                    }
                }
            }
        }
    return ret;
}
int xiaya(char  cc[8][10])
{
    int ret=0;
    for(;;)
    {
        int a=xia(cc);
        if(a==0)
            break;
        ret+=a;
    }
    return ret;
}
double gao(char ci[8][10],int a)
{
    char cc[8][10];
        for(int i=0;i<8;i++)
            for(int j=0;j<10;j++)
                cc[i][j]=ci[i][j];
/*
    cout<<"hehe "<<a<<endl;
    for(int i=0;i<8;i++)
        printf("%s\n",cc[i]);
    getchar();
*/
    int b=xia(cc);
/*
    cout<<"xiaya "<<b<<endl;
    for(int i=0;i<8;i++)
        printf("%s\n",cc[i]);
*/
    if(b>=a)
        return 1.0;
    a-=b;
    if(b==0)
        return 0.0;
    vector< pair <int,int> > pi;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(cc[i][j]=='5')
                pi.push_back( make_pair(i,j));
    int zz=pow(5,pi.size());
    double fm=zz;
    double ret=0;
    for(int t=0;t<zz;t++)
    {
        vector <int> vi;
        int p=t;
        for(int i=0;i<pi.size();i++)
        {
            cc[pi[i].first][pi[i].second]=p%5+'0';
            p/=5;
        }
        ret+=gao(cc,a);
    }
    ret/=fm;
    return ret;
}
char cd[8][10];

bool ju()
{
    char cc[8][10];
        for(int i=0;i<8;i++)
            for(int j=0;j<10;j++)
                cc[i][j]=cd[i][j];
    if(xiaya(cc)>=8)
        return true;
    return false;
}
int main()
{
    freopen("8mul8.in","r",stdin);
    freopen("8mul8.out","w",stdout);
    int z;
    scanf("%d",&z);
    for(int y=1;y<=z;y++)
    {
        for(int i=0;i<8;i++)
            scanf("%s",cd[i]);
        double ans=0;
        bool fast=false;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                double  tm;
                if(i!=7)
                {
                    swap(cd[i][j],cd[i+1][j]);
                    if(ju())
                    {
                        fast=true;
                        goto n1;
                    }
                    swap(cd[i][j],cd[i+1][j]);
                }
                if(j!=7)
                {
                    swap(cd[i][j],cd[i][j+1]);
                    if(ju())
                    {
                        fast=true;
                        goto n1;
                    }
                    swap(cd[i][j],cd[i][j+1]);
                }
            }
        n1:
        if(fast)
        {
            printf("Case #%d: %.3f\n",y,1.0);
            continue;
        }
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                double  tm;
                if(i!=7)
                {
                    swap(cd[i][j],cd[i+1][j]);
                     tm=gao(cd,8);
                    ans=max(ans,tm);
                    swap(cd[i][j],cd[i+1][j]);
                }
                if(j!=7)
                {
                    swap(cd[i][j],cd[i][j+1]);
                    tm=gao(cd,8);
                    ans=max(ans,tm);;
                    swap(cd[i][j],cd[i][j+1]);
                }
                if(ans>1.0-1e-8)
                    goto o1;
            }
        o1:
        printf("Case #%d: %.3f\n",y,ans);
    }
    return 0;
}

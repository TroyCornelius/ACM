#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char use[10][10];
inline int fd(char uu[][10])
{
    int ret=0;
    int mark[10][10];
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
        mark[i][j]=0;
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
    {
        if(uu[i][j]=='x')continue;

        int i1=i,i2=i,j1=j,j2=j;
        while(i1>=0&&uu[i1][j]==uu[i][j])i1--;
        while(i2<8&&uu[i2][j]==uu[i][j])i2++;
        while(j1>=0&&uu[i][j1]==uu[i][j])j1--;
        while(j2<8&&uu[i][j2]==uu[i][j])j2++;
        i1++;i2--;j1++;j2--;
        if(i2-i1>=2)for(int w=i1;w<=i2;w++)mark[w][j]=1;
        if(j2-j1>=2)for(int w=j1;w<=j2;w++)mark[i][w]=1;
    }
    for(int j=0;j<8;j++)
    {
        int now=7;
        for(int i=7;i>=0;i--)
        {
            while(now>=0&&mark[now][j]==1)now--;
            if(now>=0)
            {
                uu[i][j]=uu[now][j];
                now--;
            }
            else
            {
                uu[i][j]='x';
                ret++;
            }
        }
    }
    return ret;
}
double fun(int need,int lost,char uu[][10])
{
    if(need<=0)return 1.0;
    if(lost>0)
    {
        double ret=0;
        int i=0;
        while(uu[i/8][i%8]!='x')i++;
        int j=i%8;
        i/=8;
        for(int w=0;w<5;w++)
        {
            uu[i][j]=w+'0';
            //if(fnd(i,j,uu)>=need)return 1.0;
            double cc=fun(need,lost-1,uu);
            ret+=cc/5.0;
        }
        uu[i][j]='x';
        return ret;
    }
    else
    {
        char uc[10][10];
        for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            uc[i][j]=uu[i][j];
        int how=fd(uc);
        if(how==0)return 0.0;
        return fun(need-how,how,uc);
    }
}

int main()
{
    freopen("8mul8.in","r",stdin);
    freopen("8mul7.out","w",stdout);
    int ti;
    scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        double ret=0;
        for(int i=0;i<8;i++)
            scanf("%s",use[i]);
        for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            double rr=0;

            char tmp;
            if(i+1<8)
            {
                tmp=use[i][j];
                use[i][j]=use[i+1][j];
                use[i+1][j]=tmp;

                rr=fun(8,0,use);

                tmp=use[i][j];
                use[i][j]=use[i+1][j];
                use[i+1][j]=tmp;

                if(ret<rr)ret=rr;
                if(ret>1.0-1e-8)break;
//if(ca==3)cout<<i<<" "<<j<<" "<<rr<<endl;
            }
//if(ca==4) return 0;
            if(j+1<8)
            {
                tmp=use[i][j];
                use[i][j]=use[i][j+1];
                use[i][j+1]=tmp;

                rr=fun(8,0,use);

                tmp=use[i][j];
                use[i][j]=use[i][j+1];
                use[i][j+1]=tmp;

                if(ret<rr)ret=rr;
                if(ret>1.0-1e-8)break;
//if(ca==3)cout<<i<<" "<<j<<" "<<rr<<endl;
            }
        }
        printf("Case #%d: %.3f\n",ca,ret);
    }
}

/*
00234012
34012340
12340123
40123401
23401234
01234012
34012340
12340123
1
00112233
44001122
33440011
22334400
11223344
00112233
44001122
33440011

*/

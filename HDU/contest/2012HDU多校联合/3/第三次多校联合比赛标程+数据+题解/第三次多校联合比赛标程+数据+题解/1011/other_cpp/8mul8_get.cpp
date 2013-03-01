#include <cstdio>
#include <cstdlib>
int fd(char uu[10][10])
{
    int ret=0;
    int mark[10][10];
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
        mark[i][j]=0;
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
    {
        if(mark[i][j])continue;
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

int main()
{
    freopen("8mul8.in","w",stdout);
    srand(1);
    int cases=100;
    printf("%d\n",cases);
    for(int i=0;i<cases;i++)
    {
        char uu[10][10];
        for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            uu[i][j]=rand()%5+'0';
        while(fd(uu))
        {
            for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                if(uu[i][j]=='x')
                    uu[i][j]=rand()%5+'0';
            }
        }
        for(int i=0;i<8;i++)
        {
            uu[i][8]=0;
            printf("%s\n",uu[i]);
        }
        printf("\n");
    }
}

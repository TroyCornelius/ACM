#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
bool graph[1000][1000];
int degree[1000];
int a[1000];              // 标号
int label[1000];
int n,m;
bool judge()
{
    int i,j,k,p,max,min;
    a[0]=1;                 //进A=1
    label[0]=n-1;
    for(i=1;i<n;i++)
        if(graph[i][0])
   degree[i]=1;
    /////////////////////进A///////////////////////////////
    for(i=n-2;i>=0;i--)
    {
        max=-1;
        for(j=0;j<n;j++)
            if(a[j]==0&&degree[j]>max)
   {
    max=degree[j];
    k=j;
   }
  a[k]=1;
        label[k]=i;
        for(p=0;p<n;p++)
            if(a[p]==0&&graph[p][k])
    degree[p]++;
    }
    //////////////////////进C//////////////////////
    for(i=0;i<=n-1;i++)
    {
         for(p=0;p<n;p++)
   if(label[p]==i)
    break;
         min=5000;
         for(j=0;j<n;j++)
         {
             if(label[j]>label[p] && graph[j][p]==1) 
             {
                 a[j]=2;  
                 if(label[j]<min)  
                 {
                     min=label[j];
                     k=j;
                 }
             }
         }
         for(j=0;j<n;j++)
             if(a[j]==2&&j!=k&&graph[k][j]==0)
     return false;
         for(j=0;j<n;j++)
             if(a[j]==2)
     a[j]=1;
    }
    return true;
}
int main()
{
// freopen("in.txt","r",stdin);
    int i,x,y;
     scanf("%d %d",&n,&m);
    
        memset(graph,0,sizeof(graph));
        memset(a,0,sizeof(a));
        memset(degree,0,sizeof(degree));
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            graph[x-1][y-1]=1;
   graph[y-1][x-1]=1;
        }     
        if(judge())
   printf("FHTAGN!\n");
  else
   printf("NO\n");
       system("pause");
    return 0;
}

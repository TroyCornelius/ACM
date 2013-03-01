#include "stdio.h"
#include "iostream"
typedef struct
{
 char b[]="22233344455566677778889999";
 char str[14];
}NUM;
int map(NUM a[],int j,int k)
{
 if(a[j].str[k]>=0&&a[j].str[k]<=9)
  return a[j].str[k];
 if(a[j].str[k]>='A'&&a[j].str[k]<='Y')
  return a[j].b[str[k]-'A'];
}
int main()
{
   NUM a[n],t;
   int m=0,i,j,cnt=0;
   cin>>n;
   while(m<n)
   {
    cin>>a[m].str>>endl;
    len=strlen(a[m].str);
    for(i=0;i<len;i++)
    {
     if(i>=0&&i<3||i>3)
      a[m].str[i]=map(a,m,i);
     if(i==3)
               a[m].str[i]="-";
    }
   }
   for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
     if(strcpy(a[i].str,a[j].str)>0)
     {t=a[i].str;
     a[i].str=a[j].str;
     a[j].str=t;
     }
    }
   for(i=0;i<n;i++)
   {
    t=a[i].str;
       for(j=i+1;j<n;j++)
     if(strcpy(t,a[j].str)==0)
      cnt++;
     else break;
    cout<<t<<" "<<cnt<<endl;
   }
   return 0;
}

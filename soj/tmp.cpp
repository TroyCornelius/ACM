#include<iostream>
#include<string.h>
using namespace std;
int s,len,sum;             
char x[11];               
struct stu                   
{
 int k;              
 int a[26];              
}str[200000];
void ws()             
{
 int i;
 str[s].k=0;
 for(i=0;i<26;i++)
  str[s].a[i]=0;
}
void zds(int i,int j)            
{
 if(j==len)             
 {
  str[i].k=1;         
  return ;
 }
 if(x[j]>='A'&&x[j]<='Z')
  x[j]=x[j]+'a'-'A';
 int m=x[j]-'a';
 if(str[i].a[m]==0)      
 {
  ws();
  str[i].a[m]=s;
  s++;
 }
 zds(str[i].a[m],j+1);         
}
void cz(int i,int j)             
{
 if(j==len)                  
 {
  if(str[i].k)              
  {
  str[i].k=0;                
  sum++;              
  }
  return ;
 }
 if(x[j]>='A'&&x[j]<='Z') 
  x[j]=x[j]+'a'-'A';
 int m=x[j]-'a';
 if(str[i].a[m]==0)return ;           
 cz(str[i].a[m],j+1);
}
int main()
{
 int m,n,i;
 while(cin>>n)
 {
  if(n==0)break;
  cin>>m;
  s=0;
  ws();
  s=1;
  for(i=0;i<n;i++)
  {
   scanf("%s",x);
   len=strlen(x);
   zds(0,0);
  }
  sum=0;
  for(i=0;i<m;i++)
  {
   scanf("%s",x);
   len=strlen(x);
   cz(0,0);
  }
  n=n-sum;
  printf("%d\n",n);
 }
 return 0;
}

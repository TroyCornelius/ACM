#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
bool is[5000100];
int prm[5000100];
int a[100100];
int phi[5000100];
int minn,minn1,minn2,cnt,cnt1,cnt2,tmp,t,n,k,k1,k2,kk;

void get_prime(int n)
{
	int i,j,k=0;
	int s,e=(int)(sqrt(1.0*n)+1);
	memset(is,1,sizeof(is));
	prm[k++]=2;
	is[0]=is[1]=0;
	for (i=4; i<n; i+=2) is[i]=0;
	for (i=3; i<e; i+=2)
	   if (is[i])
	   {
	      prm[k++]=i;
	      for (s=i*2, j=i*i; j<n; j+=s)
	          is[j]=0;
	   }
	for (; i<n; i+=2) if (is[i]) prm[k++]=i;
	is[1]=1;
}

void euler(int n)
{
   for (int i=1; i<=n; i++) phi[i]=i;
   for (int i=2; i<=n; i+=2) phi[i]/=2;
   for (int i=3; i<=n; i+=2)
   if (phi[i]==i)
   {
      for (int j=i; j<=n; j+=i)
         phi[j]=phi[j]/i*(i-1);
   }
}

bool solve(int a,int b,int c)
{
    if (a+b+c==0) return false;
    if (a+b+c==1) {return true;}
    if (a==1 && b==1 && c==1) {tmp=minn2; return solve(0,1,0); }
    if (a==0 && b==1 && c==1) {tmp=minn2; return !solve(0,0,0); }
    if (a==1 && b==1 && c==0) {tmp=minn1; return !solve(0,0,0); }
    if (a==1 && b==0 && c==1) {tmp=minn2; return !solve(0,0,0); }
}

int main()
{
    get_prime(5000000);
    euler(5000000);
    t=0;
    while (~scanf("%d",&n))
    {
       minn=minn1=minn2=1<<30;
       cnt=cnt1=cnt2=0;
       bool flag,flag1,flag2;
       flag=flag1=flag2=true;
        for (int i=0; i<=n-1; i++)
        {
            scanf("%d",&a[i]);
            if (is[a[i]]==1) {if (flag==true && a[i]!=1) {minn=i; flag=false;} if (a[i]!=1) cnt++;}
            else
            if (a[i]-1-phi[a[i]]==2 || (sqrt(a[i])==(int)(sqrt(a[i])) && is[(int)(sqrt(a[i]))]==1 && a[i]!=1))
             {if (flag1==true) {minn1=i; flag1=false;} cnt1++;}
            else {if (flag2==true) {minn2=i; flag2=false;} cnt2++;}
        }
   //     cout <<cnt <<cnt1 <<cnt2<<endl;
    //    cout << minn <<" "<< minn1 <<" "<< minn2<<endl;
        flag=solve(cnt%2,cnt1%2,cnt2%2);
        if (flag==true)
        {
           //cout << tmp << endl;
           if (cnt%2+cnt1%2+cnt2%2==1)
           {
               if (cnt%2==1) tmp=minn;
               if (cnt1%2==1) tmp=minn1;
               if (cnt2%2==1) tmp=minn2;
           }
           if (cnt1+cnt2>=2) if (tmp>minn) tmp=minn;
           t++;
           printf("Test #%d: Alice %d\n",t,tmp+1);
        }
        else {t++; printf("Test #%d: Bob\n",t);}
    }
    system("pause");
    return 0;
}

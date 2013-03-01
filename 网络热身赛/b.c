
#include <stdio.h>
int main()
{
    freopen("std.in", "r", stdin);
    freopen("std.out", "w", stdout);
 int n,i,j,k,p,q,a[20],b[100][2],flag=1;
 scanf("%d",&n);
 for(k=0;k<n;k++)
  scanf("%d",&a[k]);

 for(k=0;k<n;k++)
 {
  p=0;
  for(i=1;;i++)
  {
   for(j=a[k]-i+1;j<a[k]+i;j++)
   {
    if(i*i+j*j==a[k]*a[k] || i*i+a[k]*a[k]==j*j || a[k]*a[k]+j*j==i*i)
    {
     if(j<=i)
     {
      b[p][0]=i;b[p][1]=j;
      p++;
     }
    }
   }
   if((2*i+1)>a[k]*a[k])
    break;
  }
  for(q=p-1;q>=0;q--)
   printf("%d,%d\n",b[q][0],b[q][1]);
  if(k!=n-1)
   printf("\n");
 }
}


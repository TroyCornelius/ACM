#include<stdio.h>
#include<math.h>
long long H(int n){
    long long res = 0;
   int m = (int)sqrt(n+0.0);
   int i;
    for( i = 1; i <= m; i=i+1 ){
     int tmp = n/i;
        res += tmp;
     int y = n/(i+1);
     if(i==tmp){
        break;
     }
     int x = tmp - y;
     res += x * i;
    }
    return res;
}
int main(){
   int T;
   int n;
   scanf("%d",&T);
   while(T--){
     scanf("%d",&n);
     printf("%lld\n",H(n));
   }
}

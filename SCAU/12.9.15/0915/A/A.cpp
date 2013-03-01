#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
 
using namespace std;
typedef long long int64;
 
#define MOD 1000000007
 
int tcase;
int64 n,res;
int64 A[2][2],B[2][2],C[2][2];
int64 inv; 
int64 F[6];
 
int64 powmod(int64 base,int64 exp){
   int64 res = 1;
   for( ; exp; exp>>=1) {
      if(exp & 1) {
          res = res*base; res %= MOD;
      }
      base = base*base ; base %= MOD;
   }
   return res;
}
 
int64 calculate(int64 n){
   int64 tn = n; n += 5; 
   A[0][0] = A[1][1] = 1; A[1][0] = A[0][1] = 0;
   B[0][0] = B[0][1] = 1; B[1][0] = 1; B[1][1] = 0 ;
   for(  ; n ; n>>=1 ){
      if( n&1 ){
          C[0][0] = A[0][0]; C[0][1] = A[0][1]; 
          C[1][0] = A[1][0]; C[1][1] = A[1][1];
          A[0][0] = A[0][1] = A[1][0] = A[1][1] = 0; 
          for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) {
             for(int k=0; k<2; ++k){
                  A[i][j] += (C[i][k]*B[k][j])%MOD;  A[i][j] %= MOD;
              }
          } 
      }
      C[0][0] = B[0][0]; C[0][1] = B[0][1]; 
      C[1][0] = B[1][0]; C[1][1] = B[1][1];
      B[0][0] = B[0][1] = B[1][0] = B[1][1] = 0;
      for(int i=0; i<2; ++i) for(int j=0; j<2; ++j){
        for(int k=0; k<2; ++k) {
             B[i][j] += (C[i][k]*C[k][j])%MOD;  B[i][j] %= MOD;
        }
      }
   }  
   int64 FA = A[0][0]; int64 FB = A[1][0];  
 
   res = 0; res += (((2*tn+10)%MOD)*FA)%MOD; res -= (((tn+6)%MOD)*FB)%MOD; res %= MOD;
   res *= inv; res %= MOD; 
   for(int i=0; i<5; ++i) {
     int64 T = (FA-FB+MOD)%MOD; FA = FB; FB = T; 
     if(i<2) res -= 2*F[i]*FA; else res -= F[i]*FA;  res %= MOD; 
   }
   res = (res + MOD)%MOD;
   return res;     
}
 
int main(){
  
    freopen("A.in", "r", stdin);  
    freopen("A.out", "w", stdout);
    
  F[0] = 0; F[1] = 1; F[2] = 1; F[3] = 2; F[4] = 3; F[5] = 5;
  inv = powmod(5,MOD-2);
  for( scanf("%d",&tcase); tcase; tcase-=1) {
      scanf("%lld",&n); printf("%lld\n",calculate(n)); 
  }
  return 0;
}

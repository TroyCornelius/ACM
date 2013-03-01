#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
//系列存在1...n,n+1列为常数行，答案存在x[] 
int n=11;
double a[15][15];
double x[15];
void guass(){
    int i,j,k; double sum,rate;
    for (k=1;k<n;k++){
        for (i=k,j=k;i<=n;i++) j=fabs(a[i][k])>fabs(a[j][k])?i:j;
        for (i=k;i<=n+1;i++) swap(a[j][i],a[k][i]);
        for (i=k+1;i<=n;i++)
          for (rate=a[i][k]/a[k][k],j=k;j<=n+1;j++)
            a[i][j]-=a[k][j]*rate;    
    }
    for (i=n;i>=1;i--){
        for (sum=0,j=i+1;j<=n;sum+=a[i][j]*x[j],j++);
        x[i]=(a[i][n+1]-sum)/a[i][i];
    }
}
double mat[15][15];
double result[15];
double Fix(double y){
	if (fabs(y)<5e-3) return 0;
	return y;
}
int main(){
	int Tc;
	scanf("%d",&Tc);
	while (Tc--){
		for (int i=1;i<=12;i++){
			for (int j=1;j<=11;j++)
				scanf("%lf",&mat[i][j]);
			scanf("%lf",&result[i]);
			result[i]=result[i]*result[i];
			for (int j=1;j<=11;j++){
				result[i]-=mat[i][j]*mat[i][j];
				mat[i][j]*=-2;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)
				a[i][j]=mat[i][j]-mat[i+1][j];
			a[i][n+1]=result[i]-result[i+1];
		}
		guass();
		for (int i=1;i<=n;i++){
			if (i!=1) printf(" ");
			printf("%.2lf",Fix(x[i]));
		}
		printf("\n");
	}
}

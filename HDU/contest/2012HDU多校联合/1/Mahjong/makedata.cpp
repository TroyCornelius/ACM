#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[300000],b[303][303],c[303][303];
int n;

void gaor(){
    for (int i=1;i<=10000;++i){
        int r=rand()%n+1;
        int p1=rand()%n+1,p2=rand()%n+1;
        swap(b[r][p1],b[r][p2]);
    }
}

void gaoc(){
    for (int i=1;i<=10000;++i){
        int c=rand()%n+1;
        int p1=rand()%n+1,p2=rand()%n+1;
        swap(b[p1][c],b[p2][c]);
    }
}

int main(){
    srand(time(NULL));
    memset(a,0,sizeof(a));
    n = 300;
    int T = 2;
    int ma=n*n;
    printf("%d\n",T);
    
    for (int tm=1;tm<=T;++tm){
        memset(a,0,sizeof(a));
        printf("%d %d %d\n",n,rand()%1000000,rand()%1000000);
        
        for (int i=1;i<=ma;++i) a[i]=(i+1)/2;
        random_shuffle(a+1,a+ma+1);
        
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                b[i][j]=c[i][j]=a[(i-1)*n+j];

        gaoc();
        gaor();
        gaoc();        
        
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j) printf("%d ",b[i][j]);
            puts("");
        }
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j) printf("%d ",c[i][j]);
            puts("");
        }
        
        
    }
    return 0;
}
    
    

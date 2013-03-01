#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


int main() 
{
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        int m;
        m=(int)ceil(sqrt(n));
        //cout << m << endl;
        int tmp=n/m;
        if (n%m!=0) tmp++;
        //cout << tmp << endl;
        //if(n == 2) {
            //printf("1 2\n");
            //continue;
        //}
        bool flag=false;
        if (tmp==m) {
           int idx=n-n/m*m;
           
           for (int i=idx; i>=1; i--) {
               if (flag) printf(" "); 
               else  flag=true;
                   printf("%d",i);}
           
           for (int i=1; i<=n/m; i++) {
                for (int j=m; j>=1; j--) {
                     if (flag) printf(" "); 
               else  flag=true;
                    printf("%d",idx+(i-1)*m+j);
                }
           }
           printf("\n");
        }
        else {
            int k=m-tmp;
            //cout << k << endl;
            for (int i=1; i<=k; i++) {
                 if (flag) printf(" "); 
               else  flag=true;
                printf("%d",i);
            }
            //cout << endl;
            int idx=n-n/m*m;
            if (idx==0) idx=m;
            
            for (int i=idx; i>=k+1; i--) {
                 if (flag) printf(" "); 
               else  flag=true;
                printf("%d",i);
            }
            //cout << endl;
            int i;
            if (n%m==0) i=2,idx=0;
            else i=1;
            for (; i<=n/m; i++) {
                for (int j=m; j>=1; j--) {
                     if (flag) printf(" "); 
               else  flag=true;
                    printf("%d",idx+(i-1)*m+j);
                }
            }
            printf("\n");
            
        }
    
    }
    return 0;
}


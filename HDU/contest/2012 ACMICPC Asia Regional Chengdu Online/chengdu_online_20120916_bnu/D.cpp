#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
//n是矩阵的规模，res是单位矩阵，t是乘子，m是模数，注意矩阵不易过大
//注意对n和m进行初始化
const int maxn = 3;
struct room {
    ll element[maxn][maxn];
};
int n;
ll m;
room matrix_mul(room &aa, room &bb) {
    room s;
    ll i, j, k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            s.element[i][j] = 0;
            for (k = 1; k <= n; k++) s.element[i][j] = (s.element[i][j] + aa.element[i][k] * bb.element[k][j]) % m;
        }
    return s;
}

room matrix_pow(room t, long long power) {
    room res;
    ll i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) res.element[i][j] = 0;
        res.element[i][i] = 1;
    }
    while (power) {
        if (power&1) res = matrix_mul(t, res);
        power >>= 1;
        t = matrix_mul(t, t);
    }
    return res;
}
room a,t;
int main(){
    n=2;

    a.element[1][1]=0;
    a.element[1][2]=1;
    a.element[2][1]=1;
    a.element[2][2]=3;
    ll p;
    while(scanf("%I64d",&p)!=EOF){





        a.element[1][1]=0;
        a.element[1][2]=1;
        a.element[2][1]=1;
        a.element[2][2]=3;

        /*
        m=222222224ll;
        t = matrix_pow(a,p);
        ll ttt  = t.element[2][1];
        printf("%I64d\n",ttt);
        continue;
        */


        m=183120ll;
        t = matrix_pow(a,p);
        ll x  = t.element[2][1];

//        printf("~~~%I64d\n",x);


        m=222222224ll;
        t = matrix_pow(a,x);
        ll y  = t.element[2][1];

        m=1000000007ll;
        t = matrix_pow(a,y);
        ll z  = t.element[2][1];
        printf("%I64d\n",z);
    }
    return 0;
}
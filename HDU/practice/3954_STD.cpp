#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
const int maxn = 11111;
const int maxk = 12;

int add[maxn<<2];
int MAX[maxk][maxn<<2];
int need[maxk];
int n , K;
void pushDown(int rt) {
	if (add[rt]) {
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		for (int i = 1 ; i <= K ; i ++) {
			if (MAX[i][rt<<1] != -1) MAX[i][rt<<1] += add[rt] * i;
			if (MAX[i][rt<<1|1] != -1) MAX[i][rt<<1|1] += add[rt] * i;
		}
		add[rt] = 0;
	}
}
void pushUp(int rt) {
	for (int i = 1 ; i <= K ; i ++) {
		MAX[i][rt] = max(MAX[i][rt<<1] , MAX[i][rt<<1|1]);
	}
}
void levelUp(int i,int l,int r,int rt) {
	if (l == r) {
		while (i < K) {
			if (MAX[i][rt] < need[i]) break;
			MAX[i+1][rt] = MAX[i][rt];
			MAX[i][rt] = -1;
			i ++;
		}
		return ;
	}
	pushDown(rt);
	int mid = (l + r) >> 1;
	if (MAX[i][rt<<1] >= need[i]) levelUp(i , lson);
	if (MAX[i][rt<<1|1] >= need[i]) levelUp(i , rson);
	pushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
	if (L <= l && r <= R) {
		add[rt] += c;
		for (int i = K ; i >= 1 ; i --) {
			if (MAX[i][rt] != -1) MAX[i][rt] += c * i;
			if (i < K && MAX[i][rt] >= need[i]) {
				levelUp(i , l , r , rt);
			}
		}
		return ;
	}
	pushDown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(L , R , c , lson);
	if (mid < R) update(L , R , c , rson);
	pushUp(rt);
}
int query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		for (int i = K ; i >= 1 ; i --) {
			if (MAX[i][rt] != -1) return MAX[i][rt];
		}
	}
	pushDown(rt);
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid) ret = max(ret , query(L , R , lson));
	if (mid < R) ret = max(ret , query(L , R , rson));
	return ret;
}
int main() {
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int T , cas = 1;
	scanf("%d",&T);
	while (T --) {
		int Q;
		scanf("%d%d%d",&n,&K,&Q);
		for (int i = 1 ; i < K ; i ++) scanf("%d",&need[i]);

		memset(add , 0 , sizeof(add));
		memset(MAX[1] , 0 , sizeof(MAX[1]));

		for (int i = 2 ; i <= K ; i ++) {
			memset(MAX[i] , -1 , sizeof(MAX[i]));
		}
		printf("Case %d:\n" , cas ++);
		while (Q --) {
			char op[2];
			int a , b , c;
			scanf("%s",op);
			if (op[0] == 'W') {
				scanf("%d%d%d",&a,&b,&c);
				update(a , b , c , 1 , n , 1);
			} else {
				scanf("%d%d",&a,&b);
				printf("%d\n" , query(a , b , 1 , n , 1));
			}
		}
		puts("");
	}
	return 0;
}


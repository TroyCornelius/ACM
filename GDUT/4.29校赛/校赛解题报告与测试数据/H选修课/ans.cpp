#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define LL long long
using namespace std;
const int MAXN = 20005;

inline LL Max(LL x, LL y) { return x > y ? x : y; }
struct Node { int l, p; };
vector<Node> Vec[MAXN];

LL f[MAXN][2];
/**
 * f[i][0]表示前i个项目中不投资i项目的最大获利
 * f[i][1]表示前i个项目中投资i项目的最大获利
**/
struct segment_trees {
	int ld, rd;
	LL c, max;
};

segment_trees tree[100005 * 3];

void make_tree(int p, int a, int b)
{
        int m = (a+b)>>1;
	tree[p].ld = a; tree[p].rd = b;
	tree[p].c = tree[p].max = 0;
	if(a == b) return;
	make_tree(L(p), a, m);
	make_tree(R(p), m+1, b);
}
void insert(int T, int a, int b, LL v)
{
	int l = L(T), r = R(T);
	if(a <= tree[T].ld && tree[T].rd <= b)
	{
	        tree[T].c+=v;
	        tree[T].max+=v;
	        return;

	}
	int mid = (tree[T].ld + tree[T].rd) >> 1;
	if(a <= mid) insert(l, a, b, v);
	if(b > mid) insert(r, a, b, v);
	tree[T].max=tree[T].c+Max(tree[l].max,tree[r].max);
}

LL inc, maxV;
void query(int T, int a, int b)
{
	int l = L(T), r = R(T);
	if(a <= tree[T].ld && tree[T].rd <= b)
	{
	        if(maxV < tree[T].max + inc) maxV = tree[T].max + inc;
	        return;

	}
	int mid = (tree[T].ld + tree[T].rd) >> 1;
	inc += tree[T].c;
	if(a <= mid) query(l, a, b);
	if(b > mid) query(r, a, b);
	inc -= tree[T].c;
}

int cost[100005];
void Solve(int n)
{
        int i, j;
        Node tmp;
        vector<Node>::iterator it;
        LL oo = -1000000000;
        oo *= 30000;
        for(i = 0; i <= n; ++i) f[i][0] = f[i][1] = oo;
        f[0][0] = 0; // 待检查
        make_tree(1,0,n);
        for(i = 1; i <= n; ++i)
        {
                f[i][0] = Max(f[i - 1][0], f[i - 1][1]);
                //printf("f[%d][0] = %I64d\n", i, f[i][0]);
                for(it = Vec[i].begin(); it != Vec[i].end(); it++)
                {
                        tmp = *it;
                        insert(1, 0, tmp.l-1, tmp.p);
                }
                insert(1, 0, i-1, -cost[i]);
                inc=0; maxV = oo;
                query(1, 0, i-1);
                f[i][1] = maxV;
                //printf("f[%d][1] = %I64d\n", i, f[i][1]);
                insert(1, i, i, f[i][0]);
                // f[i][1] =  f[k-1][0] + sum(l1,l2...) - cost(k..,i)
                // 将   0<=k<=Li, Ri
                // 将区间[0, Li]的值全部加p
                // 级区间[0, i]的值全部值减cost[i]
                // 查询区间[0, i-1]的最大值
                // 插入新的点i,值为f[i][0]

        }
        LL ans = Max(f[n][0], f[n][1]);
        if(ans < 0) ans = 0;
        printf("%I64d\n",ans);

}
int main()
{
	int i, n, m, r, t;
	Node tmp;
	freopen("data1.in","r",stdin);
	freopen("data1.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
	        scanf("%d", &n);
	        for(i = 1; i <= n; ++i) Vec[i].clear();
	        for(i = 1; i <= n; ++i) scanf("%d", &cost[i]);
	        scanf("%d", &m);
		for(i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &tmp.l, &r, &tmp.p);
			Vec[r].push_back(tmp);
		}
		Solve(n);
	}
	return 0;
}

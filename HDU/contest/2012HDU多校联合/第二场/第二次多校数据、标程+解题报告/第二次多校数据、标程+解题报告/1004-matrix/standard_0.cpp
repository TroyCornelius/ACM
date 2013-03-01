#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;


typedef __int64 ll;
const int MAXN = 100010;
const int INF = (~0U>>1);
const ll LINF = ((~0ULL)>>2);
struct Edge{
	int v, w;
	int next;
	Edge(){}
	Edge(int _v, int _w, int _next){
		v = _v; w = _w; next = _next;
	}
}ePool[2*MAXN];

int head[MAXN], eTop;

void init_e(){
	memset(head, -1, sizeof(head));
	eTop = 0;
}
void add_e(int u, int v, int w){
	ePool[eTop] = Edge(v, w, head[u]);
	head[u] = eTop++;
	ePool[eTop] = Edge(u, w, head[v]);
	head[v] = eTop++;
}

ll dp[MAXN][2];
bool dangerous[MAXN];

void calc_dp(int u, int f){
	bool has_son = false;
	ll sum = 0;
	for(int p = head[u]; p != -1; p = ePool[p].next){
		int v = ePool[p].v;
		if(v == f)continue;
		has_son = true;
		calc_dp(v, u);
		sum += min(dp[v][0], ePool[p].w + dp[v][1]);
	}
	if(!has_son){ // leaf
		dp[u][0] = dp[u][1] = 0;
		if(dangerous[u])dp[u][0] = LINF;
		return ;
	}

	dp[u][1] = dp[u][0] = sum;
	if(dangerous[u]){
		dp[u][0] = LINF;
		return ;
	}
	// u isn't dangerous vertex
	for(int p = head[u]; p != -1; p = ePool[p].next){
		int v = ePool[p].v;
		if(v == f)continue;
		ll old_value = min(dp[v][0], ePool[p].w + dp[v][1]);
		dp[u][1] = min(dp[u][1], sum - old_value + dp[v][1]);
	}
}

int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	int n, k, a, b, c, T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		init_e();
		for(int i = 0; i < n - 1; ++i){
			cin>>a>>b>>c;
			add_e(a, b, c);
		}
		memset(dangerous, 0, sizeof(dangerous));
		for(int i = 0; i < k; ++i){
			cin>>a;
			dangerous[a] = true;
		}
		calc_dp(a, a);
		cout<<min(dp[a][0], dp[a][1])<<endl;
	}
}

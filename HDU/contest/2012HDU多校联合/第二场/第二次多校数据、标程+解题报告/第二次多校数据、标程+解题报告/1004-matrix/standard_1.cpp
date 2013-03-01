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
	int a, b, c;
	Edge(){}
	bool operator < (const Edge &e)const {
		return c > e.c;
	}
}edge[MAXN];

int p[MAXN], dangerous[MAXN];
void make_set(int n){
	for(int i = 0; i < n; ++i)
		p[i] = i;
}
int Find(int v){
	if(p[v] == v)return v;
	return p[v] = Find(p[v]);
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[x] = y;
	if(dangerous[x])
		dangerous[y] = 1;
}

int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("greedy.out", "w", stdout);
	int n, k, T, a;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i = 0; i < n - 1; ++i){
			cin>>edge[i].a>>edge[i].b>>edge[i].c;
		}
		memset(dangerous, 0, sizeof(dangerous));
		for(int i = 0; i < k; ++i){
			cin>>a;
			dangerous[a] = true;
		}
		sort(edge, edge + n - 1);
		ll ans = 0;
		make_set(n);
		for(int i = 0; i < n - 1; ++i){
			int x = Find(edge[i].a);
			int y = Find(edge[i].b);
			if(dangerous[x] && dangerous[y])
				ans += edge[i].c;
			else Union(x, y);
		}
		cout<<ans<<endl;
	}
}

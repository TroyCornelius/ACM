#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
struct Edge {
	int u, v;
	double cost;
	int next;
}et[maxm];

int n, m;
double l, uu;
void init() {
	tot = 0;
	memset(eh, -1, sizeof(eh));
}

void addedge(int u, int v, double cost) {
	Edge e = {u, v, cost, eh[u]};
	et[tot] = e;
	eh[u] = tot++;
}
int main()
{
	while(scanf("%d%d%lf%lf", &n, &m, &l, &uu) != EOF) {
		init();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%lf", &mat[i][j]);
				addedge(j + n, i, log(uu / mat[i][j]));
				addedge(i, j + n, -log(l / mat[i][j]));
			}
			
		}    
    
    return 0;
    }

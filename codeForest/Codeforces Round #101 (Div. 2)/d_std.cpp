#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAXN = 400003;
const int INF = 1000000001;

int n, m, d[MAXN], x[MAXN], D[MAXN], t[MAXN], p[MAXN], parent[MAXN], pp[MAXN], N = 0;
map<int,int> pos;
vector<pair<int,int> > adj[MAXN];
vector<int> desc[MAXN];

struct TCmp {
        bool operator() (int a, int b) {
                if (d[a] != d[b])
                        return d[a] < d[b];
                return a < b;
        }
};

set<int,TCmp> Pq;

int main() {
        scanf("%d%d", &n, &m);

        pos[0] = 0;
        pos[m] = 0;
        for (int i = 0; i < n; i++) {
                scanf("%d%d%d%d", &x[i], &D[i], &t[i], &p[i]);
                if (x[i]-p[i] >= 0) {
                        //printf("adding %d %d\n", x[i]-p[i], x[i]+D[i]);
                        pos[x[i]-p[i]] = 0;
                        pos[x[i]+D[i]] = 0;
                }
        }

        for (map<int,int>::iterator it = pos.begin(); it != pos.end(); it++) {
                //printf("%d\n", (*it).first);
                pos[(*it).first] = N++;
        }

        int xx = 0, prev = -1;
        for (map<int,int>::iterator it = pos.begin(); it != pos.end(); it++) {
                if (prev != -1) {
                        adj[xx-1].push_back(make_pair(xx, (*it).first-prev));
                        desc[xx-1].push_back(-1);
                        adj[xx].push_back(make_pair(xx-1, (*it).first-prev));
                        desc[xx].push_back(-1);
                }
                xx++;
                prev = (*it).first;
        }
        
        for (int i = 0; i < n; i++)
                if (x[i]-p[i] >= 0) {
                        adj[pos[x[i]-p[i]]].push_back(make_pair(pos[x[i]+D[i]], t[i]+p[i]));
                        desc[pos[x[i]-p[i]]].push_back(i);
                }

        /*printf("vertices\n");
        printf("N = %d\n", N);
        for (map<int,int>::iterator it = pos.begin(); it != pos.end(); it++)
                printf("%d: %d\n", (*it).first, (*it).second);
        printf("\n");

        printf("edges\n");
        for (int i = 0; i < N; i++) {
                printf("%d: ", i);
                for (int j = 0; j < adj[i].size(); j++)
                        printf("%d,%d ", adj[i][j].first, adj[i][j].second);
                printf("\n");
        }*/

        for (int i = 0; i < N; i++)
                d[i] = INF;
        d[0] = 0;

        for (int i = 0; i < N; i++)
                Pq.insert(i);
        
        while (!Pq.empty()) {
                int u = *(Pq.begin());

                Pq.erase(Pq.begin());

                for (int i = 0; i < adj[u].size(); i++)
                        if (d[adj[u][i].first] > d[u]+adj[u][i].second) {
                                Pq.erase(Pq.find(adj[u][i].first));
                                d[adj[u][i].first] = d[u]+adj[u][i].second;
                                parent[adj[u][i].first] = desc[u][i];
                                pp[adj[u][i].first] = u;
                                Pq.insert(adj[u][i].first);
                        }
        }

        printf("%d\n", d[N-1]);

        int v = N-1;
        vector<int> result;
        while (v != 0) {
                if (parent[v] != -1)
                        result.push_back(parent[v]);
                v = pp[v];
        }

        reverse(result.begin(), result.end());

        printf("%d\n", (int)result.size());

        for (int i = 0; i < result.size(); i++)
                printf("%d ", result[i]+1);
        printf("\n");
        
        return 0;       
}


#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
#include "set"
#include "utility"
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sof(x) sizeof(x)
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
char maz[2000][2000];
bool visit[2000][2000];
pii pos[2000][2000];
int sx, sy, n, m;
queue<int> que;

bool bfs() {
    memset(visit, false, sof(visit));
    
    que.push(sx);
    que.push(sy);
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        int y = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            int rx = (xx%n + n) % n, ry = (yy%m + m) % m;
            if(maz[rx][ry] == '#') continue;
            if(visit[rx][ry]) {
                if(pos[rx][ry] != mp(xx, yy)) return true;
            } else {
                visit[rx][ry] = true;
                pos[rx][ry] = mp(xx, yy);
                que.push(xx);
                que.push(yy);
            }
        }
    }
    return false;
}

int main() {
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            cin >> maz[i];
            for(int j = 0; j < m; j++) {
                if(maz[i][j] == 'S') {
                    sx = i, sy = j;
                }
            }
        }
        if(bfs()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}


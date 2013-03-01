#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

const int INF = 1000000000;

struct rec {
    int a, b;

    rec(int a = 0, int b = 0) {
        this->a = a;
        this->b = b;
    }

    friend bool operator<(rec x, rec y) {
        if (x.a == y.a) return x.b > y.b;
        return x.a < y.a;
    }
};

int n, m;
vector<rec> pt, ep, sc;
vector<rec> sct;
vector<int> sca;
vector<rec> qa, qb;
vector<int> oa, ob;
int f[20][400005];
set<rec> ss;

int query(int l, int r) {
    if (r <= l) return 0;
    int ret = 0;
    int k = 20;
    int x = l;
    while (k) {
        k--;
        ret <<= 1;
        if (f[k][x] <= r) {
            ret += 1;
            x = f[k][x];
        }
    }
    return ret;
}

int main() {

    while (cin >> n >> m) {
        pt.clear();
        for (int i = 0; i < n; i++) {
            int ta, tb;
            cin >> ta >> tb;
            pt.push_back(rec(ta, tb));
        }
        sort(pt.begin(), pt.end());
        ep.clear();
        for (int i = 0; i < n; i++) {
            while (ep.size() != 0 && pt[i].b <= (*(ep.end() - 1)).b) ep.pop_back();
            ep.push_back(pt[i]);
        }

        sct.clear();
        for (int i = 0; i != ep.size(); i++) {
            sct.push_back(rec(ep[i].a, 2 * i));
            sct.push_back(rec(ep[i].b, 2 * i + 1));
        }
        sort(sct.begin(), sct.end());

        sca.clear();
        sc.resize(ep.size());
        for (int i = 0; i != sct.size(); i++) {
            if (i == 0 || sct[i].a != sct[i - 1].a)
                sca.push_back(sct[i].a);
            if (sct[i].b & 1) sc[sct[i].b / 2].b = sca.size() - 1;
            else sc[sct[i].b / 2].a = sca.size() - 1;
        }

        qa.clear();
        qb.clear();
        for (int i = 0; i < m; i++) {
            int ta, tb;
            cin >> ta >> tb;
            qa.push_back(rec(ta, i));
            qb.push_back(rec(tb, i));
        }

        sort(qa.begin(), qa.end());
        sort(qb.begin(), qb.end());

        oa.resize(m);
        ob.resize(m);

        int pa = 0;
        for (int i = 0; i != qa.size(); i++) {
            while (pa != sca.size() && sca[pa] < qa[i].a) pa++;
            if (pa == sca.size()) oa[qa[i].b] = INF;
            else oa[qa[i].b] = pa;
        }

        int pb = sca.size() - 1;
        for (int i = qb.size() - 1; i >= 0; i--) {
            while (pb >= 0 && sca[pb] > qb[i].a) pb--;
            if (pb == -1) ob[qa[i].b] = -INF;
            else ob[qb[i].b] = pb;
        }

        ss.clear();
        for (int i = 0; i != sc.size(); i++) ss.insert(sc[i]);
        ss.insert(rec(sca.size(), sca.size()));

        for (int i = 0; i != sca.size(); i++) {
            f[0][i] = (*ss.lower_bound(rec(i, INF))).b;
        }
        for (int i = 0; i < 20; i++)
            f[i][sca.size()] = sca.size();

        for (int i = 1; i < 20; i++)
            for (int j = 0; j != sca.size(); j++)
                f[i][j] = f[i - 1][f[i - 1][j]];

        for (int i = 0; i < m; i++) {
            cout << query(oa[i], ob[i]) << endl;
        }
    }
    return 0;
}

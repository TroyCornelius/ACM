#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 50000 + 10;

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a > 0 ? a : -a;
}

int*alloc(int size) {
	static int pool[MAX_N * 16] = { }, *ptr = pool;
	ptr += size;
	return ptr - size;
}

struct SegmentTree {
	//add a_i by v
	//query [l,r]'s gcd

	int*a, pw;

	inline void update(int i) {
		a[i] = gcd(a[i + i], a[i + i + 1]);
	}

	void init(int n, int val[]) {
		pw = 1;
		while (pw <= n + 3)
			pw <<= 1;
		a = alloc(pw * 2);
		for (int i = 0; i < n; ++i) {
			a[1 + pw + i] = val[i];
		}
		for (int i = pw - 1; i >= 1; --i) {
			update(i);
		}
	}

	void add(int i, int v) {
		a[i += pw + 1] += v;
		for (i >>= 1; i; i >>= 1)
			update(i);
	}

	int query(int l, int r) { //[l,r]
		l += pw, r += pw + 2;
		int ret = 0;
		for (; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if (~l & 1)
				ret = gcd(ret, a[l ^ 1]);
			if (r & 1)
				ret = gcd(ret, a[r ^ 1]);
		}
		return ret;
	}
};

struct TA {
	int*a, n;
	void init(int _n) {
		n = _n;
		a = alloc(n);
		memset(a, 0, sizeof(int) * n);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	void add(int l, int r, int x) {
		add(l, x);
		add(r + 1, -x);
	}
	int get(int p) {
		int ret = 0;
		for (p++; p; p -= p & -p) {
			ret += a[p - 1];
		}
		return ret;
	}
};

struct Chain {
	//add [l,r] by d
	//query [l,r]'s gcd

	int*a;
	int n;

	SegmentTree st;
	TA ta;

	Chain(int _n, int _a[]) {
		n = _n;
		a = alloc(n);
		for (int i = 0; i < n; ++i) {
			a[i] = _a[i];
		}

		static int diff[MAX_N];
		for (int i = 0; i < n - 1; ++i) {
			diff[i] = a[i + 1] - a[i];
		}
		st.init(n - 1, diff);

		ta.init(n);
		for (int i = 0; i < n; ++i) {
			ta.add(i, i, a[i]);
		}
	}

	void add(int l, int r, int d) {
		//update ta
		ta.add(l, r, d);
		//update st
		if (l > 0)
			st.add(l - 1, d);
		if (r + 1 < n)
			st.add(r, -d);
	}

	int query(int l, int r) {
//		cout << l << " " << r << endl;
		if (l == r)
			return ta.get(l);
		int ret = ta.get(l);
		ret = gcd(ret, st.query(l, r - 1));
		return ret;
	}
};

Chain*myChain[MAX_N];
int top[MAX_N], idx[MAX_N], size[MAX_N], father[MAX_N], dep[MAX_N];
int que[MAX_N], qh, qt;

int n;
vector<int> E[MAX_N];

int init[MAX_N];

void readInput() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b), E[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", init + i);
	}
}

void build() {
	qh = qt = 0;
	que[qt++] = 0;
	father[0] = -1;
	dep[0] = 0;

	while (qh < qt) {
		int u = que[qh++];
		for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
			if (*e != father[u]) {
				father[*e] = u;
				que[qt++] = *e;
				dep[*e] = dep[u] + 1;
			}
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		int u = que[i];
		size[u] = 1;
		for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
			if (father[*e] == u)
				size[u] += size[*e];
		}
	}

	memset(top, -1, sizeof top);
	for (int i = 0; i < n; ++i) {
		int tp = que[i];
		if (top[tp] != -1)
			continue;
		int u = tp;
		static int v[MAX_N];
		int cnt = 0;

		for (;;) {
			v[cnt] = init[u];
			top[u] = tp;
			idx[u] = cnt++;

			int nxt = -1;
			for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
				if (father[*e] == u && (nxt == -1 || size[*e] > size[nxt]))
					nxt = *e;
			}

			if (nxt == -1)
				break;

			u = nxt;
		}

		myChain[tp] = new Chain(cnt, v);
	}

	for (int i = 0; i < n; ++i) {
		myChain[i] = myChain[top[i]];
	}
}

void add(int u, int v, int d) {
	for (;;) {
		if (top[u] == top[v]) {
			if (dep[u] > dep[v])
				swap(u, v);
			myChain[u]->add(idx[u], idx[v], d);
			return;
		}

		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		myChain[u]->add(0, idx[u], d);
		u = father[top[u]];
	}
}

int query(int u, int v) {
	int ret = 0;
	for (;;) {
		if (top[u] == top[v]) {
			if (dep[u] > dep[v])
				swap(u, v);
			ret = gcd(ret, myChain[u]->query(idx[u], idx[v]));
			return ret;
		}

		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		ret = gcd(ret, myChain[u]->query(0, idx[u]));
		u = father[top[u]];
	}
	return -1;
}

int main() {
	readInput();
	build();
	int nQ;
	scanf("%d", &nQ);
	for (int i = 0; i < nQ; ++i) {
		char cmd;
		int u, v, c;
		scanf(" ");
		scanf("%c %d %d", &cmd, &u, &v);
		if (cmd == 'F') {
			printf("%d\n", query(u, v));
		} else {
			scanf("%d", &c);
			add(u, v, c);
		}
	}
	return 0;
}


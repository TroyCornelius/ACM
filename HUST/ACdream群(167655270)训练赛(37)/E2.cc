/*
Author: Adrian Kuegel
Date: August 2nd, 2011
Algorithm: sort by last occurence of each letter
Complexity: O(n)
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

char s[100001];
int ind[128], last_t[128], cnt[128];

bool comp(int a, int b) {
	return last_t[a] < last_t[b];
}

int main() {
	int tc, n;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %s", &n, s);
		for (int i=0; i<128; ++i) {
			last_t[i] = cnt[i] = 0;
			ind[i] = i;
		}
		for (int i=0; i<n; ++i) {
			last_t[s[i]] = i+1;
			++cnt[s[i]];
		}
		long long wt = 0;
		for (int i=0; i<128; ++i)
			wt += last_t[i] * cnt[i];
		sort(ind, ind+128, comp);
		int cur_t = 0;
		for (int i=0; i<128; ++i) {
			if (!last_t[ind[i]])
				continue;
			cur_t += cnt[ind[i]];
			wt -= cnt[ind[i]] * cur_t;
		}
		printf("%lld\n", wt * 5);
	}
	return 0;
}

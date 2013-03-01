// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <algorithm>

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

pair<int, char> lastOcc[128];
int cnt[128];
char buffer[25000];

int waittime(int len) {
	int ret = 0;
	FOR(i, 0, len) {
		lastOcc[(int) buffer[i]].first = i;
		cnt[(int) buffer[i]]++;
	}
	FOR(i, 0, len) {
		ret += (5 * (lastOcc[(int) buffer[i]].first - i));
	}

	return ret;
}

int main(int argc, char **argv) {
	int numCases;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		int len;
		scanf("%d", &len);

		FOR(i, 0, 128) {
			lastOcc[i].first = -1;
			lastOcc[i].second = (char) i;
			cnt[i] = 0;
		}

		scanf("%s", buffer);

		int before = waittime(len);
		sort(lastOcc, lastOcc + 128);
		int pos = 0;
		FOR(i, 0, 128) {
			while (cnt[i] --> 0) {
				buffer[pos++] = lastOcc[i].second;
			}
		}
		int after = waittime(len);

		printf("%d\n", before - after);
	}
	
	return 0;
}

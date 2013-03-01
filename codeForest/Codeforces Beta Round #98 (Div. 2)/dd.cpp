#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#define MAXN 4001
using namespace std;
long long h[MAXN + 1], p[MAXN + 1];
int m, n;
string ln;
int dp[3][MAXN];

long long getHash(int i, int len) {
	return (h[i + len] - h[i]) * p[n - i - len];
}

bool isPoly(int i, int len) {
	return getHash(i, len) == getHash(2 * m - i - len, len);
}
vector<string> res;
long long prime = 1000000009L;

int calc(int x, int y)
{
    
}
int main() 
{
    
	memset(dp, 0, sizeof dp);
	dp[0][0] = dp[1][0] = 1;
	cin >> ln;
	m = ln.length();
	n = 2 * m;
	p[0] = 1L;
	for (int i = 0; i < n; i++) {
		int index = i;
		if (index >= m)
			index = n - i - 1;
		h[i + 1] = h[i] + ln[index] * p[i];
		p[i + 1] = p[i] * prime;
	}
	for (int i = 1; i < m; i++) {
		dp[0][i] = dp[0][i - 1] + 1;
		dp[1][i] = 1;
		for (int j = i - 1; j >= 0; j--) 
        {
			int len = i - j + 1;
		//	if (isPoly(j, len)) 
            {
                int tmp = (j, i);
				int val = i - len < 0 ? 1 : dp[0][i - len] + 1;
				if (dp[0][i] > val) 
                {
					dp[0][i] = val;
					dp[1][i] = len;
				}
			}
		}
	}
	cout << dp[0][m - 1] << endl;
	for (int index = m - 1; index >= 0; index -= dp[1][index]) {
		string tmp = "";
		for (int i = index - dp[1][index]+1; i >= 0 && i <= index; i++)tmp += ln[i];
		res.push_back(tmp);
	}
	for (int i = res.size()-1; i >=0; i--) cout << res[i] << "+";
	cout << endl;
	return 0;
}

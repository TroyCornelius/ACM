#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int x[MAXN], y[MAXN];
ll sx[MAXN], sy[MAXN];

int main()
{
	freopen("data.in", "r", stdin);
	freopen("forcedata.out", "w", stdout);
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; ++i){
			cin>>x[i]>>y[i];
		}

		ll ans = -1;
		int k = -1;
		for(int i = 0; i < n; ++i){
			ll t = 0;
			for(int j = 0; j < n; ++j){
				t += max(abs(x[i] - x[j]), abs(y[i] - y[j]));
			}
			if(ans == -1 || ans > t){
				ans = t;
				k = i;
			}
		}
		//cout<<"meeting point "<<x[k]<<' '<<y[k]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

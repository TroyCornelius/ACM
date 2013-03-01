#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef __int64 ll;

const int MAXN = 100100;

struct Point{
	int x, y;
	Point(){}
	Point(int _x, int _y):x(_x),y(_y){}
}ary[MAXN];

int x[MAXN], y[MAXN];
ll sx[MAXN], sy[MAXN];

int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; ++i){
			cin>>x[i]>>y[i];
			ary[i] = Point(x[i] - y[i], x[i] + y[i]);
			x[i] = ary[i].x;
			y[i] = ary[i].y;
		}
		sort(x, x + n);
		sort(y, y + n);
		sx[0] = x[0];
		sy[0] = y[0];
		for(int i = 1; i < n; ++i){
			sx[i] = sx[i - 1] + x[i];
			sy[i] = sy[i - 1] + y[i];
		}
		ll ans = 1;
		ans <<= 60;
		for(int i = 0; i < n; ++i){
			int rankx = lower_bound(x, x + n, ary[i].x) - x;
			int ranky = lower_bound(y, y + n, ary[i].y) - y;
			//cout<<rankx<<' '<<ranky<<endl;
			ll t = ll(ary[i].x) * (rankx + 1) - sx[rankx] +
					sx[n - 1] - sx[rankx] - ll(ary[i].x) * (n - rankx - 1);
			t += ll(ary[i].y) * (ranky + 1) - sy[ranky] +
					sy[n - 1] - sy[ranky] - ll(ary[i].y) * (n - ranky - 1);
			ans = min(ans, t);
		}
		cout<<ans / 2<<endl;
	}
	return 0;
}

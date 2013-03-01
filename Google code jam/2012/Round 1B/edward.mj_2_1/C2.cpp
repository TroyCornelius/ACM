#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = 505;

int Tc;
int n;
long long a[N];
set < pair < long long , pair < long long , int > > > que;
map < long long , int > father;

void output(long long x,int i){
	long long y = x;
	vector <long long> vec1;
	vector <long long> vec2;
	while (y != 0) {
		vec1.push_back(a[father[y]]);
		y -= a[ father[y] ];
	}
	vec2.push_back(a[i]);
	x -= a[i];
	while (x != 0) {
		vec2.push_back(a[father[x]]);
		x -= a[ father[x] ];
	}
	for (int i=0;i<vec1.size();i++){
		if (i) printf(" ");
		cout << vec1[i];
	}
	cout << endl;
	for (int i=0;i<vec2.size();i++){
		if (i) printf(" ");
		cout << vec2[i];
	}
	cout << endl;
}

int main(){
	freopen("C.in","r",stdin);
	cin >> Tc;
	for (int ri=1;ri<=Tc;ri++){
		printf("Case #%d:\n",ri);
		cin >> n;
		for (int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		que.clear();
		father.clear();
		que.insert( make_pair( a[0] , make_pair( 0 , 0 ) ) );
		bool done = false;
		try {
			while (!que.empty()) {
				__typeof(que.begin()) it = que.begin();
				pair < int , pair < long long , int > > tmp = *it;
				que.erase(it);
				for (int i=tmp.second.second;i<n;i++){
					long long now = tmp.second.first + a[i];
					if (father.count(now)) {
						output(now, i);
						done = true;
						throw 1;
					} else {
						father[now] = i;
					}
					if ( i + 1 < n ) {
						que.insert(make_pair(  tmp.second.first + a[i] + a[i + 1] , make_pair( tmp.second.first + a[i] , i + 1 ) ));
					}
				}
			}
		}
		catch (...) {
		}
		if (!done) {
			puts("Impossible");
		}
	}
}

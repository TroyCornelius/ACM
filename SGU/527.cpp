#include 
#include 
#include 
#include 
#include 
using namespace std;
#define FOR(i, b, n)	for(int i = b; i &lt; n; i++)
#define RFOR(i, b, n)	for(int i = b; i &gt;= n; i--)
#define FORN(i, b)	FOR(i, b, n)
#define FORN0(i, b)	FOR(i, 0, n)
#define DEB if(0) 
#define DEBUG(x) DEB std :: cout &lt;&lt; #x &lt;&lt; " " &lt;&lt; (x) &lt;&lt; endl;
#define DEBVECTOR(a) DEB for(int i = 0; i &lt; n; i++){std :: cout &lt;&lt; a[i] &lt;&lt; " ";};cout &lt;&lt; endl;
#define DEBMATRIX(a) DEB for(int i = 0; i &lt; n; i++){for(int j = 0; j &lt; n; j++)std :: cout &lt;&lt; a[i][j] &lt;&lt; " ";cout &lt;&lt; endl;}
int n, m;
int a[25];
int bits[1&lt;&lt;25];
int uni[1&lt;&lt;25];
void print(int x){
	FOR(i,0,m)
		cout &lt;&lt; ((x&gt;&gt;i) &amp; 1);
	cout &lt;&lt; endl;
}
int main(){
	cin &gt;&gt; n &gt;&gt; m;
	FOR(i,0,n){
		a[i] = 0;
		FOR(j,0,m){
			char ch;
			cin &gt;&gt; ch;
			if(ch == '*')
				a[i] |= 1 &lt;&lt; j;
		}
	}
	bits[0] = 0;
	FOR(i,1,1&lt;&lt;25)
		bits[i] = bits[i&gt;&gt;1] + (i&amp;1);
	uni[0] = 0;
	FOR(s,0,25)
		FOR(i,0,1&lt;&lt;&lt;&lt;&lt; "----"&lt;&lt; endl;;
		print(i);
		print(uni[i]);
	}
	int mx = 999;
	FOR(i,0,1&lt;&lt;&lt;25) - 1);
		int res = uni[un];
		/*FOR(j,0,n){
			if( !((i &gt;&gt; j) &amp; 1))
				res |= a[j];
		}*/
		DEBUG(i);
		DEBUG(bits[i]);
		DEBUG(res);
		DEBUG(bits[res]);
		mx = min(mx, max(bits[res], bits[i]));
		DEBUG(mx);
	}
	cout &lt;&lt; mx;
	//DEBVECTOR(a);
	//DEBMATRIX(a);
	return 0;
}


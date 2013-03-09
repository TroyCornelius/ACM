// BEGIN CUT HERE

// END CUT HERE
#line 5 "NewArenaPassword.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


//vi g[150];
//int n;
/*
void dfs(string &s1, string &s2, int p) {
    vis[p] = true;
    if (p >= n) cnt[s2[p-n]-'a']++;
    else cnt[s1[p]-'a']++;
    REP(i, g[p].size()) {
        if (!vis[g[p][i]]) dfs(s1, s2, g[p][i]);
    }
}*/
class NewArenaPassword
{
        public:
        int editdis(string s1, string s2, int sl) {
            int n = s1.length();
            int ret = 0;
            cout <<s1 <<endl;
            cout <<s2 <<endl;
            cout <<sl <<endl;
            
            int cnt[256];
            bool v1[55], v2[55];
            for (int i = sl; i < n - sl; i++)
                if (s2[i] != s1[i]) ret++;
            memset(cnt, 0, sizeof(cnt));
            memset(v1, false, sizeof(v1));
            memset(v2, false, sizeof(v2));
            /*
            int tot = 0;
            for (int i = 0; i < sl; i++) {
                cnt[s2[i]-'a']++;
                v2[i] = true;
                tot++;
                if (!v2[n-i-1]) 
                    cnt[s2[n-i-1]-'a']++, tot++;
                //cnt[s1[n-i-1]-'a']++;
                v1[n-i-1] = true;
                //tot++;
                if (!v1[i]) 
                    cnt[s1[i]-'a']++, tot++;
            }
            ret += tot - *max_element(cnt, cnt+30);
               REP(i, n) {
            //g[i].pb(i+n);
                //g[i+n].pb(i);
                
                if (i < sl) {
                    //g[i+n].pb(n-i-1);
                    //g[n-i-1].pb(i+n);
                    
                }
            }
            
            memset(vis, false, sizeof(vis));
            REP(i, n) {
                memset(cnt, 0, sizeof(cnt));
                dfs(s1, s2, i);
                int tot = 0, mx = 0;
                REP(i, 26) {
                    tot += cnt[i];
                    mx = max(mx, cnt[i]);
                }
                cout <<tot <<" "<<mx <<endl;
                ret += tot - mx;
            }*/
            return ret;
        }
        int minChange(string s, int K)
        {
            int ans = 0;
            int n = s.size();
            //string s1 = oldPassword.substr(0, K);
            //string s2 = oldPassword.substr(oldPassword.size()-K, K);
            //return editdis(s1, s2, max(0, K - 1 - ((int)oldPassword.size()-K)+1));
            bool vis[100];
            memset(vis, false, sizeof(vis));
            int cnt[256];
            REP(i, K) {
                if (!vis[i]) {
                    memset(cnt, 0, sizeof(cnt));
                    int x = i, mx = 0, tot = 0;
                    while (!vis[x]) {
                        vis[x] = true;
                        cnt[s[x]-'a']++;
                        mx = max(mx, cnt[s[x]-'a']);
                        tot++;
                        if (x < K) x = n - K + x;
                        else x = x - n + K;
                    }
                    ans += tot - mx;
                }
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoderopen"; int Arg1 = 5; int Arg2 = 3; verify_case(0, Arg2, minChange(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "puyopuyo"; int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, minChange(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "loool"; int Arg1 = 3; int Arg2 = 1; verify_case(2, Arg2, minChange(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "arena"; int Arg1 = 5; int Arg2 = 0; verify_case(3, Arg2, minChange(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "amavckdkz"; int Arg1 = 7; int Arg2 = 5; verify_case(4, Arg2, minChange(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        NewArenaPassword ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

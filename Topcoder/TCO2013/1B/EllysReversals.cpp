// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysReversals.cpp"
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


class EllysReversals
{
        public:
        string change(string s) {
            vector<string> a;
            for (int i = 0; i+1 < s.length(); i += 2) {
                string tmp = s.substr(i, 2);
                sort(all(tmp));
                a.pb(tmp);
            }
            sort(all(a));
            string ret = "";
            REP(i, a.size()) ret += a[i];
            if (s.length() & 1) ret += s[s.length()-1];
            return ret;
        }
        int getMin(vector <string> words)
        {
            int n = words.size();
            REP(i, n) words[i] = change(words[i]);
            int ans = 0, cnt = 1;
            sort(all(words));
            for (int i = 1; i < n; i++)
                if (words[i] == words[i-1]) cnt++;
                else {
                    ans += (cnt / 2 * 2);
                    cnt = 1;
                }
            ans += (cnt / 2 * 2);
            return n - ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"esprit", "god", "redotopc", "odcpoter", "dog"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arr0[] = {"no", "zaphod", "just", "very", "improbable"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arr0[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arr0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arr0[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(4, Arg1, getMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EllysReversals ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

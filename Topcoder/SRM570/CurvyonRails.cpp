// BEGIN CUT HERE

// END CUT HERE
#line 5 "CurvyonRails.cpp"
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


class CurvyonRails
{
        public:
        int getmin(vector <string> field)
        {
                return int() ;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".."
,".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {"wCCww"
,"wCC.."
,"..w.."
,"....w"
,"ww..w"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {"C.w"
,"..."
,".C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {"w"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arr0[] = {"CC..CCCw.CwC..CC.w.C",
 "C.CCCwCCC.w.w..C.w..",
 "wwww...CC.wC.Cw.CC..",
 "CC..CC.w..w.C..CCCC.",
 "CC.CCC..CwwCCC.wCC..",
 "w.C..wwCC.CC.wwwCC..",
 ".CC.CC..CCC..CC.CC.C",
 "Cw....C.C.CCC...CC..",
 "CC.C..Cww.C.CwwwC..w",
 "wCCww..C...CCCCCCC.w",
 "C.CCw.CC.ww...C.CCww",
 "C.C.C.CCwCC..wCCw.Cw",
 "CCC.C...w..C.wC.wCCw",
 "CC.C..C..CCC.CC.C...",
 "C.ww...CCC..CC...CCC",
 "...CCC.CwwwC..www.C.",
 "wwCCCCC.w.C.C...wCwC",
 "CCwC.CwCCC.C.w.Cw...",
 "C.w.wC.CC.CCC.C.w.Cw",
 "CCw.CCC..C..CC.CwCCw",
 "C.wwwww.CwwCCwwwwwww"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CurvyonRails ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

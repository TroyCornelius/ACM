#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, v.size())
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

void require(bool cond, const string& message = "Runtime error")
{
    if (!cond) {
        cerr << message << endl;
        assert(false);
    }
}

vi zfunction(const string& s)
{
    int n = (int)s.length();
    vi z(n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

string s;
string rs;

string rev(string w)
{
    reverse(all(w));
    return w;
}

bool canView(const string& w)
{
    if (w.size() <= 1) return false;
    vi z = zfunction(w + '$' + s);
    z.erase(z.begin(), z.begin() + w.size() + 1);
    vi zb = zfunction(rev(w) + '$' + rs);
    zb.erase(zb.begin(), zb.begin() + w.size() + 1);
    forv(i, zb) {
        if (i && zb[i - 1] > zb[i]) {
            zb[i] = zb[i - 1];
        }
    }
    int n = z.size();
   // assert(n == s.size());
    forv(i, z) {
        if (i + w.size() > n) break;
        if (z[i] > 0) {
            int o = zb[n - (i + w.size())];
            if (o > 0 && z[i] + o >= w.size()) {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> s;
    rs = rev(s);
    int n; cin >> n;
    int ans = 0;
    forn(i, n) {
        string w;
        cin >> w;
        if (canView(w)) {
            ++ans;
        }
        cout <<ans <<endl;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


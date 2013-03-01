//Sample solution for the Bread Sorting problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef vector<int> vi;
int main()
{
    int n; scanf("%d", &n);
    vi a(n), b(n);
    rep(i,0,n)
        scanf("%d", &a[i]);
    rep(i,0,n)
        scanf("%d", &b[a[i] - 1]);
    //For 2 permutations a, b:
    //sgn(a) == sgn(b^-1) is equivalent to sgn(a * b) == 1

    vector<bool> seen(n, false);
    int swaps = n;
    rep(i,0,n) if (!seen[i])
    {
        swaps--;
        for (int j = i; !seen[j]; j = b[j] - 1)
            seen[j] = true;
    }
    printf((swaps & 1) ? "Impossible\n" : "Possible\n");
}

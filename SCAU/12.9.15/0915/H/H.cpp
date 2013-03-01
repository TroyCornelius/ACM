#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 101000;

int W[MAXN];
int H[MAXN];
int N, L; 

long long DP[MAXN];
int SA[MAXN];

void solve()
{
    int* S = SA;
  int rsz = 0;
  int wsum = DP[0] = 0;
  multiset<long long> bst;
  for(int i = 1, j = 1; i <= N; i++) {
      scanf("%d %d", &H[i], &W[i]);
    //cin >> H[i] >> W[i];

    for(S[rsz++] = 1; rsz > 1 && H[i - S[rsz - 1]] <= H[i]; rsz--) {
      bst.erase(bst.find(H[i - S[rsz - 1]] + DP[i - S[rsz - 1] - S[rsz - 2]]));
      S[rsz - 2] += S[rsz - 1];
    }
    bst.insert(H[i] + DP[i - S[rsz - 1]]);

    wsum += W[i];
    for(; wsum > L; j++) {
      wsum -= W[j];
      bst.erase(bst.find(H[j + S[0] - 1] + DP[j - 1]));
      if(--S[0] == 0) {
        ++S; rsz--;
      } else {
        bst.insert(H[j + S[0]] + DP[j]);
      }
    }

    DP[i] = *bst.begin();
  }
  cout << DP[N] << endl;    
}

int main() 
{
    freopen("H.in", "r", stdin);
    //freopen("H2.out", "w", stdout);
    
  while(cin>>N>>L)
  {
    solve();    
  }  
  
  while(1);
}

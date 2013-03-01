#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 5000000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

string S,ans,curans,non;
bool mus;
int main()
{
 int len,k,i,j,i0=0,d=0;
 cin >> S;
 mus =false;
 len = S.length();
 if(S[0]=='-'){ mus = true; i0=1;}
 for(i=i0;i<len;i++)
  if(S[i]=='.') break;
 d=-1;
 for(j=i-1;j>=i0;j--)
 {
  if(d%3==2)curans+=",";
  d+=1; 
   curans+=S[j];
 }
 if(mus) ans+="(";
 ans+="$";
 for(j=curans.length()-1;j>=0;j--)
  ans+=curans[j];
  ans+=".";
 
 d=i+2;
 for(i+=1;i<len;i++)
 {
  non+=S[i];    
  if(i==d)break;
 } 
  if(non.size()==0) non+="00";
  else if(non.size()==1) non+="0";
  ans+=non;
 if(mus)ans+=")";
 cout << ans << endl;
 return 0;
}

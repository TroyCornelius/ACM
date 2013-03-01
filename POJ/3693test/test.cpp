#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int maxn=211000;
char s[maxn];
int n,k,len1,len2;
int sa[maxn],rank[maxn],rank2[maxn],h[maxn];
int hi[maxn][30];
bool cmp0(int a,int b) {return s[a]<s[b];}
bool cmp(int a,int b)
{
    if (rank[a]!=rank[b]) return rank[a]<rank[b];
    return rank[a+k]<rank[b+k];
}

void make_sa()
{
    int i,j=0;
    for (i=0; i<n; i++)
        sa[i]=i;
    sort(sa,sa+n,cmp0);
    for (i=j=0; i<n; i++, j+=cmp0(sa[i-1],sa[i])) rank[sa[i]]=j;
    for (k=1; j<n-1; k<<=1)
    {
        sort(sa,sa+n,cmp);
        for (i=j=0; i<n; i++,j+=cmp(sa[i-1],sa[i])) rank2[sa[i]]=j;
        copy(rank2,rank2+n,rank);
    }
}

void calheight(char *r,int *sa,int n)
{
    int i,j,k=0;
    for (i=1; i<=n; i++) rank[sa[i]]=i;
    for (i=0; i<n;h[rank[i++]]=k)
        for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return ;
}

void make()
{
    int t=1;
    int i,j;
    for (i=0; i<n; i++) hi[i][0]=h[i];
    for (i=1; i<25; i++)
    {
        t*=2;
        if (t>n) break;
        for (j=0; j+t<=n; j++)
            if (hi[j][i-1]<hi[j+t/2][i-1])
                hi[j][i]=hi[j][i-1];
            else hi[j][i]=hi[j+t/2][i-1];
    }
}

int find(int x,int y)
{
    int temp=y-x+1;
    int t=0;
    while ((1<<t)<=temp) t++;
    t--;
    int a1=hi[x][t];
    int b1=hi[y-(1<<t)+1][t];
    return a1<b1?a1:b1;
}

int max(int a,int b) {return a>b?a:b;}
int main()
{
    freopen("data.in","r",stdin);
	freopen("test.out","w",stdout);
    int i,j,k,ca=1;
    int tmp,maxx,anss;
    while (~scanf("%s",s))
    {
        if (s[0]=='#') break;
        n=strlen(s);
       // cout << n<<endl;
        tmp=1<<30;
        s[n++]=0;
      //  cout << n<<endl;
        make_sa();
        calheight(s,sa,n-1);
        make();
        int ans=0;
        int anss=0;
        maxx=1;
        for (i=1; i<n; i++)
        {
            for (j=0; j+i<n;)
            {
                int a=rank[j],b=rank[j+i];
                int aa=j,bb=j+i;
                if (a>b) {swap(a,b); swap(aa,bb);}
                aa=j;
                k=find(a+1,b);
                int now=k/i;
                int jj=j-(i-k%i);
                if (jj>=0)
                {
                    a=rank[jj];b=rank[jj+i];
                     bb=jj+i;
                    if (a>b) swap(a,b);
                    if (find(a+1,b)>=i-k%i) {now++;aa=jj;}
                }
                // jj=0;

                if (ans<now) {ans=now; maxx=i; anss=max(0,aa);}
                if (ans==now && rank[anss]>rank[aa]){ans=now; maxx=i; anss=max(0,aa); }
                j+=(now+1)*i;
            }
        }
      //  cout << maxx << " " << " "<< anss;
     //   cout << n<<endl;
     //  cout<<ans+1<<" "<<anss<<" "<<maxx<<endl;
        printf("Case %d: ",ca++);
        for (int i=0; i<=maxx*(ans+1)-1; i++)
            printf("%c",s[anss+i]);
        cout << endl;

    }
    return 0;
}

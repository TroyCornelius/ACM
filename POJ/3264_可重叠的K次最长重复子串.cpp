#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define Maxn 20020
using namespace std;

class SuffixArray
{
    public:
    int *sa, *rank;
    int *height;
    int keyTypeMax, length;    
    SuffixArray(int *a, int n, int m)
    {
       keyTypeMax = max(n, m) + 5;
       sa = new int[n+10];
       rank = new int[keyTypeMax];
       height = new int[n+10];
       length = n+1;
       a[n] = 0;
       setSa(a, length);
       setHeight(a);                    
    }
    ~SuffixArray()
    {
       delete(sa);
       delete(rank);
       delete(height);                  
    }
    void setSa(int *a, int n)
    {
         int *cnt = new int[keyTypeMax];
         for (int i=0; i<keyTypeMax; i++) cnt[i] = 0;     //注意，不能用memset 
         for (int i=0; i<n; i++) cnt[rank[i] = a[i]]++;
         for (int i=0; i<keyTypeMax-1; i++) cnt[i+1] += cnt[i];
         for (int i=n-1; i>=0; i--) sa[--cnt[rank[i]]] = i;
         
         int *rankSt = new int[keyTypeMax];
         int *rankStPos = new int[n+10];
         for (int p=0, h=1, rankMax=keyTypeMax; p<n; h<<=1, rankMax=p)
         {
             p = 0;
             for (int i=n-h; i<n; i++) rankStPos[p++] = i;
             for (int i=0; i<n; i++) if (sa[i]>=h) rankStPos[p++] = sa[i] - h;
             for (int i=0; i<n; i++) rankSt[i] = rank[rankStPos[i]];
             for (int i=0; i<rankMax; i++) cnt[i] = 0;
             for (int i=0; i<n; i++) cnt[rankSt[i]]++;
             for (int i=0; i<rankMax-1; i++) cnt[i+1] += cnt[i];
             for (int i=n-1; i>=0; i--) sa[--cnt[rankSt[i]]] = rankStPos[i];
             
             swap(rank, rankStPos);
             rank[sa[0]] = 0;
             p = 1;
             for (int i=1; i<n; i++)
             {
                 if ((rankStPos[sa[i]] == rankStPos[sa[i-1]]) && 
                     (rankStPos[sa[i]+h] == rankStPos[sa[i-1]+h])) rank[sa[i]] = p-1;
                 else rank[sa[i]] = p++;
             }             
         }
         delete(rankSt);
         delete(rankStPos);
         delete(cnt);   
    }
    void setHeight(int *a)
    {
         int h = 0;
         for (int i=0; i<length; i++)
         {
             int r = rank[i];
             if (!r) height[r] = h = 0;
             else
             {
                 int pb = sa[r-1];
                 int off;
                 for (off=(h?h-1:0); a[i+off]==a[pb+off]; off++);
                 height[r] = h = off;                 
             }             
         }         
    }
    bool check(int len, int kk)
    {
         int tot=1;
         for (int i=0; i<length; i++)
         {
             if (height[i] >= len)
             {
                if (++tot >= kk) return true;                           
             }
             else tot = 1;
         }
         return false;
    }
    int getAns(int k)
    {
        int lo=0, hi=length, mid;
        while (lo <= hi)
        {
           mid = (lo+hi)>>1;
           if (check(mid, k)) lo = mid+1;
           else hi = mid - 1;              
        }
        return hi;  
    }
};
int d[Maxn], t[Maxn]; 
int main()
{
    int n, k, tmp=0;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) 
    {
        scanf("%d", &d[i]);
        tmp = max(tmp, d[i]);
    }
    SuffixArray sa(d, n, tmp+1);
    cout <<sa.getAns(k) <<endl;
    
    return 0;
    }

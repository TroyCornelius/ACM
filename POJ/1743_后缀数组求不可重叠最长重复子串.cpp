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
    bool check(int len)
    {
         if (!len) return true;
         int tmax = -1;
         int tmin = length;
         for (int i=0; i<length; i++)
         {
             if (height[i] < len) tmax = tmin = sa[i];
             else
             {
                 tmax = max(tmax, sa[i]);
                 tmin = min(tmin, sa[i]);
                 if (tmax - tmin > len) return true;                 
             } 
         }
         return false;
    }
    int getAns()
    {
        int lo=0, hi=length-1, mid;
        while (lo <= hi)
        {
           mid = (lo+hi)>>1;
           if (check(mid)) lo = mid+1;
           else hi = mid - 1;              
        }
        return hi+1;  
    }
};
int d[Maxn], t[Maxn], k, ans; 
int main()
{
    while (scanf("%d", &k))
    {
       if (k==0) break;
       for (int i=0; i<k; i++) scanf("%d", &t[i]);
       for (int i=0; i<k-1; i++) d[i] = t[i+1] - t[i] + 90;
       SuffixArray sa(d, k-1, 180);
       ans = sa.getAns();
       cout << (ans>=5?ans:0) <<endl;
    }
    
    return 0;
    }

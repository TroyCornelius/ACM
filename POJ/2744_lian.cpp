#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;

class SuffixArray
{
public:
    int *sa,*rank;
    int *height;
    int keyTypeMax,length;
    SuffixArray(int *a,int n,int m)
    {
        keyTypeMax = max(m,n)+5;
        sa = new int[n+10];
        rank = new int[keyTypeMax];
        height = new int[n+10];
        length = n+1;
        a[n] = 0;
        setSa(a,length);
        setHeight(a,length);
    }
    ~SuffixArray()
    {
        delete(sa);
        delete(rank);
        delete(height);
    }
    void setSa(int *a,int n)
    {
        int *cnt = new int[keyTypeMax];
        for (int i=0; i<keyTypeMax; i++) cnt[i] = 0;
        for (int i=0; i<n; i++) cnt[rank[i] = a[i]]++;
        for (int i=0; i<keyTypeMax-1; i++) cnt[i+1] += cnt[i];
        for(int i= n-1; i >= 0; i--) sa[--cnt[rank[i]]] = i;

        int *rankSt = new int[keyTypeMax];
        int *rankStPos = new int[n+10];
        for(int p=0,h=1,rankMax=keyTypeMax;p<n;h<<= 1,rankMax=p)
        {
            p = 0;
            for (int i=n-h; i<n; i++) rankStPos[p++] = i;
            for (int i=0; i<n; i++) if(sa[i]>=h) rankStPos[p++] = sa[i] - h;
            for (int i=0; i<n; i++) rankSt[i] = rank[rankStPos[i]];
            for (int i=0; i<rankMax; i++) cnt[i] = 0;
            for (int i=0; i<n; i++) cnt[rankSt[i]]++;
            for (int i=0; i<rankMax-1; i++) cnt[i+1] += cnt[i];
            for(int i=n-1;i>=0;i--) sa[--cnt[rankSt[i]]] = rankStPos[i];

            swap(rank,rankStPos);
            rank[sa[0]] = 0;
            p = 1;
            for (int i=1; i<n; i++)
            {
                if(rankStPos[sa[i]] == rankStPos[sa[i-1]]
                   &&rankStPos[sa[i]+h] == rankStPos[sa[i-1]+h])
                rank[sa[i]] = p-1;
                else rank[sa[i]] = p++;
            }
        }
        delete(rankStPos);
        delete(rankSt);
        delete(cnt);
    }
    void setHeight(int *a,int n)
    {
        int h = 0;
        for (int i=0; i<n; i++)
        {
            int r = rank[i];
            if(!r) height[r] = h = 0;
            else
            {
                int pb = sa[r-1];
                int off;
                for(off = (h?h-1:0);a[i+off]==a[pb+off];off++);
                height[r] = h = off;;
            }
        }
    }
    int getAns(int len1)
    {
        int ans = 0;
        for (int i=0; i<length; i++) 
        if(height[i]>ans)
        {
            int pa = sa[i],pb = sa[i-1];
            if(pb<pa) swap(pa,pb);
            if(pa<len1&&pb>len1) ans = max(ans,height[i]);
        }
        return ans;
    }
};
int arr[200200];
char s[100200];
int main()
{
    int len;
    scanf("%s",s);
    len = strlen(s);
    for (int i=0; i<len; i++) arr[i] = s[i];
    arr[len] = 1;
    scanf("%s",s);
    int len2 = strlen(s);
    for (int i=0; i<len2; i++) arr[len+i+1] = s[i];
    SuffixArray sa(arr,len+len2+1,256);
    cout<<sa.getAns(len)<<endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> d;
string s,s1,s2;
int next[3010],next1[3010],a[3010],b[3010];
int temp,sn,sn1,n,sn2,ans1,ans2,summ;

void kmp1()
{
    int i=0, j=0, sum=0;
    sn=s.size();
    int k=-1;
    for (i=0; i<sn; i++)
    {
        while (j>0 && s[i]!=s1[j])
            j=next[j-1];
        if (s[i]==s1[j])
            j++;
        else
            j=0;
        if (j==sn1)
        {
            k++;
            a[k]=i-sn1+1;
            j=next[j-1];
        }
    }
    ans1=k;
  //  cout << "1";
}

void kmp2()
{
    int i=0, j=0, sum=0;
    sn=s.size();
    int k=-1;
    for (i=0; i<sn; i++)
    {
        while (j>0 && s[i]!=s2[j])
            j=next1[j-1];
        if (s[i]==s2[j])
            j++;
        else
            j=0;
        if (j==sn2)
        {
            k++;
            b[k]=i-sn2+1;
            j=next1[j-1];
        }
    }
    ans2=k;
}

void working()
{
    next[0]=0;
    next[1]=0;
    sn1=s1.size();
    for(int i=1; i<sn1; i++)
    {
        temp = next[i - 1];
        while(temp && s1[temp]!=s1[i])
            temp=next[temp-1];
        if(s1[temp]==s1[i])
            next[i]=temp+1;
        else
            next[i]=0;
    }
    next1[0]=0;
    next1[1]=0;
    sn2=s2.size();
    for(int i=1; i<sn2; i++)
    {
        temp = next1[i - 1];
        while(temp && s2[temp]!=s2[i])
            temp=next1[temp-1];
        if(s2[temp]==s2[i])
            next1[i]=temp+1;
        else
            next1[i]=0;
    }
    kmp1();
    kmp2();
}
int main()
{
    cin>> s;
    cin >> s1;
    cin >> s2;
    working();
    summ=0;
    string word;
    d.clear();
    for (int i=0; i<=ans1; i++)
    {
        for (int j=0; j<=ans2; j++)
            if (b[j]>a[i])
                {
                    word=s.substr(a[i],b[j]+sn2-a[i]);
                 if (d[word]==0) summ++;
                    d[word]=1;
                }
    }
    cout << summ << endl;

    return 0;
}

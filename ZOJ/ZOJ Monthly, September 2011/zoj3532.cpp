#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stdlib.h>
#include <cassert>
#define pi acos(-1.0)
#define MAX 1010000000
using namespace std;

struct node
{
	int x,len;
	friend bool operator < (node n1,node n2)
	{
		return n2.len < n1.len;
	}
};

int d[1100];
int mat[1100][1100];
map <string,int> list;
map <string,int> ::iterator it;

int main()
{
	int cases=1;
	int i,j,k,m,n,p,dist;
	char ch;
	while(cin>>p>>m)
	{
		assert(p>=0&&p<=32000);
		assert(m>=0&&m<=3000);
		if(p==0&&m==0)
			break;
		for(i=0;i<1100;i++)
			for(j=0;j<1100;j++)
				mat[i][j]=MAX;
		list.clear();
		n=0;
		while(p--)
		{
			cin>>dist;
			assert(dist>=1&&dist<=1000000);
			string s,s1,s2;
			vector <int> l;
			while(cin>>s1>>s2)
			{
				ch=s2[s2.size()-1];
				s=s1+" "+s2.substr(0,s2.size()-1);
				it=list.find(s);
				if(it==list.end())
				{
					list.insert(make_pair(s,n));
					l.push_back(n++);
				}
				else l.push_back(it->second);
				if(ch==':')
					break;
			}
			getline(cin,s);
			for(i=0;i<l.size();i++)
				for(j=i+1;j<l.size();j++)
				{
					mat[l[i]][l[j]]=min(mat[l[i]][l[j]],dist);
					mat[l[j]][l[i]]=min(mat[l[j]][l[i]],dist);
				}			
		}

		for(i=0;i<n;i++)
			d[i]=MAX;
		node ss,tt;
		it=list.find("Kevin, Bacon");
		ss.x=it->second;
		ss.len=0;
		d[ss.x]=0;
		priority_queue <node> q;
		q.push(ss);

		while(!q.empty())
		{
			ss=q.top();
			q.pop();
			if(ss.len<d[ss.x])
				continue;
			for(i=0;i<n;i++)
			{
				tt.x=i;
				tt.len=ss.len+mat[ss.x][i];
				if(tt.len<d[tt.x])
				{
					d[tt.x]=tt.len;
					q.push(tt);
				}
			}
		}
		printf("Database %d\n",cases++);
		while(m--)
		{
			string s;
			getline(cin,s);
			it=list.find(s);
			cout<<s<<": ";
			if(d[it->second]!=MAX)
				cout<<d[it->second]<<endl;
			else cout<<"infinity"<<endl;
		}
		cout<<endl;
	}
	return 0;
}

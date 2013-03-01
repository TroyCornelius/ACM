//拓扑排序,poj 1094
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
bool gp[100][100];
int cnt[100];
char dr[100];
vector<int>q;
bool cmp(int a,int b)
{
	if( cnt[a]>cnt[b]||(cnt[a]==cnt[b]&&a>b))
		return 1;
	else
		return 0;	
}
int topsort(int x)
{
	int flag=1;
	memset(dr,'\0',sizeof(dr));
	memset(cnt,0,sizeof(cnt));
	q.clear();
	int i,j,k;
	for(i=0;i<x;i++)
	{
		for(j=0;j<x;j++)
		{
			if(gp[i][j])
				cnt[j]++;
		}
        q.push_back(i);	//加入vector
	}
		make_heap(q.begin(),q.end(),cmp);//从头到尾建立堆
	//push_heap(q.begin(),q.end(),cmp);将最后一个堆元素加入堆排
	for(i=0;i<x;i++)
	{
		if(cnt[q[0]]==0)
		{
			dr[i]=q[0]+'A';
			if(q.size()>1&&cnt[q[1]]==0)
				flag=2;
			for(j=0;j<x;j++)
			{
				if(gp[q[0]][j])
					cnt[j]--;
			}
			pop_heap(q.begin(),q.end(),cmp);//将堆头和堆尾交换，并维护
			q.pop_back();//删除堆尾的元素
		}
		else
			return 0;
	}
	return flag;
}
int main()
{
	int n,m,i,j,x,y,ans,h=0;
	char s[5];
	while(1)
	{
		h=0;
		cin>>n>>m;
		getchar();
		if(n==0&&m==0) break;
		memset(gp,0,sizeof(gp));
		for(i=1;i<=m;i++)
		{			
			scanf("%s",s);
			getchar();
			if(h==1)
				continue;
			x=s[0]-'A';
			y=s[2]-'A';
			if(s[1]=='>')
				gp[x][y]=1;
			else
				if(s[1]=='<')
					gp[y][x]=1;
			ans=topsort(n);
			if(ans==0)
			{
				printf("Inconsistency found after %d relations.\n",i);
				h=1;
			}
			else if(ans==1)
			{
				printf("Sorted sequence determined after %d relations: %s.\n",i,dr);
				h=1;
			}
		}
		if(h==0)
			printf("Sorted sequence cannot be determined.\n");
	}
	system("pause");
	return 0;
}

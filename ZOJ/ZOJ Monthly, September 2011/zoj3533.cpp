#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

struct SString{
	int F[100005];
	int Palindrome(char *s){
		int ans=0;
		int n=strlen(s);
		s--;
		for (int i=0;i<=n;i++) F[i]=0;
		// odd Palindrome
		int Max=0;
		int Maxi=0;
		for (int i=1;i<=n;i++){
			if (i>Max){
				int k=0;
				while (i-k>=1 && i+k<=n && s[i-k]==s[i+k]) k++;
				F[i]=k;
			}
			else{
				int p=Maxi-(i-Maxi);
				int k=F[p];
				if (i+k-1>Max) k=Max-i+1;
				while (i-k>=1 && i+k<=n && s[i-k]==s[i+k]) k++;
				F[i]=k;
			}
			if (i+F[i]-1>Max){
				Max=i+F[i]-1;
				Maxi=i;
			}
			ans=max(ans,F[i]*2-1);
		}
		//even Palindrome
		for (int i=0;i<=n;i++) F[i]=0;
		Max=0;
		Maxi=0;
		for (int i=2;i<=n;i++){
			if (i>Max){
				int k=1;
				while (i-k>=1 && i+k-1<=n && s[i-k]==s[i+k-1]) k++;
				F[i]=k-1;
			}
			else{
				int p=Maxi-(i-Maxi);
				int k=F[p];
				if (i+k-1>Max) k=Max-i+1;
				while (i-k>=1 && i+k-1<=n && s[i-k]==s[i+k-1]) k++;
				F[i]=k-1;
			}
			if (F[i]+i-1>Max){
				Max=F[i]+i-1;
				Maxi=i;
			}
			ans=max(ans,F[i]*2);
		}
		return ans;
	}
}String;

typedef unsigned int llu;
const int N=100005;
const int Len=1200;
const int P=13;
llu Pow[N];

struct Node{
	string str;
	vector <llu> Hash;
	vector <llu> rev_Hash;
	Node *pre,*next;
	bool rev;
	int n;
	Node(){rev=false; str.clear(); Hash.clear(); rev_Hash.clear(); pre=NULL; next=NULL;}

	void make_hash(){
		n=str.size();
		Hash.resize(str.size());
		rev_Hash.resize(str.size());
		Hash[n-1]=str[n-1];
		for (int i=n-2;i>=0;i--) Hash[i]=Hash[i+1]+str[i]*Pow[n-i-1];
		rev_Hash[0]=str[0];
		for (int i=1;i<n;i++) rev_Hash[i]=rev_Hash[i-1]+str[i]*Pow[i];
	}

	void push_down(){
		n=str.size();
		if (rev){
			string ts;
			ts.clear();
			for (int i=n-1;i>=0;i--) ts+=str[i];
			str=ts;
			rev=false;
		}
	}
};

int n,m,Qt;
char buf[N];
Node *Begin,*End,*Q[N];

void Link(Node *A,Node *B){ A->next=B; B->pre=A; }

void init_build(){
	Begin=new Node;
	End=new Node;
	{
		Node *tmp=new Node;
		Link(Begin,tmp);
		Link(tmp,End);
	}
	for (int i=1;i<=n;i++){
		if (End->pre->str.size()<Len)
			End->pre->str.push_back(buf[i]);
		else{
			Node *tmp=new Node;
			tmp->str.push_back(buf[i]);
			Link(End->pre,tmp);
			Link(tmp,End);
		}
	}
	for (Node *it=Begin->next;it!=End;it=it->next) it->make_hash();
}

pair <Node*,int> Get_Position(int p){
	int cnt=0;
	for (Node *it=Begin;it!=End;it=it->next)
		if (cnt+it->str.size()>=p) return make_pair(it,p-cnt-1);
		else cnt+=it->str.size();
}

Node *Split(Node *it,int p,int t){
	if (t==1){
		if (p==0) return it;
		it->push_down();
		Node *New=new Node;
		for (int i=0;i<p;i++)
			New->str.push_back(it->str[i]);
		it->str.erase(it->str.begin(),it->str.begin()+p);
		it->make_hash();
		New->make_hash();
		Link(it->pre,New);
		Link(New,it);
		return it;
	}
	else{
		if (p==it->str.size()-1) return it;
		it->push_down();
		Node *New=new Node;
		for (int i=0;i<=p;i++)
			New->str.push_back(it->str[i]);
		it->str.erase(it->str.begin(),it->str.begin()+p+1);
		it->make_hash();
		New->make_hash();
		Link(it->pre,New);
		Link(New,it);
		return New;
	}
}

llu Get_Hash(Node *i,int p){
	if (p>=i->str.size()) return 0;
	if (i->rev) return i->rev_Hash[i->str.size()-p-1];
	else return i->Hash[p];
}

void Union(Node *i){
	Node *j=i->next;
	i->push_down();
	j->push_down();
	i->str+=j->str;
	Link(i,j->next);
	delete j;
	i->make_hash();
}

void Try_Union(){
	for (Node *i=Begin->next;i!=End && i->next!=End;i=i->next)
		while (i!=End && i->next!=End && i->str.size()+i->next->str.size()<=Len)
			Union(i);
}

void Rev(int l,int r){
	Node *itl,*itr;
	int pl,pr;
	{ pair <Node*,int> T=Get_Position(l); itl=T.first; pl=T.second; }
	{ pair <Node*,int> T=Get_Position(r); itr=T.first; pr=T.second; }
	if (itl==itr){
		itl->push_down();
		int i=pl;
		int j=pr;
		while (i<j) swap(itl->str[i++],itl->str[j--]);
		itl->make_hash();
	}
	else{
		itl=Split(itl,pl,1);
		itr=Split(itr,pr,0);
		Node *pre=itl->pre;
		Node *next=itr->next;

		Qt=0;
		for (Node *it=itl;it!=itr;it=it->next) Q[++Qt]=it;
		Q[++Qt]=itr;
		for (int i=Qt;i>1;i--) Link(Q[i],Q[i-1]);
		for (int i=1;i<=Qt;i++) Q[i]->rev^=1;
		Link(pre,itr);
		Link(itl,next);
	}
}

void Modify(int p,char ch){
	pair <Node*,int> T=Get_Position(p);
	T.first->push_down();
	T.first->str[T.second]=ch;
	T.first->make_hash();
}

int Lcp(int l,int r){
	if (l>r) swap(l,r);
	Node *itl,*itr;
	int pl,pr;
	{ pair <Node*,int> T=Get_Position(l); itl=T.first; pl=T.second; }
	{ pair <Node*,int> T=Get_Position(r); itr=T.first; pr=T.second; }
	int ret=0;
	while (itl!=End && itr!=End){
		int L1=itl->str.size()-pl;
		int L2=itr->str.size()-pr;
		int L=min(L1,L2);
		llu h1=Get_Hash(itl,pl);
		llu h2=Get_Hash(itr,pr);
		if ((L1>L2)?
			( h1-Get_Hash(itl,itl->str.size()-(L1-L2)) == h2*Pow[L1-L2] )
			:( h2-Get_Hash(itr,itr->str.size()-(L2-L1)) == h1*Pow[L2-L1] )){
			ret+=L;
			pl+=L;
			pr+=L;
			if (pl==itl->str.size()){
				pl=0;
				itl=itl->next;
			}
			if (pr==itr->str.size()){
				pr=0;
				itr=itr->next;
			}
		}
		else{
			itl->push_down();
			itr->push_down();
			while (itl->str[pl++]==itr->str[pr++]) ret++;
			itl->make_hash();
			itr->make_hash();
			return ret;
		}
	}
	return ret;
}

void Palindrome(){
	int m=0;
	for (Node *it=Begin->next;it!=End;it=it->next){
		it->push_down();
		it->make_hash();
		for (int i=0;i<it->str.size();i++)
			buf[++m]=it->str[i];
	}
	printf("%d\n",String.Palindrome(buf+1));
}

void Clear(){
	for (Node *t=Begin;t!=End;){
		Node *tmp=t->next;
		delete t;
		t=tmp;
	}
	delete End;
}

int main(){
	Pow[0]=1;
	for (int i=1;i<N;i++) Pow[i]=Pow[i-1]*P;
	while (scanf("%s",buf+1)!=EOF){
		n=strlen(buf+1);
		assert(1 <= n && n <= 100000);
		init_build();
		scanf("%d",&m);
		assert(1 <= m && m <= 10000);
		int q_palindrome_time = 0;
		for (int i=0;i<m;i++){
			scanf("%s",buf);
			switch (buf[0]){
			case 'R':
				int l,r;
				scanf("%d%d",&l,&r);
				Rev(l,r);
				break;
			case 'M':
				int p;
				scanf("%d%s",&p,buf);
				Modify(p,buf[0]);
				break;
			case 'L':
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",Lcp(x,y));
				break;
			case 'P':
				q_palindrome_time++;
				Palindrome();
				break;
			}
			if (i%Len==0) Try_Union();
		}
		assert(q_palindrome_time <= 10);
		Clear();
	}
}

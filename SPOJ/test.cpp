#define MAXm 270000
int size[MAXm],n,Q,M,H;
LL col[MAXm],sum[MAXm];
void Defend() {
	int i;
	for( i = M ; i ; --i ) {
		sum[i] = sum[i<<1] + sum[(i<<1)^1];
		size[i] = size[i<<1] + size[(i<<1)^1];
	}	
} 
void PushToLeaf(int p) {
	sum[p] += size[p]*col[p];
	if( p < M ) {
		col[p<<1] += col[p];
		col[(p<<1)^1] += col[p];
	}
	col[p] = 0;
}
void Update( int p ) {
	int i;
	for( i = H ; i > -1 ; --i )
		PushToLeaf(p>>i);
}
LL Question( int s , int t ) {
	LL re = 0 ;
	Update(s);
	Update(t);
	for( ; s^t^1 ; s>>=1 , t>>=1 ) {
		if( !(s&1) ) {
			PushToLeaf(s^1);
			re += sum[s^1];
		}
		if( t&1 ) {
			PushToLeaf(t^1);
			re += sum[t^1];
		}
	}
	return re;
}
void Update1(int p) {
	for( p>>=1 ; p ; p>>=1 ) {
		PushToLeaf(p<<1);
		PushToLeaf((p<<1)^1);
		sum[p] = sum[p<<1] + sum[(p<<1)^1] ;	
	}	
}
void Modify(int s ,int t ,int c) {
	int l = s , r = t ;
	Update(s);
	Update(t);
	for( ; s^t^1 ; s>>=1 , t>>=1 ) {
		if( !(s&1) ) col[s^1] += c;
		if( t&1 ) col[t^1] += c;	
	}	
	Update1(l);
	Update1(r);
}
void Solve() {
	int i,s,e,c;
	char ch;
	for( i = 0 ; i < Q ; ++i ) {
		scanf("%*c%c%d%d",&ch,&s,&e);
		if( ch == 'Q' ) 
			cout<<Question(s+M-1,e+M+1)<<endl;
		else {
			scanf("%d",&c);
			Modify(s+M-1,e+M+1,c);
		}
	}	
}
int main() {
	int i;
	scanf("%d%d",&n,&Q);
	for( H = 1 ; (n+1) >> H ; ++H ) ;
	M = 1<<H ; 
	for( i = 1 ; i <= n ; ++i ) {
		scanf("%I64d", &sum[i+M]);
		size[i+M] = 1;
	}
	Defend();
	Solve();
	return 0;
}

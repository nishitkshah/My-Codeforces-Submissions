//22:23 08-09-2018
//22:26 08-09-2018
//22:37 08-09-2018
//22:42 08-09-2018 - 354A_2.cpp - misunderstood problem earlier

#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 100000
#define INF 10000000000LL

main(){
	int n, l, r, ql, qr, w[MAXN], sum=0, ls=0;
	long long s, smn=INF;
	cin >> n >> l >> r >> ql >> qr;
	for(int i=0; i<n; i++){
		cin >> w[i];
		sum += w[i];
	}
	
	for(int i=0; i<=n; i++){
		long long diff = 0LL;
		if((i-(n-i))>1) diff = (i-(n-i)-1)*ql;
		else if(((n-i)-i)>1) diff = ((n-i)-i-1)*qr;
		s = ls*l + (sum-ls)*r + diff;
		smn = min(s, smn);
		if(i!=n) ls += w[i];
	}
	cout << smn;
}

//22:34 08-09-2018
//22:39 08-09-2018
//22:56 08-09-2018
//23:03 08-09-2018

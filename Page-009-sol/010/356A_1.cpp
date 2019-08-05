//22:27 12-07-2018 to 22:40 12-07-2018 - Use segment Tree with lazy propagation
//16:50 17-07-2018

#include<iostream>

using namespace std;

int n, m, l, r, x, dp[400000]={0};

void fill(int v, int ind){
	if(!dp[ind]) dp[ind] = v;
}

void push(int x, int y, int v, int ind=0, int l=0, int r=n-1){
	if((x==l)&&(y==r)) fill(v, ind);
	int m = l+(r-l)/2;
	if(m>=y) push(x, y, v, 2*ind+1, l, m);
	else if(m<x) push(x, y, v, 2*ind+2, m+1, r);
	else{
		push(x, m, v, 2*ind+1, l, m);
		push(m+1, y, v, 2*ind+2, m+1, r);
	}
}

void flood(int v, int ind=0, int l=0, int r=n-1){
	if(l==r){
		fill(v, ind);
		if(l) cout << ' ';
		cout << dp[ind];
	}
	int m = l+(r-l)/2;
	if(dp[ind]) v = dp[ind];
	flood(v, 2*ind+1, l, m);
	flood(v, 2*ind+2, m+1, r);
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> l >> r >> x;
		if(l!=x) push(l, x-1, x);
		if(r!=x) push(x+1, r, x);
	}
	flood(0);
}

//17:22 17-07-2018

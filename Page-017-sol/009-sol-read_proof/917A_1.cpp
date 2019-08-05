//18:13 02-01-2019 - read editorial
//19:30 02-01-2019

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(b); a++)
#define N_ 5000

string s;
int o[N_]={0}, c[N_]={0}, q[N_]={0};
//int ro[N_]={0}, rc[N_]={0}, rq[N_]={0};
int for[N_][N_]={0}, bac[N_][N_]={0}, lr[N_][N_]={0};

void update(char c, int i){
if(c=='(') o[i]=1;
if(c==')') c[i]=1;
if(c=='?') q[i]=1;
}

int range(int* arr, int l, int r){
	if(l) return arr[r]-arr[l-1];
	return arr[r];
}

void calc_for(){
RE(i, 0, n){
	RE(j, i, n)
		if((range(o, i, j)+range(q, i, j)-range(c, i, j))>=0)
			for[i][j] = 1;
		else
			for[i][j] = 0;
	RE(j, i+1, n)
		for[i][j] += for[i][j-1];
}
}

void calc_bac(){
RE(i, 0, n){
	RE(j, i, n)
		if((range(c, i, j)+range(q, i, j)-range(o, i, j))>=0)
			bac[i][j] = 1;
		else
			bac[i][j] = 0;
	for(int j=n-2; j>=i; j--)
		bac[i][j] += bac[i][j+1];
}
}

main(){
cin >> s;
RE(i, 0, s.size()) update(s[i], i);
RE(i, 1, n) o[i] += o[i-1], c[i] += c[i-1], q[i] += q[i-1];
calc_for(); calc_bac();
int ans = 0;
RE(l, 0, n){
	RE(r, l, n){
		if( ((r-l+1)%2==0) && (range(for[l], l, r)==(r-l+1)) && (range(bac[l], l, r)==(r-l+1)) )
			ans++;
	}
}
cout << ans << '\n';
}

//20:19 02-01-2019

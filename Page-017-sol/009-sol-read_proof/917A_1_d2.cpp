//18:13 02-01-2019 - read editorial
//19:30 02-01-2019
//20:20 02-01-2019
//21:46 03-01-2019

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
//Incorrect Macro of for loop
#define N_ 5000

string s;
int n;
int o[N_]={0}, c[N_]={0}, q[N_]={0};
//int ro[N_]={0}, rc[N_]={0}, rq[N_]={0};
int forw[N_][N_]={0}, bac[N_][N_]={0};

void update(char ch, int i){
if(ch=='(') o[i]=1;
if(ch==')') c[i]=1;
if(ch=='?') q[i]=1;
}

int range(int* arr, int l, int r){
	if(l) return arr[r]-arr[l-1];
	return arr[r];
}

void calc_forw(){
RE(i, 0, n){
	RE(j, i, n)
		if((range(o, i, j)+range(q, i, j)-range(c, i, j))>=0)
			forw[i][j] = 1;
		else
			forw[i][j] = 0;
	RE(j, i+1, n)
		forw[i][j] += forw[i][j-1];
}
}

void calc_bac(){
RE(i, 0, n)
	RE(j, i, n)
		if((range(c, i, j)+range(q, i, j)-range(o, i, j))>=0)
			bac[j][i] = 1;	//i and j are swapped as we want to sum by right end
		else
			bac[j][i] = 0;	//i and j are swapped as we want to sum by right end
RE(j, 0, n)
	for(int i=n-2; i>=0; i--)
		if(j>=i)
			bac[j][i] += bac[j][i+1];
}

main(){
cin >> s;
n = s.size();
RE(i, 0, n) update(s[i], i);
RE(i, 1, n) o[i] += o[i-1], c[i] += c[i-1], q[i] += q[i-1];
calc_forw(); calc_bac();
int ans = 0;
RE(l, 0, n){
	RE(r, l, n){
		if( ((r-l+1)%2==0) && (forw[l][r]==(r-l+1)) && (bac[r][l]==(r-l+1)) )
			ans++;
	}
}
cout << ans << '\n';
cerr << s << ' ' << n << '\n';
RE(i, 0, n) cerr << o[i] << ' '; cerr << '\n';
RE(i, 0, n) cerr << c[i] << ' '; cerr << '\n';
RE(i, 0, n) cerr << q[i] << ' '; cerr << '\n';
RE(i, 0, n){
	RE(j, 0, n)
		cerr << forw[i][j] << ' ';
	cerr << '\n';
}
RE(i, 0, n){
	RE(j, 0, n)
		cerr << bac[i][j] << ' ';
	cerr << '\n';
}
}

//20:19 02-01-2019
//20:23 02-01-2019
//23:40 03-01-2019

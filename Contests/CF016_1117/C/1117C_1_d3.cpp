//21:42 18-02-2019
//22:09 18-02-2019
//22:34 18-02-2019
//22:38 18-02-2019
//22:45 18-02-2019
//23:08 18-02-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<cstdlib>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100010

long long x1, y1, x2, y2;
int n;
long long mxd=1LL, cntu[N_]={0LL}, cntr[N_]={0LL}, du, dr, valc[N_]={0LL}, oppc[N_]={0LL}, opmc[N_]={0LL};
string s;
char cu='O', cr='O';

bool chk(long long d){
long long r = d%n, q = d/n;
long long cdu, cdr;
cdu = q*cntu[n] + cntu[r];
cdr = q*cntr[n] + cntr[r];
cdu = min(cdu, du);
cdr = min(cdr, dr);
return 2*(cdu+cdr)>=(du+dr);
}

long long b_search(){
long long l=0LL, h=2*mxd+n, m;
while(l!=(h-1)){
	m = l+(h-l)/2;
	if(chk(m)) h = m;
	else l = m;
}
return h;
}

long long single_dir(){
char val, op1, op2;
if(cu=='O'){
	val = cr;
	op1 = 'U';
	op2 = 'D';
}
if(cr=='O'){
	val = cu;
	op1 = 'L';
	op2 = 'R';
}
//valc[N_]={0LL}, oppc[N_]={0LL}, opmc[N_]={0LL};
RE(i, 1, n+1){
	valc[i] += valc[i-1];
	oppc[i] += oppc[i-1];
	opmc[i] += opmc[i-1];
	if(s[i]==val) valc[i]++;
	if(s[i]==op1 || s[i]==op2) oppc[i]++;
	if(s[i]==op1) opmc[i]++;
	if(s[i]==op2) opmc[i]--;
}
long long d, q, r, sm, ans=0LL;
d = du+dr;
sm = valc[n]+oppc[n]-abs(opmc[n]);
q = d/sm;
r = d%sm;
ans += q*n;
RE(i, 0, n){
	long long sm2 = valc[i]+oppc[i]-abs(opmc[i]);
	if(sm2>=r){
		ans += i;
		break;
	}
}
return ans;
}

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
s = "z"+s;
if(y1<y2) cu = 'U';
if(y1>y2) cu = 'D';
if(x1<x2) cr = 'R';
if(x1>x2) cr = 'L';
RE(i, 1, n+1){
	cntu[i] = cntu[i-1];
	cntr[i] = cntr[i-1];
	if(s[i]==cu)
		cntu[i]++;
	if(s[i]==cr)
		cntr[i]++;
}
du = abs(y2-y1);
dr = abs(x2-x1);
if(cntu[n]) mxd = max(mxd, (du+cntu[n]-1LL)/cntu[n]);
if(cntr[n]) mxd = max(mxd, (dr+cntr[n]-1LL)/cntr[n]);
mxd *= n;
if(cu=='O' || cr=='O'){
	cout << single_dir() << '\n';
	return 0;
}
if(!cntu[n] && !cntr[n]){
	cout << "-1\n";
	return 0;
}
//cerr << chk(1LL);
cout << b_search() << '\n';
}

//22:34 18-02-2019
//22:36 18-02-2019
//22:40 18-02-2019
//23:07 18-02-2019
//23:07 18-02-2019
//23:10 18-02-2019
//23:10 18-02-2019

//23:37 06-11-2018 to 23:52 06-11-2018
//16:19 24-11-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200000
#define INF 2000000000

int n, w, len;
int b[N_], e[N_], bd[N_], ed[N_], s[2*N_], z[2*N_];

void z_dp(){
int l=0, r=0, p=1;
while(p<len){
	if(p>r){
		l = p;
		r = p-1;
		while(s[r+1]==s[r-l+1]) r++;
		z[p] = r-l+1;
	}else{
		int ext = z[p-l];
		if((p+ext) < r) z[p] = ext;
		if((p+ext) > r) z[p] = r-p+1;
		if((p+ext) == r){
			l = p;
			while(s[r+1]==s[r-l+1]) r++;
			z[p] = r-l+1;
		}
	}
	p++;
}
}

main(){
cin >> n >> w;
RE(i, 0, n) cin >> b[i];
RE(i, 0, w) cin >> e[i];
if(n<w){
	cout << "0\n";
	return 0;
}
if(w==1){
	cout << n << '\n';
	return 0;
}
RE(i, 0, n-1) bd[i] = b[i+1]-b[i];
RE(i, 0, w-1) ed[i] = e[i+1]-e[i];
RE(i, 0, w-1) s[i] = ed[i];
s[w] = INF;
RE(i, 0, n-1) s[w+i] = bd[i];
len = n+w-1;
z[0] = 0;
z_dp();
int ans = 0;
RE(i, 0, len)
	if(z[i]==(n-1)) ans++;
cout << ans << '\n';
}

//16:47 24-11-2018

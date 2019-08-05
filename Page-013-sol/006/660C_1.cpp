//21:31 21-09-2018
//21:35 21-09-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 300000

main(){
	int n, k, a[MAXN], cnt[(MAXN+1)/2][2]={0}, p=0, le=1;
	cin >> n >> k;
	RE(i, 0, n) cin >> a[i];
	RE(i, 0, n){
		if(a[i]!=le)
			if(a[i]==1)
				p++;
		cnt[p][a[i]]++;
		le = a[i];
	}
	p++;
	int l=0, r=0, sm=0, ans = cnt[0][1];
	while(r<=p){
		if(r<p&&(sm+cnt[r][0])<k){
			r++;
			sm += cnt[r][0];
		}
	}
	
}

//21:49 21-09-2018 - Incomplete - This idea would not work

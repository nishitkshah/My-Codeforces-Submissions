//16:02 08-08-2018
//16:22 08-08-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 200001

int n, a[MAXN], p, rn, cnt[MAXN]={0}, rem[MAXN], done[MAXN]={0};

main(){
	cin >> n;
	RE(i, 0, n){
		cin >> a[i];
		cnt[a[i]]++;
	}
	rn = 0;
	RE(i, 1, n+1){
		if(cnt[i]==0){
			rem[rn++] = i;
		}
	}
	p = 0;
	RE(i, 0, n){
		if(p==rn)
			break;
		if(cnt[a[i]]>1){
			if(a[i]>rem[p] || done[a[i]]){
				cnt[a[i]]--;
				cnt[rem[p]]++;
				a[i] = rem[p];
				p++;
			}else{
				done[a[i]] = 1;
			}
		}
	}
	cout << rn << '\n';
	RE(i, 0, n){
		if(i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
}

//16:36 08-08-2018
//16:39 08-08-2018

//09:27 29-06-2018
//09:33 29-06-2018

#include<iostream>

using namespace std;

main(){
	int n, m, a[101]={0}, l, r, h=0;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for(int i=0; i<m; i++){
		cin >> l >> r;
		if((a[r]-a[l-1])>0) h += a[r]-a[l-1];
	}
	cout << h << '\n';
}

//09:37 29-06-2018
//09:39 29-06-2018

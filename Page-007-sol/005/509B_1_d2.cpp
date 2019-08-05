//12:21 01-07-2018 to 12:27 01-07-2018
//13:16 01-07-2018
//13:23 01-07-2018
//13:26 01-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n, k, a[100], mn=100000, mx=-1;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if((mx-mn)>k){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<mn; j++){
			if(j) cout << " ";
			cout << "1";
		}
		for(int j=mn; j<a[i]; j++) cout << " " << j-mn+1;
		cout << '\n';
	}
}

//13:22 01-07-2018
//13:23 01-07-2018
//13:26 01-07-2018
//13:26 01-07-2018

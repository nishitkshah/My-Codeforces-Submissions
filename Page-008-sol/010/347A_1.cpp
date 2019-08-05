//16:23 03-07-2018
//16:25 03-07-2018

#include<iostream>
#include<algorithm>

using namespace std;

int n, a[100];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	swap(a[0], a[n-1]);
	for(int i=0; i<n; i++){
		if(i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';
}

//16:28 03-07-2018
//16:30 03-07-2018

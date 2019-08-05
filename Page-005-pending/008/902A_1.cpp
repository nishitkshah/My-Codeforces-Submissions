//18:35 28-06-2018
//18:38 28-06-2018

#include<iostream>

using namespace std;

int n, m, x, y, ind=-1;
int a[100], b[100];

main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		if(ind==-1 || (y>b[ind] && x<m)){
			ind++;
			a[ind] = x;
			b[ind] = y;
		}
	}
	n = ind+1;
	for(int i=1; i<n; i++){
		if(a[i]>b[i-1]){
			cout << "NO\n";
			return 0;
		}
	}
	if(b[n-1]<m) cout << "NO\n";
	else cout << "YES\n";
}

//18:50 28-06-2018
//18:51 28-06-2018

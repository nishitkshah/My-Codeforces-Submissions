//22:41 18-10-2018
//23:00 18-10-2018

#include<iostream>
#include<vector>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 1000

int n, l[N_], r[N_], v[N_]={0};

main(){
cin >> n;
RE(i, 0, n) cin >> l[i];
RE(i, 0, n) cin >> r[i];
bool isValid = true;
for(int mx=n; mx>0; mx--){
	vector<int> m;
	//Find max remaining and assign value to them
	RE(i, 0, n)
		if(!l[i] && !r[i] && !v[i]){
			m.push_back(i);
			v[i] = mx;
		}
	//Adjust array
	int lc=0, rc=m.size();
	RE(i, 0, n){
		if(l[i] || r[i]){
			l[i] -= lc;
			r[i] -= rc;
			if(l[i]<0 || r[i]<0) isValid = false;
		}
		if(!l[i] && !r[i] && !v[i]){
			lc++;
			rc--;
		}
	}
}
RE(i, 0, n) if(l[i] || r[i]) isValid = false;
if(isValid){
	cout << "YES\n";
	RE(i, 0, n){
		if(i) cout << ' ';
		cout << v[i];
	}
	cout << '\n';
}else cout << "NO\n";
}

//23:18 18-10-2018

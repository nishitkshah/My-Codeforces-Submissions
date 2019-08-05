//10:33 30-05-2018
//10:36 30-05-2018
///10:40 30-05-2018

#include<iostream>
#include<algorithm>

using namespace std;

int n, hp=-1, mp=-1, h, m, mx=0, ct=1; 

main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> h >> m;
		if((h==hp)&&(m==mp)) ct++;
		else ct = 1;
		mx = max(mx, ct);
		hp = h; mp = m;
	}
	cout << mx << "\n";
}

//10:39 30-05-2018
//10:41 30-05-2018
//10:41 30-05-2018

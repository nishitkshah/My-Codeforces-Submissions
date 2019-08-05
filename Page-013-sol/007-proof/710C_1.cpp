//16:16 13-10-2018
//16:39 13-10-2018

#include<iostream>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

main(){
	int n;
	cin >> n;
	int o=1; e=2, l=n/2, r=(n+1)/2, rev=0;
	RE(i, 0, n){
		RE(j, 0, n){
			if(j) cout << ' ';
			if(l<j && j<r){
				cout << o;
				o += 2;
			}else{
				cout << e;
				e += 2;
			}
		}
		if(!l) rev = 1;
		if(!rev) l--, r++;
		else l++, r--;
		cout << '\n';
	}
}

//16:47 13-10-2018

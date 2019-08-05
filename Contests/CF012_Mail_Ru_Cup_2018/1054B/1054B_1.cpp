//22:24 18-10-2018
//22:33 18-10-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 100000

int n, a[N_], mx[N_]={0};

main(){
	cin >> n;
	RE(i, 0, n) cin >> a[i];
	if(a[0]){
		cout << "1\n";
		return 0;
	}
	mx[0] = 0;
	RE(i, 1, n){
		mx[i] = max(mx[i-1], a[i]);
		if(mx[i] > (mx[i-1]+1)){
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}

//22:38 18-10-2018
//22:40 18-10-2018

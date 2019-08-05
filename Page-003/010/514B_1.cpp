//11:40 31-05-2018
//11:43 31-05-2018

#include<iostream>

using namespace std;

int n, x0, y0, x[1000], y[1000], dp[1000], s=0;

main(){
	cin >> n >> x0 >> y0;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
		x[i] -= x0; y[i] -= y0;
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(x[i]*y[j]==x[j]*y[i]){
				dp[i] = 0;
				break;
			}
		}
		s += dp[i];
	}
	cout << s << "\n";
}

//11:53 31-05-2018
//11:54 31-05-2018

//17:32 20-08-2018 to 17:36 20-08-2018
//17:40 20-08-2018

#include<iostream>
#include<map>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 200000

int n, l[MAX], r[MAX], dp[MAX*3]={0};
map<int, int> m;

main(){
	cin >> n;
	RE(i, 0, n){
		cin >> l[i] >> r[i];
		m[l[i]] = 1;
		m[r[i]] = 1;
	}
	int c=0;
	for(auto p: m){
		m[p.first] = c++;
	}
	RE(i, 0, n){
		dp[m[l[i]]]++;
		dp[m[r[i]]+1]--;
	}
	RE(i, 1, 3*MAX){
		dp[i] += dp[i-1];
		if(dp[i]>2){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}

//17:54 20-08-2018
//17:56 20-08-2018

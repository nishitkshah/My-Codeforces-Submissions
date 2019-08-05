#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int arr[100000+1000], lcis[100000+1000];

int main(){
	ios::sync_with_stdio(0);
	int n, a, mx;
	cin >> n;
	REP(i, 0, n){
		cin >> a;
		arr[a-1] = i;
	}
	lcis[0] = 1;
	mx = 1;
	REP(i, 1, n){
		if(arr[i-1]<arr[i]) lcis[i] = lcis[i-1]+1;
		else lcis[i] = 1;
		if(mx<lcis[i]) mx = lcis[i];
	}
	cout << n-mx;
	return 0;
}

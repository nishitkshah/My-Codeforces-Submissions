#include<iostream>

using namespace std;

int n;

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	if(n%2) cout << 0;
	else{
		n/=2;
		int cnt = n-1;
		if(n%2==0) cnt--;
		cnt /=2;
		cout << cnt;
	}
	return 0;
}

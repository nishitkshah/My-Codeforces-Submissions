#include<iostream>

using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;	//Gave error without this as n was 0
	a--;
	a += b;
	a %= n;
	a += n;
	a %= n;
	a++;
	cout << a;
	cout << "\n";
	return 0;
}

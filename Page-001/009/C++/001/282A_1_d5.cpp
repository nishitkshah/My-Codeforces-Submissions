#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	int x = 0, n;
	char c[5];
	cin >>n;
	for(int i=0; i<n; i++){
		cout << c << endl;
		cin >> c;
		if((c[0]=='+')||(c[2]=='+')){
			x++;
			cout << "P\n";}
		else{
			x--;
			cout << "M\n";}
		cout << x<<endl;
	}
	return 0;
}


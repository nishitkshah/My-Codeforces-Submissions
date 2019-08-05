//16:56 16-05-2018
//16:58 16-05-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int lk[14] = {4, 44, 444, 7, 77, 777, 47, 74, 447, 474, 744, 774, 747, 477};

int main(){
	int n;
	cin >> n;
	REP(i, 0, 14)
		if(n%lk[i]==0){
			cout << "YES\n";
			return 0;
		}	
	cout << "NO\n";
	return 0;
}

//17:04 16-05-2018
//17:05 16-05-2018

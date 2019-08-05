//12:14 28-06-2018
//12:16 28-06-2018

#include<iostream>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int a[6];

main(){
	int sum = 0;
	REP(i, 0, 6){
		cin >> a[i];
		sum += a[i];
	}
	if(sum%2==0){
		REP(i, 0, 4){
			REP(j, i+1, 5){
				REP(k, j+1, 6){
					if(2*(a[i]+a[j]+a[k])==sum){
						cout << "YES\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

//12:21 28-06-2018
//12:22 28-06-2018

//17:53 01-06-2018
//17:56 01-06-2018
//18:16 01-06-2018

#include<iostream>

using namespace std;

int dp[5][5] = {0},
dx[]={0,1,0,-1,0},
dy[]={0,0,1,0,-1},
t;

main(){
	for(int i=1; i<4; i++)
		for(int j=1; j<4; j++){
			cin >> t;
			for(int k=0; k<5; k++){
				int cx=i+dx[k], cy=j+dy[k];
				dp[cx][cy] += t;
			}
		}
	for(int i=1; i<4; i++){
		for(int j=1; j<4; j++){
			cout << 1-(dp[i][j]%2);
			if(j!=3) cout << " ";
		}
		cout << "\n";
	}
}

//18:06 01-06-2018
//18:16 01-06-2018
//18:17 01-06-2018

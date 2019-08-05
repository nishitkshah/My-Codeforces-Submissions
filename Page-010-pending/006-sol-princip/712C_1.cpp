//16:31 07-08-2018
//17:07 07-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int x, y[3];
	cin >> x >> y[0];
	y[1]=y[0], y[2]=y[0];
	int cnt=0;
	while(y[0]!=x){
		cnt++;
		y[0] = min(x, y[1]+y[2]-1);
		sort(y, y+3);
	}
	cout << cnt << '\n';
}

//17:15 07-08-2018
//17:17 07-08-2018

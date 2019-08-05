//19:49 19-10-2018
//19:55 19-10-2018
//17:11 20-10-2018

#include<iostream>
#include<algorithm>

using namespace std;

int x[3], y[3];

bool between(int a, int b, int m){
	if(a<=m && m<=b) return true;
	return false;
}

bool chk_2_match(int i, int j, int o){
	if( x[i]==x[j] && !between(min(y[i], y[j]), max(y[i], y[j]), y[o]))
		return true;
	if( y[i]==y[j] && !between(min(x[i], x[j]), max(x[i], x[j]), x[o]))
		return true;
	return false;
}

main(){
for(int i=0; i<3; i++) cin >> x[i] >> y[i];
int ans = 3;
if((x[0]==x[1] && x[1]==x[2]) || (y[0]==y[1] && y[1]==y[2]))
	ans = 1;
else if(chk_2_match(0, 1, 2)||chk_2_match(1, 2, 0)||chk_2_match(2, 0, 1))
	ans = 2;
cout << ans << '\n';
}

//20:00 19-10-2018
//17:19 20-10-2018

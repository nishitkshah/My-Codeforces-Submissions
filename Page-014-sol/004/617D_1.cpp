//19:49 19-10-2018
//19:55 19-10-2018

#include<iostream>

using namespace std;

bool chk_2_match(int a[3]){
	if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2]) return true;
	return false;
}

main(){
int x[3], y[3];
for(int i=0; i<3; i++) cin >> x[i] >> y[i];
int ans = 3;
if((x[0]==x[1] && x[1]==x[2]) || (y[0]==y[1] && y[1]==y[2]))
	ans = 1;
else if(chk_2_match(x)||chk_2_match(y))
	ans = 2;
cout << ans << '\n';
}

//20:00 19-10-2018
//20:01 19-10-2018

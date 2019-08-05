//16:24 02-06-2019
//16:44 02-06-2019
//17:06 02-06-2019

#include<iostream>
#include<string>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)

string s;

void qy(long long x, long long y){
cout << "? " << x << " " << y << endl;
cin >> s;
}

void ans(long long x){
cout << "! " << x << endl;
cin >> s;
}

main(){
cin >> s;	//Consume "start"
while(1){
	qy(0, 1);
	if(s[0]=='e') return 0;
	if(s[0]=='x'){
		ans(1);
		continue;
	}
	long long l=1, r=2, m;
	qy(l, r);
	while(s[0]!='x'){
		if(s[0]=='e') return 0;
		l = l<<1;
		r = r<<1;
		qy(l, r);
	}
	while(l!=(r-1)){
		m = l + (r-l)/2;
		qy(l, m);
		if(s[0]=='x')
			r = m;
		if(s[0]=='y')
			l = m;
		if(s[0]=='e')
			return 0;
	}
	ans(r);
	if(s[0]=='e') break;
}
return 0;
}

//17:04 02-06-2019
//17:07 02-06-2019
//17:10 02-06-2019

//22:37 07-10-2018
//22:41 07-10-2018
//22:56 07-10-2018

#include<iostream>

using namespace std;

int n, ax, ay, bx, by, cx, cy;
int u[2], r[2];

void calc(int i, int x, int y){
	u[i]=0, r[i]=0;
	if((x-ax)>0) u[i] = 1;
	if((y-ay)>0) r[i] = 1;
}

main(){
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
	calc(0, bx, by);
	calc(0, cx, cy);
	if(u[0]==u[1] && r[0]==r[1])
		cout << "YES\n";
	else
		cout << "NO\n";
}

//22:53 07-10-2018
//22:57 07-10-2018
//23:01 07-10-2018

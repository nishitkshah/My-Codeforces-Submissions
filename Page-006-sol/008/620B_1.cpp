//09:00 29-06-2018
//09:02 29-06-2018

#include<iostream>

using namespace std;

#define MAX 1000001

int l[MAX] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void init(){
	for(int i=10; i<MAX; i++)
		l[i] = l[i%10]+l[i/10];
}

main(){
	init();
	int a, b, sum=0;
	cin >> a >> b;
	for(int i=a; i<=b; i++) sum += l[i];
	cout << sum << '\n';
}

//09:07 29-06-2018
//09:08 29-06-2018

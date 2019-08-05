//11:19 31-05-2018
//11:22 31-05-2018

#include<iostream>
#include<cstdio>

using namespace std;

char s[200001];

main(){
	int n;
	cin >> n;
	s[0] = s[1] = 'a';
	for(int i=2; i<n; i++) s[i] = s[i-2]=='a' ? 'b' : 'a';
	s[n] = '\0';
	printf("%s\n", s);
}

//11:25 31-05-2018
//11:27 31-05-2018

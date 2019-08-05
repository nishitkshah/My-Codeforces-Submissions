//20:05 01-05-2019
//20:12 01-05-2019
//20:44 01-05-2019
//21:02 01-05-2019

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define N_ 200

int n, a[N_];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
RE(i, 0, n) cin >> a[i];
bool inf = false;
int sum = 0;
RE(i, 0, n-1){
	if((a[i]+a[i+1])==5)
		inf = true;
	else
		sum += a[i]+a[i+1];
	if(a[i]==3 && ((i+2)<n) && a[i+2]==2) sum--;
}
if(inf)
	cout << "Infinite\n";
else
	cout << "Finite\n" << sum << '\n';
}

//20:20 01-05-2019
//21:01 01-05-2019
//21:03 01-05-2019
//21:03 01-05-2019

//20:15 15-05-2018
//20:17 15-05-2018

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;

int main(){
	cin >> n;
	v.resize(n);
	for(int a=0; a<n; a++){
		cin >> v[a];
	}
	sort(v.begin(), v.end());
	cout << v[(n-1)/2] << "\n";
	return 0;
}

//20:19 15-05-2018
//20:21 15-05-2018

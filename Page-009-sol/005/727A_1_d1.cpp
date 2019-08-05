//16:53 09-07-2018
//17:03 09-07-2018
//17:12 09-07-2018

#include<iostream>
#include<vector>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	vector<int> v;
	cin >> a >> b;
	v.push_back(b);
	while(b>a){
		if(b%2==0){
			b /= 2;
			v.push_back(b);
			continue;
		}
		if(b%10==1){
			b /= 10;
			v.push_back(b);
			continue;
		}
		break;
	}
	if(b!=a){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n" << v.size() << '\n';
	for(int i=v.size()-1; i>=0; i--){
		cout << v[i];
		if(i) cout <<  " ";
	}
	cout << '\n';
}

//17:12 09-07-2018
//17:13 09-07-2018
//17:15 09-07-2018

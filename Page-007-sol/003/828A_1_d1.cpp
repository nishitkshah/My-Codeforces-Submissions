//20:36 29-06-2018
//20:38 29-06-2018
//20:42 29-06-2018

#include<iostream>

using namespace std;

main(){
	int n, a, b, ans=0, t;
	cin >> n >> a >> b;
	for(int i=0; i<n; i++){
		cin >> t;
		switch(t){
			case 1:
				if(a) a--;
				else
					if(b){
						b--;
						a++;
					}else ans++;
				break;
			case 2:
				if(b) b--;
				else ans++;
				break;
		}
	}
	cout << ans << '\n';
}

//20:41 29-06-2018
//20:42 29-06-2018

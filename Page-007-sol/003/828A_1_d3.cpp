//20:36 29-06-2018
//20:38 29-06-2018
//20:42 29-06-2018
//20:44 29-06-2018
//12:13 01-07-2018

#include<iostream>

using namespace std;

main(){
	int n, a, b, one_in_2=0, ans=0, t;
	cin >> n >> a >> b;
	for(int i=0; i<n; i++){
		cin >> t;
		switch(t){
			case 1:
				if(a) a--;
				else
					if(b){
						b--;
						one_in_2++;
					}else
						if(one_in_2){
							one_in_2--;
						}else ans++;
				break;
			case 2:
				if(b) b--;
				else ans+=2;
				break;
		}
	}
	cout << ans << '\n';
}

//20:41 29-06-2018
//20:42 29-06-2018
//20:44 29-06-2018
//12:15 01-07-2018
//12:18 01-07-2018

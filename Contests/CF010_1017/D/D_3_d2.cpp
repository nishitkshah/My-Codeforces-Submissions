//21:16 08-08-2018
//21:28 08-08-2018
//21:52 08-08-2018
//21:58 08-08-2018
//22:02 08-08-2018 - D_2.cpp
//22:21 08-08-2018
//11:05 09-08-2018 - D_3.cpp
//11:15 09-08-2018
//11:22 09-08-2018

#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=b; a<(c); a++)
#define MAX 500010

int n, m, q, w[12];

main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

cin >> n >> m >> q;

RE(i, 0, n)
	cin >> w[i];

unordered_map<int, int> d;

RE(i, 0, m){
	string s;
	cin >> s;
	int num = stoi(s, NULL, 2);
	if(d.count(num))
		d[num] = d[num]+1;
	else
		d[num] = 1;
}

unordered_map<int, int> val;

RE(i, 0, 1<<n){
	int v = 0;
	RE(ind, 0, n){
		if((i&(1<<(n-1-ind)))==0){
			v += w[ind];
		}
	}
	val[i] = v;
}

unordered_map<int, int> dp;

RE(num, 0, 1<<n){
	RE(k, 0, 101){
		int cnt = 0;
		for(auto pr = d.begin(); pr!=d.end(); pr++){
			int s = pr->first;
			if(val[s^num] <= k)
				cnt += (pr->second);
		}
		dp[1000*num + k] = cnt;
	}
}

RE(i, 0, q){
	string t;
	int k;
	cin >> t >> k;
	int num = stoi(t, NULL, 2);
	cout << dp[1000*num + k] << '\n';
}

/*
cerr << "d: ";
for(auto pr = d.begin(); pr!=d.end(); pr++){
	cerr << pr->first << " " << (pr->second) << endl;
}
cerr << "val: ";
for(auto pr = val.begin(); pr!=val.end(); pr++){
	cerr << pr->first << " " << (pr->second) << endl;
}
*/

}

//21:51 08-08-2018
//21:53 08-08-2018
//22:00 08-08-2018
//22:18 08-08-2018
//22:28 08-08-2018
//11:13 09-08-2018
//11:17 09-08-2018
//11:24 09-08-2018
//11:25 09-08-2018

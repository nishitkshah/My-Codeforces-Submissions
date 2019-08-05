//16:47 17-08-2018 to 17:02 17-08-2018
//17:39 17-08-2018
//23:54 17-08-2018
//13:10 18-08-2018

#include<iostream>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define MAX 10000001
#ifdef DBG
	#define PE(x) cerr << x << '\n'
	#define PI(x) cerr << #x ": " << x << '\n'
#endif
#ifndef DBG
	#define PE(x)
	#define PI(x)
#endif

int pr[MAX]={0}, pal[MAX]={0};

inline void gen_primes(){
	pr[0] = pr[1] = 1;
	PE("Before prime");
	RE(i, 2, MAX){
		//if(i%1000==0) PI(i);
		if(i*i>MAX) break;
		if(pr[i]==0){
			for(int j=i; (i*j)<MAX; j++){
				//if(i>45555) PI(i*j);
				pr[i*j] = 1;
			}
		}
	}
	PE("After prime");
	//Reverse flag
	RE(i, 0, MAX){
		pr[i] = 1-pr[i];
	}
}

inline void gen_pal(){
	PE("Before pal");
	pal[0] = 0;
	//Even length Palindromes
	RE(i, 1, MAX){
		int rem = i;
		long long rev = i;
		while(rem){
			rev = 10*rev + rem%10;
			rem /= 10;
		}
		if(rev<MAX){
			pal[(int)(rev)] = 1;
		}else{
			break;
		}
	}
	//Odd length Palindromes
	RE(i, 1, MAX){
		int rem = i;
		rem /= 10;
		long long rev = i;
		while(rem){
			rev = 10*rev + rem%10;
			rem /= 10;
		}
		if(rev<MAX){
			pal[(int)(rev)] = 1;
		}else{
			break;
		}
	}
	PE("After pal");
}

main(){
	gen_primes();
	gen_pal();
	int p, q, mx=-1;
	long long cntpr=0LL, cntpal=0LL;
	cin >> p >> q;
	RE(i, 0, MAX){
		cntpr += pr[i];
		cntpal += pal[i];
		if((cntpr*q)<=(cntpal*p)){
			mx = i;
		}
	}
	if(mx==-1) cout << "Palindromic tree is better than splay tree\n";
	else cout << mx << '\n';
}

//18:15 17-08-2018
//00:13 18-08-2018
//13:11 18-08-2018
//13:11 18-08-2018

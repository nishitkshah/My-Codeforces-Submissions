//20:35 03-07-2018
//20:39 03-07-2018
//20:50 03-07-2018

#include<cstdio>
#include<algorithm>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define IA(a, i, x, y) for(int i=(x); i<(y); i++) scanf("%d", &(a[i]));

main(){
	int n, k, a[5001]={0}, sum[5001]={0};
	double avg[5001]={0};
	scanf("%d%d", &n, &k);
	IA(a, i, 1, n+1);
	RE(i, 1, n+1) sum[i] = sum[i-1]+a[i];
	RE(i, k, n+1){
		RE(j, 0, i-k+1){
			avg[i] = max(avg[i], (sum[i]-sum[j])/(double(i-j)));
		}
	}
	double mx = 0;
	RE(i, k, n+1) mx = max(mx, avg[i]);
	printf("%.9f\n", mx);
}

//20:49 03-07-2018
//20:53 03-07-2018
//20:54 03-07-2018

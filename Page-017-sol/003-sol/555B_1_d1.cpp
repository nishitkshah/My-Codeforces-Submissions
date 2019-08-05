//22:32 15-12-2018 to 22:41 15-12-2018
//23:02 15-12-2018
//23:31 15-12-2018

#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>

using namespace std;

#define RE(a, b, c) for(int a=(b); a<(c); a++)
#define SI(a) scanf("%d", &(a))
#define SL(a) scanf("%I64d", &(a))
#define N_ 200000

struct gap{
	long long mx, mn;
	int id, aid;
};

bool cmp(struct gap &a, struct gap &b){
	if(a.mx!=b.mx) return a.mx<b.mx;
	if(a.mn!=b.mn) return a.mn<b.mn;
	return a.id<b.id;
}

bool cmp_output(struct gap &a, struct gap &b){
	return a.id<b.id;
}

int n, m;
long long l[N_], r[N_], a[N_];
gap d[N_];
set< pair<long long, int> > st;

main(){
SI(n); SI(m);
SL(l[0]); SL(r[0]);
RE(i, 1, n){
	SL(l[i]); SL(r[i]);
	d[i-1].id = i-1;
	d[i-1].aid = -1;
	d[i-1].mx = r[i]-l[i-1];
	d[i-1].mn = l[i]-r[i-1];
}
RE(i, 0, m){
	SL(a[i]);
	st.insert({a[i], i});
}
sort(d, d+n-1, cmp);
sort(a, a+m);
bool matches = true;
RE(i, 0, n-1){
	auto it = st.lower_bound({d[i].mn, 0});
	if(it==st.end() || (it->first)>d[i].mx){
		matches = false;
		break;
	}
	d[i].aid = it->second;
	st.erase(it);
}
if(matches){
	printf("YES\n");
	sort(d, d+n-1, cmp_output);
	RE(i, 0, n-1){
		if(i) printf(" ");
		printf("%d", d[i].aid);
	}
	printf("\n");
}else{
	printf("NO\n");
}
}

//23:30 15-12-2018
//23:32 15-12-2018

#include<iostream>

using namespace std;

int main(){
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	int b_needed=0, p_xtra=0;
	if(x1>=x2) p_xtra+=(x1-x2)/2;
	else b_needed+=x2-x1;
	if(y1>=y2) p_xtra+=(y1-y2)/2;
	else b_needed+=y2-y1;
	if(z1>=z2) p_xtra+=(z1-z2)/2;
	else b_needed+=z2-z1;
	if(b_needed<=p_xtra) cout << "Yes";
	else cout << "No";
	return 0;
}

#include<iostream>
using namespace std;
int m[40], t;
int main (){
	cin >> t;
	while(t--){
		for(int i = 0; i < 40; i++)
			m[i] = 0;
		long long int x;
		int k, cnt = 0;
		cin >> x >> k;
		while(x){
			cnt++;
			m[x % k]++;
			x /= k;
		}
		if(m[0] + m[1] == cnt)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

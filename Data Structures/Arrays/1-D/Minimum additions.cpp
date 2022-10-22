#include <bits/stdc++.h>
using namespace std;
 
void Run_Case()
{
   	int64_t n, k, sum = 0;
   	cin >> n >> k;
   	vector<int64_t> v(n);
   	for(int64_t i = 0; (int64_t)i < n; i++) 
	   	cin >> v[i], sum += v[i];
   	if (sum / n <= k) 
	   	cout << "0" << endl;
   	else 
	   	cout << sum / (k + 1) - n + 1 << endl;
}
 
int main()
{
   	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   	int T; 
   	cin >> T; 
   	while(T--)
      	Run_Case();
   	return 0;
}

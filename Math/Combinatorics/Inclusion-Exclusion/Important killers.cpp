#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int POWER[55], t;
  	POWER[0] = 1;
  	for(int i = 1; i < 35; i++) 
	  	POWER[i] = POWER[i - 1] << 1;
  	cin >> t;
  	vector<bool> prime(55, false);
  	prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = true;
  	prime[23] = prime[29] = prime[31] = prime[37] = prime[41] = prime[43] = prime[47] = true;
  	while(t--) 
	{
    	int p, x, cnt = 0;
    	cin >> p >> x;
    	vector<long long> V;
    	vector<int> pr;
    	for(int i = 2; i <= p; i++) 
			if(prime[i])
			{ 
				pr.push_back(i); 
				cnt++;
			}
    	int power = 1 << cnt;
    	for(int i = 0; i < power; i++) 
		{
      		long long now = 1;
      		for(int j = 0; j < cnt; j++) 
			{
        		if(POWER[j] & i) 
          			now *= 1LL * pr[j];
      		}
      		V.push_back(now);
    	}
    	sort(V.begin(), V.end());
    	if((int)V.size() >= x) 
			cout << V[x - 1] << endl;
    	else 
			cout << "-1" << endl;
  	}
  	return 0;
}

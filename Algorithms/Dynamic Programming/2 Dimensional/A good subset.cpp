#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long T, n, K, a[5005];
    bitset<5005>S1, S2;
	cin >> T;
	while(T--)
    {
		cin >> n >> K;
        long long ans = n;
		for(long long i = 1; i <= n; i++) 
            cin >> a[i];
		S1.reset();
        S2.reset();
        S1[0] = 1;
		sort(a + 1, a + n + 1);
		for(long long i = 1; i <= n; i++)
        {
			if(a[i] >= K)
            {
                ans--;
                continue;
            }
			S2 = S1;
            bool fgg = 0;
			S1|=(S1<<a[i]);
			for(long long j = i + 1; j <= n; j++) 
                S2|=(S2<<a[j]);
			for(long long j = K - a[i]; j < K; j++) 
                if(S2[j])
                {
                    ans = i - 1;
                    fgg = 1;
                    break;
                }
			if(fgg) 
                break;
		} 
		cout << ans << endl;
	}
	return 0;
}

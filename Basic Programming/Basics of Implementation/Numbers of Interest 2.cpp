#include<bits/stdc++.h>
using namespace std; 
 
int main() 
{
	  ios::sync_with_stdio(0); cin.tie(0);
	  int spf[1000001], sum_divisors[1000001];
        for(int i = (2); i <= (1000001); ++i) 
            if (!spf[i]) 
                for (int j = i; j <= 1000001; j += i) 
                    if (!spf[j]) 
                        spf[j] = i;
	  for(int i = (1); i <= (1000001); ++i) 
        for(int m = i; m <= 1000001; m += i) 
            sum_divisors[m] += i;
	  for(int i = (1); i <= (1000001); ++i) 
    {
		    sum_divisors[i] -= i;
		    sum_divisors[i] += sum_divisors[i - 1];
		    spf[i] += spf[i - 1];
	  }
	  int T; 
    cin >> T; 
    while (T--) 
    {
		    int n;
		    cin >> n;
		    cout << (spf[n] + sum_divisors[n]) % n << endl;
	  }
}

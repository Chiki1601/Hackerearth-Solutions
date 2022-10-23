#include<bits/stdc++.h>
using namespace std;
 
unsigned long long solve(int n)
{
    vector<int> pf;
    unsigned long long sum = 0;
   	int pf1 = 0, pf2 = 0, gcd = n;
   	if(gcd % 2 == 0)
	{
	 	pf.push_back(2);
	 	while(gcd % 2 == 0)
	 	   	gcd /= 2;
   	}
   	for (int j = 3; j <= sqrt(gcd); j += 2)
   	{
	   	if(gcd % j == 0)
		{
		 	pf.push_back(j);
		 	while(gcd % j == 0)
		 	   	gcd /= j;
		}
   	}
   	if(gcd > 2)
	   	pf.push_back(gcd);
   	if(pf.size() < 2)
	 	return 0;
   	unsigned long long int m = 0;
   	int i = 0;
   	for(auto iter = pf.begin(); iter != pf.end(); iter++)
   	{
	 	pf1 = *iter;
	 	for(auto iter2 = iter + 1; iter2 != pf.end(); ++iter2)
	 	{
	   		pf2 = *iter2;
   	   		for(i = 1; pf1 * pf2 * i < n; ++i)
	   		{
		 		bool match = false;
		 		for(auto iter3 = pf.begin(); iter3 != iter2; iter3++)
		 		{
			 		if(*iter3 != pf1 && *iter3 != pf2 && (i % *iter3 == 0))
			  		{
				  		match = true;
				  		break;
			  		}
		 		}
		 		if(match)
					continue;
		 		m = pf1 * pf2 * i;
		 		sum += m;
	   		}
	 	}
   	}
   	return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        cout << solve(n) << " ";
    }
}

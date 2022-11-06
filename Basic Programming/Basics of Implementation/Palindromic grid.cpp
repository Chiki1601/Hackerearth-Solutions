#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t; 
	cin >> t;
	while(t--)
	{
 		int m, n;
		cin >> n >> m;
		int count[26] = {0}, single = 0, pairs = 0; 
		string ent;
		for(int i = 0; i < n; i++)
		{
			cin >> ent; 
			for(int j = 0; j < m; j++) 
				++count[ent[j] - 'a'];
		}
		for(int i = 0; i < 26; i++)
		{
    			if(count[i] % 2)
    			{
        			++single;
     			}
    			count[i] = count[i] >> 1;
    			if(count[i] % 2)
    			{
        			++pairs;
    			}
		}
		//cout << "P : " << pairs << "s: " << single << flush;
		bool flag = false;
		if(m % 2)
		{
    			if(n % 2)
    			{
        			if(single == 1 && pairs <= (m / 2 + n / 2))
            				flag = true;
        			else
            				flag = false;
    			}
    			else
    			{
        			if(single == 0 && pairs <= n / 2)
            				flag = true;
        			else
            				flag = false;
    			}
		}
		else
		{
    			if(n % 2)
    			{
        			if(single == 0 && pairs <= m / 2)
            				flag = true;
        			else
            				flag = false;
    			}
    			else
    			{
        			if(single == 0 && pairs == 0)
            				flag = true;
        			else
            				flag = false;
    			}
		}
		if(flag)
    			cout << "YES"<< endl << flush;
		else
    			cout << "NO" << endl << flush;
 	}
 	return 0;
}

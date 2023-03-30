#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	int k;
	cin >> s >> k;
	int n = s.size(), a = 0, c = 0, x = 0, i = 9;
	while(i >= 0 and c <= k and x < n - k) 
    {
		for(auto j = a; j < min(n, a + k - c + 1); j++)
        {
			if(s[j] - '0' == i) 
            {
				c += j - a;
				a = j + 1;
				cout << i;
				i = 10;
				x++;
				break;
			}
		}
		i--;
	}
}

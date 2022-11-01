#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int levels, q;
	long long s, k, pro = 1, pow[100], x, val;
	cin >> levels >> s;
	assert(levels >= 1 && levels <= 30);
	assert(s >= 1 && s <= 1000000000000000000);
	cin >> q;
	pow[0] = 1;
	for(int i = 1; i <= levels - 1; i++)
	{
		pro *= 2;
		pow[i] = pro;
	}
	if(levels > 1) 
		x = (s - ((pro - 1) * (pro - 1))) / (pro * 2 - 1) + 1;
	else 
		x = s + 1;
	long long root = ((levels < 2) ? 0 : pow[levels - 2] - 1);
	bool type;
	while(q--)
	{
		cin >> type;
		if(type == 0)
		{
			cin >> val;
			long long cnt = levels - 3;
			val -= x;
			if(levels > 1 && val == pow[levels - 1] - 1)
			{
				for(int i = 1; i <= levels - 1; i++)
					cout << "r";
				cout << "\n";
			}
			else
			{
				long long temp = root;
				if(val == temp)
					cout << "root" << "\n";
				else
				{
					while(temp != val)
					{
						if(temp > val)
						{
							cout << "l";
							temp -= pow[cnt--];
						}
						else
						{
							cout << "r";
							temp += pow[cnt--];
						}
					}
					cout << "\n";
				}
			}
		}
		else
		{
			cin >> k;
			int l = log2(k) + 1;
			long long a;
			if(l == levels)
				a = x;
			else 
				a = x + pow[levels - l - 1] - 1;
			long long n = k - pow[l - 1] + 1, d = pow[levels - l];
			cout << a + (n - 1) * d << "\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long mal[100005], mar[100005], mil[100005], mir[100005], ar[100005], a[100005], mins[100005], mp[100005], fre[1000005];
int n, x, k;
stack <int> st;

void great(bool f)
{
	if(f)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i == 0)
				st.push(i);
			else
			{
				while(!st.empty() and a[i] > a[st.top()])
				{
					mar[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty())
		{
			mar[st.top()] = n + 1;
			st.pop();
		}
	}
	else
	{
		for(int i = n; i >= 1; i--)
		{
			if(i == n)
				st.push(i);
			else
			{
				while(!st.empty() and a[i] > a[st.top()])
				{
					mal[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty())
		{
			mal[st.top()] = 0;
			st.pop();
		}
	}
}

void smal(bool f)
{
	if(f)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i == 0)
				st.push(i);
			else
			{
				while(!st.empty() and a[i] < a[st.top()])
				{
					mir[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty())
		{
			mir[st.top()] = n + 1;
			st.pop();
		}
	}
	else
	{
		for(int i = n; i >= 1; i--)
		{
			if(i == n)
				st.push(i);
			else
			{
				while(!st.empty() and a[i] < a[st.top()])
				{
					mil[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty())
		{
			mil[st.top()] = 0;
			st.pop();
		}
	}
}

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x >> k;
	assert(1 <= n and n <= 100000);
	assert(1 <= x and x <= n);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		fre[a[i]]++;
		assert(0 <= a[i] and a[i] <= 1000000);
	}
	for(int i = 0; i <= 1000000; i++)
		assert(fre[i] <= 1);
	great(true);
	great(false);
	smal(true);
	smal(false);
	long long mas = 0, mis = 0;
	for(int i = 1; i <= n; i++)
	{
		mp[i] = ((mar[i] - i) * (i - mal[i])) - ((mir[i] - i) * (i - mil[i]));
		mas += ((mar[i] - i) * (i - mal[i])) * a[i];
		mis += (mir[i] - i) * (i - mil[i]) * a[i];
	}
	sort(mp + 1, mp + n + 1, cmp);
	int c = 0;
	long long sum = mas - mis;
	for(int i = 1; i <= x; i++)
	{
		if(mp[i] > 0)
			sum += mp[i];
	}
	cout << sum << "\n";
	return 0;
}

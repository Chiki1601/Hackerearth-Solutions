#include <bits/stdc++.h>
using namespace std;
long long fib[1005];
 
string decipher(long long x) 
{
	string s;
	int i = 0;
	while(fib[i + 1] <= x) 
		++i;
	for(; i > 0; --i) 
	{
		if(x >= fib[i]) 
		{
			x -= fib[i];
			s += "1";
		}
		else 
			s += "0";
	}
	return s;
}
 
long long len_up_to(long long x) 
{
	long long len = 0;
	for(int i = 0; true; ++i) 
	{
		if(x >= fib[i]) 
		{
			len += (i + 1) * fib[i];
			x -= fib[i];
		}
		else 
			return len + (i + 1) * x;
	}
}
 
int main() 
{
	long long low, high, skip = 0;
	cin >> low >> high;
	fib[0] = fib[1] = 1;
	for(int i = 2; fib[i - 1] <= 2 * high + 1005; ++i) 
		fib[i] = fib[i - 1] + fib[i - 2];
	for(int i = 0; true; ++i) 
	{
		if(len_up_to(skip + (1LL << i)) < low)
			skip += 1LL << i;
		else 
		{
			for(--i; i >= 0; --i)
				if(len_up_to(skip + (1LL << i)) < low)
					skip += 1LL << i;
			break;
		}
	}
	low -= len_up_to(skip);
	high -= len_up_to(skip);
	string s;
	for(long long x = skip + 1; (int)s.length() <= high - low + 205; ++x)
		s += decipher(x);
	for(int i = low - 1; i < (int)high - 1; ++i) 
		cout << s[i];
	puts("");
}

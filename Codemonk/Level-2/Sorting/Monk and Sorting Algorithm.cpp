#include<bits/stdc++.h>
using namespace std;
long long arr[1000005], output[1000005];

void countsort(int n, long long place)
{
  	int i, freq[100000] = {0};
  	for(i = 0; i < n; i++)
  	{
    	freq[(arr[i] / place) % 100000]++;
    	output[i] = 0;
  	}
  	for(i = 1; i < 100000; i++)
    	freq[i] += freq[i - 1];
  	for(i = n - 1; i >= 0; i--)
  	{
    	output[freq[(arr[i] / place) % 100000] - 1] = arr[i];
    	freq[(arr[i] / place) % 100000]--;
  	}
  	for(i = 0; i < n; i++)
  	{
    	arr[i] = output[i];
    	cout << arr[i] << " ";
  	}
  	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n;
  	cin >> n;
  	long long maxx = -1;
  	for(int i = 0; i < n; i++)
  	{
    	cin >> arr[i];
    	maxx = max(maxx, arr[i]);
  	}
  	for(long long i = 1; maxx / i; i *= 100000)
      	countsort(n, i);
  	return 0;
}

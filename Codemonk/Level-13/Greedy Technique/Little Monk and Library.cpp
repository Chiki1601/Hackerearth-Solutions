#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n;
  	cin >> n;
  	vector<long long int> books(n, 0), location(n, 0);
  	assert(n > 0 and n <= 1000000);
  	for(int i = 0; i < n; i++)
  	{
    	cin >> books[i];
    	assert(books[i] > 0 and books[i] <= 1000000000);
  	}
  	for(int i = 0; i < n; i++)
  	{
    	cin >> location[i];
    	assert(location[i] > 0 and location[i] <= 1000000000);
  	}
  	sort((books).begin(), (books).end());
  	sort((location).begin(), (location).end());
  	assert(books.size() == n);
  	assert(location.size() == n);
  	long long int ans = 0;
  	for(int i = 0; i < n; i++)
    	ans += abs(location[i] - books[i]);
  	cout << ans << "\n";
  	return 0;
}

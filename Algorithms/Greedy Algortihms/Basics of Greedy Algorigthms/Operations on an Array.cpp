#include <iostream>
#include <climits>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long int n, i, j, cost, ans = LLONG_MAX;
	std::cin >> n;
	long a[n];
	for (i = 0; i < n; i++)
		std::cin >> a[i];
	for (i = 0; i < n; i++)
	{
		for (j = 0, cost = 0; j < n; j++)
			cost += std::min(a[j], std::abs(a[j] - a[i]));
		ans = std::min(ans, cost);
	}
	std::cout << ans;
	return 0;
}

#include <iostream>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k, i, count = 0, sum = 0;
	std::cin >> n >> k;
	int a[n];
	for (i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a + n);
	for (i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum <= k)
		{
			count++;
		}
	}
	std::cout << count;
	return 0;
}

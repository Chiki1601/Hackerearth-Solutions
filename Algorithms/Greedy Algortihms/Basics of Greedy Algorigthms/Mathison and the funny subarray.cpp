#include <iostream>
#include <unordered_map>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int i, a[n];
	for (i = 0; i < n; i++)
		std::cin >> a[i];
	std::unordered_map<int, int> map1;
	std::unordered_map<int, int> map2;
	for (i = 0; i < n; i++)
	{
		map1[a[i]] = i;
		map2[a[n - 1 - i]] = n - 1 - i;
	}
	int maxLen = 1;
	for (i = 0; i < n; i++)
	{
		int tmp = map1[a[i]] - map2[a[i]] + 1;
		if (maxLen < tmp)
			maxLen = tmp;
	}
	std::cout << maxLen;
	return 0;
}

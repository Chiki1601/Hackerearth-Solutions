#include <iostream>
#include <string>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int i, j, pos = 0;
	std::string s[n];
	for (i = 0; i < n; i++)
		std::cin >> s[i];
	for (i = 1; i < n; i++)
	{
		if (s[i] > s[pos])
			pos = i;
	}
	std::cout << pos + 1;
	return 0;
}

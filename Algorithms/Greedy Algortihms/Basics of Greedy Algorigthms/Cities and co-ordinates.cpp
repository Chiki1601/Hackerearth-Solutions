#include <iostream>
#include <cmath>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;
		long numX, numY;
		std::cin >> numX >> numY;
		long maxX = numX;
		long minX = numX;
		long maxY = numY;
		long minY = numY;
		while (--n)
		{
			std::cin >> numX >> numY;
			maxX = std::max(maxX, numX);
			minX = std::min(minX, numX);
			maxY = std::max(maxY, numY);
			minY = std::min(minY, numY);
		}
		long diffX = std::abs(maxX - minX);
		long diffY = std::abs(maxY - minY);
		long ans = std::max(diffX, diffY);
		std::cout << ans * ans << "\n";
	}
	return 0;
}

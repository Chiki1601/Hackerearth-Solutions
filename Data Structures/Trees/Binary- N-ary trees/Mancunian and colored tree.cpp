#include <iostream>
#include <vector>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	int c;
	std::cin >> n >> c;
	std::vector<std::vector<int>> arr(n + 1, std::vector<int>(2, 0));
	arr[1][0] = -1;
	for (int i = 2; i <= n; i++)
		std::cin >> arr[i][0];
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i][1];
	for (int i = 1; i <= n; i++) {
		int pos = arr[i][0];
		while (pos != -1 && arr[pos][1] != arr[i][1])
			pos = arr[pos][0];
		std::cout << pos << " ";
	}
	return 0;
}

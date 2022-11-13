#include <iostream>
#include <vector>
 
bool knapsack(std::vector<std::vector<int>> vec, std::vector<int> sum, int n) {
	if (!(sum[0] || sum[1] || sum[2] || sum[3]))
		return true;
	if (n == 0)
		return false;
	bool flag = false;
	for (int i = 0; i < 4; i++)
		if (vec[n - 1][i] > sum[i]) {
			flag = true;
			break;
		}
	if (flag)
		return knapsack(vec, sum, n - 1);
	std::vector<int> newSum(4, 0);
	for (int i = 0; i < 4; i++)
		newSum[i] = sum[i] - vec[n - 1][i];
	return knapsack(vec, newSum, n - 1) || knapsack(vec, sum, n - 1);
}
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::vector<int> sum(4, 0);
	for (int i = 0; i < 4; i++)
		std::cin >> sum[i];
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> vec(n, std::vector<int>(4, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> vec[i][j];
	std::cout << (knapsack(vec, sum, n) ? "YES" : "NO");
	return 0;
}

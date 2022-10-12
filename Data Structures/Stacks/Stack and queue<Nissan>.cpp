#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long int n;
	long long int k;
	std::cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	long long int sum = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];
	long long int mx = sum;
	for (long long i = 0; i < k - 1; i++) {
		sum = (sum + arr[n - i - 1] - arr[k - 1 - i]);
		if (sum >= mx)
			mx = sum;
	}
	std::cout << mx;
	return 0;
}

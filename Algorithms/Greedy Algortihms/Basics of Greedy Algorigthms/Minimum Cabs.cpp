#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int a[1441] = {0};
	int n;
	std::cin >> n;
	int h1, m1, h2, m2;
	while (n--) {
		std::cin >> h1 >> m1 >> h2 >> m2;
		int t1 = h1 * 60 + m1;
		int t2 = h2 * 60 + m2;
		a[t1]++;
		a[t2 + 1]--;
	}
	int ans = a[0];
	for (int i = 1; i < 1441; i++) {
		a[i] += a[i - 1];
		ans = std::max(ans, a[i]);
	}
	std::cout << ans;
	return 0;
}

#include <iostream>
#include <string>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int a[6] = {0};
		std::string brackets = "(){}[]";
		for (char ch:s)
			a[brackets.find(ch)]++;
		std::cout << 2 * (std::min(a[0], a[1]) + std::min(a[2], a[3]) + std::min(a[4], a[5])) << "\n";
	}
	return 0;
}

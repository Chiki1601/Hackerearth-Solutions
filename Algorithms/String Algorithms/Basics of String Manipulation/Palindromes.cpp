#include <iostream>
#include <string>
#include <algorithm>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string s;
	std::cin >> s;
	int i;
	int len = s.length();
	for (i = 0; i < len - 1; i++)
		if (s[i] != s[i + 1])
			break;
	std::cout << (i == len - 1 ? 0 : std::equal(s.begin(), s.begin() + len / 2, s.rbegin()) ? len - 1 : len);
	return 0;
}

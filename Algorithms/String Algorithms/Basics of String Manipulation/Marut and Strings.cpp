#include <iostream>
#include <string>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	if (t == 0 || t > 10)
		std::cout << "Invalid Test";
	else {
		while (t--) {
			std::string s;
			std::cin >> s;
			int len = s.length();
			if (len == 0 || len > 100)
				std::cout << "Invalid Input\n";
			else {
				int upper = 0;
				int lower = 0;
				for (char ch:s) {
					if ('a' <= ch && ch <= 'z')
						lower++;
					else if ('A' <= ch && ch <= 'Z')
						upper++;
				}
				lower == 0 && upper == 0 ? std::cout << "Invalid Input\n" : std::cout << std::min(lower, upper) << "\n";
			}
		}
	}
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s1;
        std::cin >> s1;
        std::string s2(s1);
        std::reverse(s2.begin(), s2.end());
        if (s1 == s2) {
            std::cout << "Palindrome\n";
        } else {
            long long int prod = 1;
            for (char ch:s1)
                prod *= (ch - 96);
            std::cout << prod << "\n";
        }
    }
    return 0;
}

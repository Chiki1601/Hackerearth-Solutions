#include<iostream>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, l, m, x, cnt = 0, totalWays = 0;
    std::cin >> n >> l >> m;
    while (n--) {
        std::cin >> x;
        if (x <= l)
            cnt++;
        if (cnt == m) {
            cnt--;
            totalWays++;
        }
        if (x > l)
            cnt = 0;
    }
    std::cout << totalWays;
    return 0;
}

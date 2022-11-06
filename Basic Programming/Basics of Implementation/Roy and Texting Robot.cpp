#include<iostream>
#include<string>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    int t;
    char keypad[10][5] = {
            {'.', ',', '?', '!', '1'},
            {'a', 'b', 'c', '2'},
            {'d', 'e', 'f', '3'},
            {'g', 'h', 'i', '4'},
            {'j', 'k', 'l', '5'},
            {'m', 'n', 'o', '6'},
            {'p', 'q', 'r', 's', '7'},
            {'t', 'u', 'v', '8'},
            {'w', 'x', 'y', 'z', '9'},
            {'_', '0'},
    };
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        int lastPos = 0, totalTime = 0;
        for (char ch:s) {
            for (int i = 0; i < 10; i++) {
                bool flag = false;
                for (int j = 0; j < 5; j++)
                    if (keypad[i][j] == ch) {
                        totalTime += j + 1 + (i != lastPos);
                        lastPos = i;
                        flag = true;
                        break;
                    }
                if (flag)
                    break;
            }
        }
        std::cout << totalTime << "\n";
    }
    return 0;
}

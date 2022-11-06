#include<iostream>
#include<vector>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n, 0);
		for (int j = 0; j < n; j++)
			std::cin >> a[j];
 
		int ans = 0;
		for (int k = 0; k < n;) {
			int current_c = a[k];
			ans++;
			if (current_c == 1) {
				k++;
				continue;
			}
			int no_of_people = current_c - 1;
			int l;
			for (l = k + 1; l < n; l++) {
				if (!no_of_people)
					break;
				if (a[l] == current_c)
					no_of_people--;
			}
			if (no_of_people)
				ans = -1;
			k = l;
		}
 
		ans == -1 ? std::cout << "Invalid Data\n" : std::cout << ans << "\n";
	}
	return 0;
}

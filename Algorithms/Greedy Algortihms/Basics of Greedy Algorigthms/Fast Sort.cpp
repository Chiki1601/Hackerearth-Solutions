#include <iostream>
#include <string>
int main()
{
	std::ios_base::sync_with_stdio();
	std::cin.tie(NULL);
	int t;
	std::string s1, s2, s3;
	std::cin >> t;
	while (t--)
	{
		s3 = "";
		std::cin >> s1 >> s2;
		int cnt[26] = {0};
		for (char ch : s2)
			cnt[ch - 'a']++;
		for (char ch : s1)
			for (int i = 1; i <= cnt[ch - 'a']; i++)
				s3 += ch;
		std::cout << s3 << "\n";
	}
	return 0;
}

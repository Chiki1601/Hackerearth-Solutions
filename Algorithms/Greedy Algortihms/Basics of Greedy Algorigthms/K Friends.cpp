#include <bits/stdc++.h>
using namespace std;
 
long long Gifts(vector<int> S, int K)
{
	std::sort(S.begin(), S.end());
	long long giftCount = 0;
	int i;
	for (i = 0;; i++)
	{
		giftCount += S[i];
		if (!--K)
			break;
	}
	giftCount = giftCount + S[i] * (S.size() - i - 1);
	return giftCount;
}
 
int main()
{
 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++)
	{
		int N;
		cin >> N;
		vector<int> S(N);
		for (int i_S = 0; i_S < N; i_S++)
		{
			cin >> S[i_S];
		}
		int K;
		cin >> K;
 
		long long out_;
		out_ = Gifts(S, K);
		cout << out_;
		cout << "\n";
	}
}

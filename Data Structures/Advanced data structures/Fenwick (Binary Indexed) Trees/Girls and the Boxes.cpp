#include<bits/stdc++.h>
using namespace std;
int n, k, S[2][1000010], ans, B[1000010];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    pair<int, int> A[1000010];
	for(int i = 0; i < n; i++)
    {
		cin >> B[i] >> A[i].second;
		A[i].first = i;
	}
	for(int i = n; i < 2 * n; i++)
    {
		A[i] = make_pair(i, B[i - n]);
		B[i] = A[i - n].second;
	}
	n *= 2;
	sort(A, A + n, [](pair<int, int> a, pair<int, int> b)
    {
		if(B[a.first] != B[b.first]) 
            return B[a.first] < B[b.first];
		return a.second > b.second;
	});
	for(int i = 0; i < n; i++)
		A[i].first = A[i].first >= n / 2;
	fill(S[0], S[0] + 1000010, 1000000010);
	fill(S[1], S[1] + 1000010, 1000000010);
	for(int i = 0; i < n; i++)
    {
		int pos = lower_bound(S[1 - A[i].first], S[1 - A[i].first] + 1000010, A[i].second) - S[1 - A[i].first];
		if(pos > 0) 
			S[A[i].first][pos - 1] = min(S[A[i].first][pos - 1], A[i].second);
		S[A[i].first][pos] = min(S[A[i].first][pos], A[i].second);
		ans = max(ans, pos + 1);
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	cin.tie(nullptr)->sync_with_stdio(false);
	const auto next_int = [](){ int num; cin >> num; return num; };
	const auto N = next_int(), M = next_int();
	vector<int> row_min(N,INT_MAX), col_min(M, INT_MAX);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j) 
		{
			const auto A = next_int();
			row_min[i] = min(row_min[i],A);
			col_min[j] = min(col_min[j],A); 
		}
	const auto max = [](const vector<int> &vec) 
	{
		return *max_element(vec.begin(),vec.end()); 
	};
	cout << min(max(row_min),max(col_min)); 
}

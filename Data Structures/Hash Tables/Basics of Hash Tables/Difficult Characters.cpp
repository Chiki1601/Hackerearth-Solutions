#include <bits/stdc++.h> 
using namespace std;
 
bool compare(pair<int, char> p1, pair<int, char> p2)
{
	if(p1.first != p2.first)
		return p1.first < p2.first;
	return p1.second > p2.second;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	string context;
	cin >> T;
	while(T--)
	{
		vector<pair<int, char>> freq;
		for(char ch = 'a'; ch <= 'z'; ch++)
			freq.push_back({0, ch});
		cin >> context;
		for(int i = 0; i < context.length(); i++)
			freq[context[i] - 'a'].first++;
		sort(freq.begin(), freq.end(), compare);
		for (auto x : freq)
			cout << x.second << ' ';
		cout << endl;
	}
	return 0;
}

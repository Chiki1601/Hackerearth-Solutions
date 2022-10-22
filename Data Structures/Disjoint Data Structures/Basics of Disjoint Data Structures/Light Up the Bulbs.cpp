#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long long int N, cost = 0;
	cin >> N;
	if(N < 2)
	{
        cout << 0; 
        return 0;
    }
	vector<vector<long long int>> p(N, vector<long long int>(2));
	for(auto &x : p)
	   cin >> x[0] >> x[1];
	vector<long long int> vlevel(N, 0);
	vlevel[0] = INT_MAX;
	for(int i = 1; i < N; i++)
	   vlevel[i] = (long long int)pow(p[0][0] - p[i][0], 2) + (long long int)pow(p[0][1] - p[i][1], 2);
	for(int i = 1; i < N; i++)
	{
		int index = min_element(vlevel.begin(), vlevel.end()) - vlevel.begin();
		cost += vlevel[index];
		vlevel[index] = INT_MAX;
		for(int j = 0; j < N; j++)
           if(vlevel[j] != INT_MAX)
               vlevel[j] = min(vlevel[j], (long long int)pow(p[index][0] - p[j][0], 2) + (long long int)pow(p[index][1] - p[j][1], 2));
	}
	cout << cost;
	return 0;
}

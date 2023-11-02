#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) 
	{
        int N;
        cin >> N;
        vector<int> lis(N), x;
        for(int i = 0; i < N; ++i) 
            cin >> lis[i];
        x.reserve(N);
        for (int j = 0; j < N; ++j) 
		{
            int current_element = lis[j];
            x.erase(remove_if(x.begin(), x.end(), [current_element](int a) { return a <= current_element; }), x.end());
            x.push_back(current_element);
            cout << x.size() << " ";
        }
        cout << "\n";
    }
    return 0;
}

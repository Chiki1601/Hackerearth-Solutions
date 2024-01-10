#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, pos[37]; 
    cin >> T;
	while(T --) 
    {
		int n; 
        cin >> n;
		for(int i = 0; i <= 30; i++) 
            pos[i] = 0;
		long long ans = 0;
		vector<int> temp;
		for(int i = 1; i <= n; i++) 
        {
			int a; 
            cin >> a;
			temp.clear();
			temp.push_back(0);
			for(int j = 0; j < 31; j++) 
            {
				if(a & (1 << j)) 
                    pos[j] = i;
				temp.push_back(pos[j]);
			}
			sort(temp.begin(), temp.end());
			int pos = 31, num = 0;
			while(1) 
            {
				num++;
				while(pos > 0 && temp[pos - 1] == temp[pos]) 
                {
                    pos--; 
                    num++;
                }
				if(num % 2) 
                    ans += (temp[pos] - temp[pos - 1]);
				if(pos == 0) 
                    break;
				pos--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

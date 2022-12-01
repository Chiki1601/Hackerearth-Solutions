#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t1, t2 = 0, ans = 0;
	bool a = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
    {
		cin >> t1;
		if(a == 0) 
        {
			if(t1 >= t2)
            { 
                a = 1;
                ans++;
            }
		}
		else
        {
			if(t1 <= t2) 
            {
                a = 0;
                ans++;
            }
		}
		t2 = t1;
	}
	cout << ans;
	return 0;
}

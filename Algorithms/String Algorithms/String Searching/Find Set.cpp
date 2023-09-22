#include<bits/stdc++.h>
using namespace std; 

bool check(string &a, string &b)
{
	int n = a.size(), m = b.size();
	if(n == m)
		return a < b;
	return n < m;
}

int main()
{ 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
    cin >> v[i];
    sort(v.begin(), v.end(), check);
    vector<bool> used(n);
    for(int i = 0; i < n; i++)
    {
        if(used[i]) 
            continue;
        ans++;
        for(int j = i + 1; j < n; j++)
        {
            if(used[j]) 
                continue;
            if(v[j].find(v[i]) != string::npos)
            {
                used[j]  = true;
                used[i] = true;
            }
        }
		used[i] = true;
    }
    cout << ans << endl;
}

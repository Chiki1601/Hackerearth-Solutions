#include <bits/stdc++.h>
using namespace std;
map<int, int> ok, ban;
queue<int> q;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, K, entrusted = 0;
    cin >> M >> K;
    vector<int> x(M + 1), d(M + 1), status(M + 1, 0);
    for(int i = 1; i <= M; i++) 
		cin >> x[i] >> d[i];
    for(int i = 0; i < K; i++)
	{
        int t, id;
        cin >> t >> id;
        int a = x[id] - d[id], b = x[id] + d[id];
        if(status[id] == 1)
		{
            ok[a]--;
            if(a != b) 
				ok[b]--;
            entrusted--;
        } 
		else if(status[id] == 2)
		{
            ban[a]--;
            ban[b]--;
        }
        status[id] = (t == 3 ? 0 : t);
        if(t == 1)
		{
            ok[a]++;
            if(a != b) 
				ok[b]++;
            entrusted++;
            q.push(id);
        } 
		else if(t == 2)
		{
            ban[a]++;
            ban[b]++;
        }
        int idx = -1;
        while(!q.empty())
		{
            int x = q.front();
            if(status[x] == 1)
			{
                idx = x;
                break;
            }
            q.pop();
        }
        if(idx == -1) 
			cout << -1 << endl;
        else
		{
            int a = x[idx] - d[idx], b = x[idx] + d[idx];
            vector<int> res;
            if(a > 0 && ok[a] == entrusted && ban[a] == 0) 
				res.push_back(a);
            if(b > a && ok[b] == entrusted && ban[b] == 0) 
				res.push_back(b);
            cout << (int)res.size();
            for(int i = 0; i < res.size(); i++)
                cout << " " << res[i];
            cout << endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int C, P, N;
    cin >> C >> P >> N;
    vector<pair<pair<long int, int>, int>> v(C, {{0, 0}, 0});
    priority_queue<pair<long long int, int>> q;
    for(int i = 0; i < C; i++)
    {
        if(i < N)
        {
            int iq;
            cin >> iq;
            v[i] = {{iq, 0}, 1};
            q.push({-iq, -i});
        }
        else
            q.push({0, -i});
    }
    for(int i = 0; i < P; i++)
    {
        int iqq = 0;
        cin >> iqq;
        pair<long long int, int> temp = q.top();
        q.pop();
        pair<pair<int, int>, int> val = v[-temp.second];
        val.second++;
        val.first.second = val.first.first;
        val.first.first = iqq;
        v[-temp.second] = val;
        q.push({-(long long)((long long)(val.first.first + val.first.second)*(long long)val.second), temp.second});
        cout << -temp.second + 1 << " ";
    }
}

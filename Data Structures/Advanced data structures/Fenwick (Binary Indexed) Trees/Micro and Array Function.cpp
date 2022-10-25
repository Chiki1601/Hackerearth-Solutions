#include<bits/stdc++.h>
using namespace std;
map<int, int>mp;
int N, K, A[100005];
 
signed long long int read(signed long long int *bit, int idx)
{
    signed long long int sum = 0;
    if(idx == 0)
        return 0;
    while(idx > 0)
	{
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(signed long long int *bit, int idx , int val)
{
    while(idx <= 200000)
	{
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
 
signed long long int calc(int *A)
{
	signed long long int ans = 0, tree[200005];
    for(int i = 1; i <= 200000; ++i)
		tree[i] = 0;
    for(int i = 1; i <= N; ++i)
	{
        ans += read(tree, mp[A[i] - K]) * (N - i + 1);
        update(tree, mp[A[i]], i);
    }
    return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--)
	{
        vector<int>V;
        cin >> N >> K;
        for(int i = 1; i <= N; ++i)
		{
            cin >> A[i];
            V.push_back(A[i]);
            V.push_back(A[i] - K);
        }
        sort(V.begin(), V.end());
        for(int i = 0; i < V.size(); ++i)
            mp[V[i]] = i + 1;
        signed long long int ans = 0;
        ans = calc(A);
        reverse(A + 1, A + N + 1);
        ans += calc(A);
        cout << ans << "\n";
    }
}

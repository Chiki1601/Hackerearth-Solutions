#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, A[100011], p[100011];
    cin >> N;
    long long cnt[2]={0}, ans = 0;
    cnt[0] = 1;
    for(int i = 1; i <= N; i++) 
	{
        cin >> A[i];
        p[i] = p[i - 1] + A[i];
        p[i] %= 2;
        ans += cnt[p[i]];
        cnt[p[i]]++;
    }
    cout << ans;
}

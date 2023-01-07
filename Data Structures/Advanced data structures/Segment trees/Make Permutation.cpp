#include <bits/stdc++.h>
using namespace std;
int B[1010101], N, T[1010101], M[1010101], DD = 128 * 1024;
 
void update(int id, int t, int l, int r, int v) 
{
    if(t >= r)  
        return;
    if(t <= l) 
    {
        T[id] += v;
        M[id] += v;
        return;
    }
    int m = (l + r) / 2;
    update(2 * id, t, l, m, v);
    update(2 * id + 1, t, m, r, v);
    M[id] = min(M[2 * id], M[2 * id + 1]) + T[id];
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	cin >> num;    
	while(num--) 
    {
        cin >> N;
        for(int i = 0; i < N; i++) 
            cin >> B[i];
        for(int i = 0; i < DD; i++) 
        {
            T[DD + i] = i;
            M[DD + i] = i;
        }
        for(int i = DD - 1; i > 0; i--) 
        {
            T[i] = 0;
            M[i] = min(M[2 * i], M[2 * i + 1]);
        }
        long long ans = 0;
        int l = 0;
        for(int r = 0; r < N; r++) 
        {
            update(1, B[r], 0, DD, - 1);
            while(M[1] < 0) 
                update(1, B[l++], 0, DD, 1);
            ans += r - l + 1;
        }
        cout << ans << endl;
    }
}

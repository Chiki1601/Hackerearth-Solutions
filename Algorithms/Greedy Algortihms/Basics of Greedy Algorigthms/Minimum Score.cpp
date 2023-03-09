#include <bits/stdc++.h>
using namespace std;
bool A[1<<20]; 
int seg[2 * (1<<20)], N, K;

int main() 
{
    int l = 1<<20, n = 1, r = 1<<20, w = 1;
    char digit;
    cin.tie(nullptr)->sync_with_stdio(false), cin >> N >> K;
    for(int i = 0; i < N; A[i++] = digit == '1')
        cin >> digit;
    bool p = A[0]; 
    for(int i = 1; i < N; ++i, ++w)
        if(A[i] != p)
            p = A[i], seg[r++] = w, ++n, w = 0;
    if(seg[r++] = w, n <= K) 
    {
        for(int i = l; i < r; ++i)
            for(; n < K and seg[i] > 1; ++n)
                seg[--l] = 1, --seg[i];
        cout << "0\n"; 
        for(int w = 0, i = l; i < r; ++i) 
        {
            const int from = w + 1, to = w + seg[i];
            cout << from << ' ' << to << '\n', w = to; 
        } 
    }
    else 
    {
        bool a_min = true, a_max = false; 
        for(int n = K - 1; n < N; ++n)
            a_min = min(a_min, A[n]), a_max = max(a_max, A[n]);
        cout << a_max - a_min << "\n"; 
        for(int n = 1; n < K; ++n)
            cout << n << ' ' << n << "\n";
        cout << K << ' ' << N; 
    } 
}

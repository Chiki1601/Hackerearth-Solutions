#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    long long int *height = new long long int[N], *ngrXOR = new long long int[N],  maxXor = 0;
    for(int i = 0; i < N; i++)
        cin >> height[i];
    stack<int> s;
    for(int i = N - 1; i >= 0; i--)
    {
        if(s.empty())
            ngrXOR[i] = height[i];
        else if(height[i] < height[s.top()])
            ngrXOR[i] = height[i] ^ ngrXOR[s.top()];
        else
        {
            while(!s.empty() && height[i] >= height[s.top()])
                s.pop();
            if (!s.empty())
                ngrXOR[i] = height[i] ^ ngrXOR[s.top()];
            else
                ngrXOR[i] = height[i];
        }
        s.push(i);
    }
    for (int i = 0; i < N; i++)
        maxXor = max(maxXor, ngrXOR[i]);
    cout << maxXor << endl;
    delete[] height, ngrXOR;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void multiply(long long int a[][2], long long int b[][2])
        {
            long long int c[2][2] = {{0}};
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    for(int k = 0; k < 2; k++)
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j] + 1000000009) % 1000000009;
                }
            }
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 2; j++)
                    a[i][j] = c[i][j];
            }
        }
        long long int unlucky_13(long long int n)
        {
            long long int res[2][2] = {{1, 0}, {0, 1}}, a[2][2] = {{0, -1}, {1, 10}};
            while(n)
            {
                if(n % 2)
                multiply(res, a);
                multiply(a, a);
                n /= 2;
            }
            return (res[0][0] + (res[1][0]*10LL) % 1000000009 + 1000000009) % 1000000009;
        }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        Solution obj;
        cout << obj.unlucky_13(n) << "\n";
    }
}

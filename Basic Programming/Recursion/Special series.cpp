#include <bits/stdc++.h>
using namespace std;
 
struct Mat 
{
    static constexpr int MAX_MAT = 2;
    int a[MAX_MAT][MAX_MAT];
    explicit Mat(bool emp = false) 
	  {
        memset(a, 0, sizeof a);
        if(emp)
            for(int i = 0; i < MAX_MAT; i++)
                a[i][i] = 1;
    }
	  const int *operator[](int i) const 
	  {
        return a[i];
    }
    int *operator[](int i) 
	  {
        return a[i];
    }
    Mat operator+(const Mat &b) 
	  {
        Mat ret;
        for (int i = 0; i < MAX_MAT; i++)
            for (int j = 0; j < MAX_MAT; j++)
                ret[i][j] = a[i][j] + b[i][j];
        return ret;
    }
    Mat operator*(const Mat &b) 
	  {
        Mat ret;
        for (int k = 0; k < MAX_MAT; k++)
            for (int i = 0; i < MAX_MAT; i++)
                for (int j = 0; j < MAX_MAT; j++)
                    ret[i][j] = (ret[i][j] + (long long) a[i][k] * b[k][j]) % 1000000007;
        return ret;
    }
    Mat operator^(int b) 
	  {
        Mat a = *this;
        Mat ret(true);
        for (; b; b >>= 1, a = a * a)
            if (b & 1)
                ret = ret * a;
        return ret;
    }
};
 
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    Mat base_fib;
    base_fib[0][0] = base_fib[0][1] = base_fib[1][0] = 1;
    int t;
    cin >> t;
    while (t--) 
	  {
        string n;
        int m, g = 0;
        cin >> n >> m;
        for (auto c : n)
            g = (g * 10ll + c - '0') % m;
        g = __gcd(g, m);
        cout << (base_fib ^ g)[0][1] << endl;
    }
}

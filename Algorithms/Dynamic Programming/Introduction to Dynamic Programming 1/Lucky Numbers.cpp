#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A[1000010];
    string s;
    cin >> s;
    long long diff = 1000000000000000000;
    if(s.size() > 1)
    {
        long long x = pow(10, s.size()-1) - 1;
        diff = stoll(s) - x;
    }
    for(int i = 0; i < s.size(); i++)
    {
        int d = s[i] - '0';
        if(d % 2 == 0)
        {                        
            string a = s.substr(0, i) + string(1, d == 0 ? '9' : char((d - 1)+'0')) + string(s.size() - i - 1, '9'), b = s.substr(0, i) + string(1, char(d + 1 + '0')) + string(s.size() - i - 1, '1');
            long long d_a = abs(stoll(a) - stoll(s)), d_b = abs(stoll(b) - stoll(s));
            if(min(d_a, d_b) >= diff)
                s = string(s.size() - 1, '9');
            else
                s = (d_b < d_a) ? b : a;
            break;
        }
    }
    cout << s << "\n";
    return 0;
}

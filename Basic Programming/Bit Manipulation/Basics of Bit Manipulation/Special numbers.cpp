#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;
        assert(k <= (int)1e9);
        int len = 1;
        long long curr = 0, next = 4;
        while(curr + next < k) 
        {
            curr += next;
            next *= 4ll;
            len++;
        }
        k -= curr;
        k--;
        string temp;
        int tmp = len;
        while(tmp--) 
        {
            int to = k % 4;
            k /= 4;
            temp.push_back(to + 'a');
        }
        string put = temp;
        reverse(temp.begin(), temp.end());
        cout << temp << put << endl;
    }
    return 0;
}

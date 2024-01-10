#include<bits/stdc++.h>
using namespace std; 

bool isGood(vector<long long int> &a, long long int width, long long int &allowedLines)
{
    long long int curLeft = width, curLines = 1;
    for(auto &x : a)
    {
        if(x <= curLeft)
        {
            curLeft -= x;
            curLeft--;
        }
        else
        {
            curLines++;
            curLeft = width;
            if(x > curLeft)
                return false;
            curLeft -= x;
            curLeft--;
        }
    }
    return (curLines <= allowedLines);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, m, ans = 1000000000000000, r = 1000000000000000, l = 1; 
    cin >> n >> m;
    vector<long long int> a(n);
    for(long long int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < 70; i++)
    {
        long long int mid = l + (r - l) / ((long long)2LL);
        if(isGood(a, mid, m))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}

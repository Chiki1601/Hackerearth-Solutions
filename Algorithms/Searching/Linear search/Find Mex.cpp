#include<bits/stdc++.h> 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, cur = 0; 
    cin >> n;
    set<int> ok;
    for(int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        ok.insert(x);
        while(ok.find(cur) != ok.end())
            cur++;
        cout << cur << " ";
    }
    return 0;
}

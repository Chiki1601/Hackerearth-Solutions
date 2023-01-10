#include <bits/stdc++.h>
using namespace std;
 
int sum_of_digit(long long int  n)
{
    if(n / 10 == 0)
        return n;
    else
    {
        int sum = 0;
        for(sum = 0; n > 0; sum += n % 10 , n /= 10);
            return sum_of_digit(sum);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, t;
    cin >> n >> t; 
    vector<int> v;
    while(n--)
    {
        long long int temp = 0;
        cin >> temp;
        v.push_back(sum_of_digit(temp));
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); i++)
        v[i] += v[i - 1];
    while(t--)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        if(x == 1)    
            cout << v[v.size() - 1] - v[v.size() - 1 - y] << endl;
        else            
            cout << v[y - 1] << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t; 
    cin >> t; 
    cin.ignore();
    while(t--)
    {
        string arr; 
        long long int k; 
        cin >> k >> arr;
        long long int count = 0, len = arr.length();
        for(long long int i = 0; i < len; i++)
        {
            long long int weight = (arr[i] -'a') + 1;
            if(weight == k )
                count ++;
            for(long long int j = (i + 1); j < len; j++)
            {
                weight += (arr[j] - 'a') + 1;
                if(weight > k)
                    break;
                if(weight == k)
                {
                    count ++;
                    break;
                }
            }
        }
        cout << count <<endl;
    }
    return 0;
}

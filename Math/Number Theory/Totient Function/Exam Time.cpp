#include<bits/stdc++.h>
using namespace std;
 
int eot(int a)
{
    long long int result = a;
    for(int i = 2; i * i <= a; i++)
    {
        if(a % i == 0)
        {
            while(a % i == 0)
             	a /= i;
            result = (result * (i - 1)) / i;
        }
    }    
    if(a > 1)
        result = (result * (a - 1)) / a;
    return result;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; 
	cin >> t;
    while(t--)
    {
        int n; 
		cin >> n; 
        cout << eot(n) << endl;
    }
}

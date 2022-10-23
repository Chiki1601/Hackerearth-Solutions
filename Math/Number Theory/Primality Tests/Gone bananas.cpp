#include <bits/stdc++.h>
using namespace std;
 
bool isPrime(long long n)
{
    if(n == 1)
        return true;
    for(long long i = 2; i * i <= (n); i++)
        if(n % i == 0)
            return false;
    return true;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long test;
    cin >> test;
    while(test--)
    {
        long long n;
        cin >> n;
        if(isPrime(n))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int no_of_elements, array_gcd;
    cin >> no_of_elements;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;  
        array_gcd = (i == 1 ? element : __gcd(array_gcd, element));
    }
    cout << (array_gcd == 1 ? "FINITE\n" : "INFINITE\n");
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int no_of_test_cases;
	cin >> no_of_test_cases;
	while(no_of_test_cases--)
	    solve();
	return 0;
}

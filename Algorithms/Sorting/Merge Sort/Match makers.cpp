#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
	  cin >> t;
    while(t--)
	  {
        int n, count = 0;
		    cin >> n;
        int A[n], B[n];
        for(int i = 0; i < n; i++)
			      cin >> A[i];
        for(int i = 0; i < n; i++)
			      cin >> B[i];
        sort(A, A + n);
        sort(B, B + n);
        for(int i = 0; i < n; i++)
		    {
            if(A[i] % B[n - 1 - i] == 0 || B[n - 1 - i] % A[i] == 0)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}

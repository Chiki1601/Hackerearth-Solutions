#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 	  int t; 
    cin >> t;
	  while(t--)
    {
		    int n;
        long long int a, b;  
        cin >> a >> b >> n;
		    long long int arr[n];
		    for(int i = 0; i < n; i++) 
            cin >> arr[i];
		    if(a == b)
        { 
            cout << "Tie" << endl; 
            continue;
        }
		    sort(arr, arr + n);
		    long long int sum = 0;
		    int j = 0;
		    while(sum <= min(a, b) && j < n)
			      sum += arr[j++];
		        if(sum > min(a, b) && sum <= max(a, b))
			          a > b ? cout << "Raghu Won" << endl : cout << "Sayan Won" << endl;
		        else 
                cout << "Tie" << endl;
    }
	  return 0;
}

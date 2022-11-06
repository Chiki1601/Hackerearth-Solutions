#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL);
	  int n;
	  cin >> n;
	  int arr[n];
	  for(int i = 0; i < n; i++)
		    cin >> arr[i];
	  int max_right[n], max_left[n];
	  max_right[0] = arr[0];
	  for(int i = 1; i < n; i++)
		    max_right[i] = max(max_right[i - 1], arr[i]);
	  max_left[n - 1] = arr[n - 1];
	  for(int i = n - 2; i > -1; i--)
		    max_left[i]=max(max_left[i+1],arr[i]);
	  cout << "1 ";
	  for(int i = 1; i < n - 1; i++)
	  {
		    if(arr[i] == max_left[i] || arr[i] == max_right[i])
			      cout << i + 1 << " ";
	  }
	  cout << n;
}

#include <bits/stdc++.h>
using namespace std;
 
// Don't use maps
int max_for_given_ratio(int arr[], int n, int r)
{
	  int numbers[200000] = {0}, maxx = 1;
    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        if(numbers[100000 + x] == 0)
        {
            numbers[100000 + x] = 1;
			      if(r * x > -100000 && r * x < 100000)
            	  numbers[100000 + r * x] = -1;
        }
        else if(numbers[100000 + x] == -1)
        {
            numbers[100000 + x] = numbers[100000 + x / r] + 1;
            maxx = max(maxx, numbers[100000 + x]);
			      if(r * x > -100000 && r * x < 100000)
            	  numbers[100000 + r * x] = -1;
        }
    }
	return maxx;
}
 
int for_one_zero(int arr[], int n)
{
	  sort(arr, arr + n);
	  int maxx = 0, maxx_elem = arr[0];
	  for(int i = 0; i < n; i++)
	  {
		    int x = 0, elem = arr[i];
		    while(arr[i] == elem)
		    {
			      x++;
			      i++;
		    }
		    i--;
		    if(x > maxx)
		    {
			      maxx = x;
			      maxx_elem = arr[i];	
		    }
	  }
	  if(maxx_elem == 0)
		    return min(maxx + 1, n);
	  else
		    return maxx;
}
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int n;
	  cin >> n;
	  int arr[n];
	  for(int i = 0; i < n; i++)
		    cin >> arr[i];
	  int maxx = 1;
	  for(int r = 2; r < 100; r++)
		    maxx = max(maxx, max_for_given_ratio(arr, n, r));
	  for(int r = -1; r > -100; r--) 
		    maxx = max(maxx, max_for_given_ratio(arr, n, r));
	  maxx = max(maxx, for_one_zero(arr, n));
	  cout << maxx << endl;
}

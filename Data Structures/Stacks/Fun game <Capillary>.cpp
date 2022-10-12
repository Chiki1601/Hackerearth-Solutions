#include <bits/stdc++.h>   
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int arr[n], a = 0, b = n - 1;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	string output = "";
	while(a <= n - 1 && b >= 0) 
    {
		if(arr[a] > arr[b]) 
        {
			b--;
			output += "1 ";
		} 
        else if(arr[a] < arr[b]) 
        {
			a++;
			output += "2 ";
		}
		else 
        {
			a++;
			b--;
			output += "0 ";
		}
	}
	cout << output;
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int n; 
    cin >> n;
	  int cost[n];
	  for(int i = 0; i < n; i++) 
        cin >> cost[i];
	  int counter = 0;
	  bool checkSum[2000 * n] = {0};
	  for(int i = 0; i < (1<<n); i++)
    {
		    long long int sum = 0;
		    for(int j = 0; j < n; j++) 
            if(i & (1<<j)) 
                sum += cost[j];
		    if(!(checkSum[sum]) && sum && !(sum & 1)) 
            counter++;
		    checkSum[sum] = {1};
	  }
	  cout << counter;
	  return 0;
}

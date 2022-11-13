#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  long long test_cases;
	  cin >> test_cases;
	  while(test_cases--)
	  {
		    long long n,x,y,min_effort=0,i;
		    cin >> n >> x >> y;
		    vector<long long>initial(n), finall(n);
		    i = 0;
		    for(i = 0; i < n; i++)
			      cin >> initial[i] >> finall[i];
		    sort(initial.begin(), initial.end());
		    sort(finall.begin(), finall.end());
		    for(i = 0; i < n; i++)
		    {
			      if(initial[i] == finall[i])
				        continue;
			      else if(initial[i] < finall[i])
				        min_effort += (finall[i] - initial[i]) * x;
			      else if(initial[i] > finall[i])
				        min_effort += (initial[i] - finall[i]) * y;
		    }
		    cout << min_effort << endl;
	  }
	  return 0;
}

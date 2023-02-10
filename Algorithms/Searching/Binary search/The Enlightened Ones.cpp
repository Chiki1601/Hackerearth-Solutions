#include<bits/stdc++.h>
using namespace std;
vector<long long int>v;
long long int n, monk, z;
bool good(long long int x);
 
int main()
{
	  cin >> n >> monk;
	  v.resize(n);
	  for(int i = 0; i < n; i++)
		    cin >> v[i];
	  sort(v.begin(), v.end());
	  monk -= 1;
	  z = monk;
	  long long int l = 0, r = 1e7, m;
	  while(r > l + 1)
	  {
		    m = l + (r - l) / 2;
		    if(good(m))
			      r = m;
		    else
			      l = m;
	  }
	  cout << r;
}
 
bool good(long long int x)
{
	  long long int i = 0, j = 1;
	  monk = z;
	  while(i < n && j < n)
  	{
		    if((v[j] - (v[i] + x)) <= x)
			      j++;
		    else
		    {	
			      if(monk == 0)
				        return false;
			      monk--;
			      i = j;
			      j = i + 1;
		    }
	  }
	  return true;
}

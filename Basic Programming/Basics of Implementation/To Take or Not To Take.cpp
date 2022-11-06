#include<bits/stdc++.h>
using namespace std;
 
long long func(long long a, char type, long long x) 
{
  	if(type == 'N') 
  		  return -a;
  	else if(type == '+') 
  		  return a + x;
  	else if(type == '-') 
  		  return a - x;
  	else if(type == '*') 
  		  return a * x;
  	else if(type == '/') 
  		  return a / x;
  	else 
	  	  assert(false);
}
 
void energy() 
{
  	int B;
  	cin >> B;
  	long long mi = 1, ma = 1;
  	for(int i = 0; i < B; ++i) 
	  {
    	  char sl[3];
    	  cin >> sl;
    	  int x;
    	  if(sl[0] != 'N') 
			      cin >> x;
    	  vector<long long> maybe;
    	  maybe.push_back(mi);
    	  maybe.push_back(ma);
    	  maybe.push_back(func(mi, sl[0], x));
    	  maybe.push_back(func(ma, sl[0], x));
    	  sort(maybe.begin(), maybe.end());
    	  mi = maybe[0];
    	  ma = maybe.back();
    	  long long M = 1000 * 1000 * 1000;
    	  M *= M;
    	  assert(max(abs(mi), abs(ma)) <= M);
  	}
  	cout << ma << endl;
}
 
int main() 
{
  	int T;
  	cin >> T;
  	while(T--) 
	  	  energy();
  	return 0;
}

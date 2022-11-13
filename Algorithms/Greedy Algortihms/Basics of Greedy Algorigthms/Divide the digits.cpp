#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int query;
	  cin >> query; 
	  for(int i = 0; i < query; i++) 
	  {
		    long N;
		    cin >> N;
		    string m_temp = to_string(N);
		    sort(m_temp.begin(), m_temp.end());
		    string A, B;
		    for(int m = 0; m < m_temp.size(); m++) 
		    {
			      if(m % 2 == 0) 
				        A.push_back(m_temp[m]);
			      else 
				        B.push_back(m_temp[m]);
		    }
		    cout << (stoi(A) + stoi(B)) << endl;
	  }
	  return 0;
}

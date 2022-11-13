#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t;
 	  cin >> t;
 	  while(t--)
	  {
    	  long long int n;
    	  cin >> n;
     	  string s, ans, ans2;
     	  cin >> s;
     	  for(int i = 0; i < n; i++)
     	  {
         	  if(s[i] != '2')
            	  ans += s[i];
         	  else 
			 	        ans2 += "2";
     	  }
     	  int i;
   		  for(i = 0; i < ans.size(); i++)
    	  { 
			  if(ans[i] == '1')
      			cout << ans[i];
        else
         		break;
    	  }
    	  cout << ans2;
   		  for(int j = i; j < ans.size(); j++)
       		  cout << ans[j];
   		  cout << endl;
 	  }
 	  return 0;
}

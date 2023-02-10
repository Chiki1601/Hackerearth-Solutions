#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  char s[100009];
	  int t, k, ans = 0, ct[30] = {0}, aa, pr;
	  cin >> s; 
	  int len = strlen(s);
	  cin >> t;
	  while(t--)
  	{
		    cin >> k; 
		    ans = 0; 
		    memset(ct, 0, sizeof(ct)); 
		    aa = len;
		    for(int i = 0; i < len; i++)
		    {
			      if(ct[s[i] - 'a'] % 2)
				        ct[s[i] - 'a']++, ans += 2;
			      else 
				        ct[s[i] - 'a']++;
			      if(ans + 1 >= k && i + 1 >= k)
			      {
				        aa = i; 
				        break;
			      }
		    }
		    if(aa == len)
			      cout << -1 << endl;
		    else 
		    {
			      int i = 0; 
			      pr = aa + 1;
			      for(i = 0; i < len - 1;)
			      {
				        if(ct[s[i] - 'a'] % 2 == 0 && ct[s[i] - 'a'] > 0)
					          ct[s[i]-'a']--, ans -= 2;
				        else if(ct[s[i] - 'a'] > 0)
					          ct[s[i] - 'a']--;
				        i++;
				        while(aa < len)
				        {
					          if(ans + 1 >= k && aa - i + 1 >= k)
					          {
						            pr = min(pr, aa - i + 1); 
						            break;
					          }
					          aa++;
					          if(aa < len)
					          {
						            if(ct[s[aa] - 'a'] % 2)
							              ct[s[aa] - 'a']++, ans += 2;
						            else 
							              ct[s[aa] - 'a']++;
					          }
				        }
			      }
			      cout << pr << endl;
		    }	
	  }
	  return 0;
}

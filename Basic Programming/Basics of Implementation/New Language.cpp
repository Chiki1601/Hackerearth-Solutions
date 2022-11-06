#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  	int t;
  	cin >> t;
  	while(t--)
  	{
    	  string s, a = "", b = "";
		    char op;
    	  cin >> s;
    	  for(int i = 0; i < s.size(); i++)
    	  {
      		  if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
      		  {
        		    op = s[i];
        		    a = b;
        		    b = "";
        		    continue;
      		  }
      		  b += (s[i] == '9') ? '8' : s[i];
    	  }
    	  long long vala = 0, valb = 0, mul = 1;
    	  for(int i = a.size() - 1; i >= 0; i--)
    	  {
      		  vala = (a[i] - 48) * mul + vala;
      		  mul *= 9;
    	  }
    	  mul = 1;
    	  for(int i = b.size() - 1; i >= 0; i--)
    	  {
      		  valb = (b[i] - 48) * mul + valb;
      		  mul *= 9;
    	  }
    	  long long ans;
    	  if(op == '+')
			      ans = vala + valb;
    	  else if(op == '-')
			      ans = vala - valb;
    	  else if(op == '*')
			      ans = vala * valb;
    	  else 
			      ans = vala / valb;
    	  a = "";
    	  while(ans)
    	  {
      		  char temp=(char)(ans % 9 + '0');
      		  if(temp == '8')
			  	      temp = '9';
      		      a = temp + a;
      		      ans /= 9;
    	  }
    	  if(a == "")
			      a += '0';
    	  cout << a << endl;
  	}
  	return 0;
}

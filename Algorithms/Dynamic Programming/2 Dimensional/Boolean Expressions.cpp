#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char s[310], o[310], op[6];
	long long int f[2][310][310];
   	cin >> s >> o;
   	int n = strlen(s), q, l, r, x;
   	for(int i = 0; i < n; i++)
   		f[s[i] - '0'][i][i] = 1ll;
   	for(int l = 2; l <= n; l++)
   	{
      	for(int i = 0; i <= n - l; i++)
		{
         	int j = i + l - 1;
         	for(int k = i; k < j; k++)
			{
		        for(int c = 0; c < 2; c++)
            		for(int d = 0; d < 2; d++)
					{
               			if(o[k] == 'a')
						   	x = (c & d);
               			else if(o[k] == 'x') 
						   	x = (c ^ d);
               			else  
						   	x = (c | d);
              			{
                  			long long int inc = f[c][i][k] * f[d][k + 1][j] % 1000000009;
                  			f[x][i][j] = (f[x][i][j] + inc) % 1000000009;
               			}
            		}
         	}
      	}
   	}
   	cin >> q;
   	while(q--)
	{
      	cin >> l >> r >> op;
      	x = op[0] == 't' ? 1 : 0;
      	cout << f[x][--l][--r] << endl;
   	}
   	return 0;
}

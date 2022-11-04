#include<bits/stdc++.h>
using namespace std;
 
class GameOFString
{
    public:
    	bool checkV(char x)
    	{
        	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            	return true;
        	return false;
    	}
    	int minLength(string &x, string &y)
    	{
        	int n = x.length(), m = y.length();
        	if(!n || !m)
            	return 0;
        	vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));
        	for(int i = 1; i <= n; i++)
        	{
            	for(int j = 1; j <= m; j++)
            	{
                	if(x[i - 1] == y[j - 1] && !checkV(x[i - 1]))
                    	t[i][j] = 1 + t[i - 1][j - 1];
                	else
                    	t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            	}
        	}
        	return t[n][m];
    	}
};
 
int main()
{
    string a, b;
    cin >> a >> b;
    GameOFString obj;
    cout << obj.minLength(a, b) << endl;
}

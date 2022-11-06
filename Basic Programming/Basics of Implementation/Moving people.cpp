#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, x, y, z, k;
string str[maxn];
int csum[maxn][maxn];
 
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) 
		cin >> str[i];
    for(int i = 1; i <= n; i++)
	  {
        for(int j = 1; j <= m; j++)
		    {
            csum[i][j] = csum[i - 1][j] + csum[i][j - 1] - csum[i - 1][j - 1];
            if(str[i][j - 1] == '1') 
				        csum[i][j]++;
        }
    }
    int lft = 1, rgh = m, up = 1, dwn = n, mxlft = 1, mnrgh = m, mxup = 1, mndwn = n;
    bool flg = false;
    while(k--)
	  {
        int tp;
        cin >> tp;
        if(tp == 1)
		    {
            int x, y;
            cin >> x >> y;
            lft += x;
            rgh += x;
            up += y;
            dwn += y;
            mxlft = max(mxlft, lft);
            mnrgh = min(mnrgh, rgh);
            mxup = max(mxup, up);
            mndwn = min(mndwn, dwn);
        }
        else
		    {
            if(mxlft > mnrgh || mxup > mndwn) 
				        cout << "0" << endl;
            else
			      {
                int anss = csum[mndwn][mnrgh] - csum[mndwn][mxlft - 1] - csum[mxup - 1][mnrgh] + csum[mxup - 1][mxlft - 1];
                cout << anss << endl;
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
bool nim[1 << 20];
const int dx[] = {1, 0, -1, 0, 1}, dy[] = {0, 1, 0, -1, 0, 1};
 
int enc(int x, int y) 
{
	return x * m + y;
}
 
bool s(int m, int x, int y) 
{
	return (m >> enc(x, y)) & 1;
}
 
bool g(int mk) 
{
	for(int x = 0; x < n; x++) 
		for(int y = 0; y < m; y++) 
		{
			if(s(mk, x, y)) 
				continue;
			int nmk = mk | (1 << enc(x, y));
			if(!nim[nmk]) 
				continue;
			for(int k = 0; k < 4; k++) 
			{
				int xx = x + dx[k], yy = y + dy[k];
				if(xx < 0 || xx >= n || yy < 0 || yy >= m) 
					continue;
				if(s(mk, xx, yy)) 
					continue;
				return 0;
			}
		}
	return 1;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q;
	cin >> n >> m >> q;
	for(int mk = 1 << (n * m); --mk >= 0;) 
		nim[mk] = g(mk);
	for(; q--; ) 
	{
		int mk = 0;
		for(int i = 0; i < n; i++) 
		{
			static char buf[32];
			cin >> buf;
			for(int j = 0; j < m; j++) 
				mk = (mk << 1) | (buf[j] - '0');
		}
		cout << nim[mk] << endl;
	}
}

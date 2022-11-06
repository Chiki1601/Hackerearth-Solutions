#include<bits/stdc++.h>
using namespace std;
char sl[1005][1005];
 
int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int z;
	cin >> z;
	while(z--) 
    {
		int n, total = 0, s = 0;
		cin >> n;
		for(int y = 0; y < n; ++y) 
            cin >> sl[y];
		for(int y = 0; y < n; ++y)
            for(int x = 0; x < n; ++x) 
                total += sl[y][x] == '#';
		bool ans = false;
		for(int x = 0; x < n; ++x) 
        {
			for(int y = 0; y < n; ++y) 
                s += sl[y][x] == '#';
			if(s * 2 == total) 
                ans = true;
		}
		s = 0;
		for(int y = 0; y < n; ++y) 
        {
			for(int x = 0; x < n; ++x) 
                s += sl[y][x] == '#';
			if(s * 2 == total) 
                ans = true;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}

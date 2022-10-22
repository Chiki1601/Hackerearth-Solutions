#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int maxFreq = 0, n, freq[3000];
    char ch, s[1005];
    cin.getline(s, 1000);
    n = strlen(s);
    for (int i = 0; i < n; ++i) 
	{
        freq[s[i]]++;
        if (freq[s[i]] > maxFreq) 
		{
            maxFreq = freq[s[i]];
            ch = s[i];
        } 
		else if (freq[s[i]] == maxFreq && ch > s[i])
            ch = s[i];
    }
    cout << ch << " " << maxFreq;
    return 0;
}

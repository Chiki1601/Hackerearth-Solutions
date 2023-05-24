#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCases;
    cin >> testCases;
    for(int t = 1; t <= testCases; t++) 
	{
        int length, mask = 0, count = 0;
        string str;
        cin >> length >> str;
        unordered_map<int, int> charMap;
        charMap[0] = 1;
        for(int i = 0; i < length; i++) 
		{
            mask ^= (1 << (str[i] - 'a'));
            count += charMap[mask];
            charMap[mask]++;
        }
        cout << count << "\n";
    }
    return 0;
}

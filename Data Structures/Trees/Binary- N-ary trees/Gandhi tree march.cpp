#include<bits/stdc++.h>
using namespace std;
int a;
string arr[2100], str;
 
void process(int b)
{
    if(str[a] != '.')
    {
    	if(abs(b) <= 1000)
        	arr[b + 1000] += str[a];
    	a += 2;
    	process(b - 1);
    	process(b + 1);
    }
    a++;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
    cin >> t;
    while(t--)
    {
    	int c, i, j, n;
    	a = 0;
    	for(i = 0; i < 2100; i++)
        	arr[i] = "";
    	cin >> c >> str;
    	n = str.length();
    	assert(c >= -1000 && c <= 1000);  
    	process(0);
    	sort(arr[c + 1000].begin(), arr[c + 1000].end());
    	if(arr[c + 1000].size())
        	cout << arr[c + 1000] << endl;
    	else 
			cout << "Common Gandhijee!" << endl;
    }
    return 0;
}

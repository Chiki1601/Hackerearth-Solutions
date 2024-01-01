#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) 
        cout << i << " " << i + 1 << "\n";
    return 0;  
}
//Solution - 2
#include <bits/stdc++.h>
using namespace std;

int main() 
{
 	int n;
 	cin >> n;
 	string s;
 	cin >> s;
 	priority_queue<int, vector<int>, greater<int>> opening;
 	priority_queue<int, vector<int>, greater<int>> closing; 
 	vector<int> sequence(n + 1, 0);
 	for(int i = 1; i <= n; i++)
	    sequence[i] = i;
	for(int i = 0; i < n; i++)
    {
		if(s[i] == '(')
			opening.push(i + 1);
		else
			closing.push(i + 1);
	}
	if(opening.size() > 0)
	{
		int prev = opening.top();
		opening.pop();
		while(opening.size() > 0)
        {
			cout << prev << " " << opening.top() << "\n";
			prev = opening.top();
			opening.pop();
		}
		if(closing.size() > 0)
        {
			cout << prev << " " << closing.top() << "\n";
			prev = closing.top();
			closing.pop();
		}
		while(closing.size() > 0)
        {
			cout << prev << " " << closing.top() << "\n";
			prev = closing.top();
			closing.pop();
		}
	}
	else
    {
		int prev = closing.top();
		closing.pop();
		while(closing.size() > 0)
        {
			cout << prev << " " << closing.top() << "\n";
			prev = closing.top();
			closing.pop();
		}
	}
	return 0;
}

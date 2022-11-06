#include<bits/stdc++.h>
using namespace std;
 
void eval()
{
	int n, players;
	cin >> n >> players;
	string s;
	cin >> s;
	vector<int> score(players);
	int p1 = 0, p2 = 1, next = 2;
	for(int i = 0; i < 6 * n; i++)
	{
	 	if(p1 >= players || p2 >= players)
	 		assert(0);
	 	if(s[i] == 'W')
	 		p1=next++;
		else if(s[i] == '6')
			score[p1] += 6;
		else if(s[i] == '4')
			score[p1] += 4;
		else if(s[i] == '2')
			score[p1] += 2;
		else if(s[i] == '1')
		{
			score[p1] += 1;
			swap(p1, p2);	//rotate strike
		}
		else if(s[i] == '0')
			;
		else
			assert(0);	//undefined character
		if(i % 6 == 5)
		{
			swap(p1, p2);	//rotate strike
		}
	}
	for(int i = 0; i < players; i++)
	{
		cout << "Player " << i + 1 << ": ";
		if(i == p1 || i == p2)
			cout << score[i] << "*" << endl;
		else if(next > i)
			cout << score[i] << endl;
		else
			cout << "DNB" << endl;
	}
}
 
int main()
{
	int t;
	cin >> t;
	for(int te = 1; te <= t; te++) 
	{
		cout << "Case " << te << ":" << endl;
		eval();
	}
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	  int t;
	  cin >> t;
	  while(t--)
	  {
		    int n;
		    cin >> n;
		    vector<pair<int,int> > v;
		    for(int i = 1; i <= n; i++)
		    {
			      int a , b;
			      cin >> a >> b;
			      v.push_back(make_pair(b , a));
		    }
		    sort(v.begin() , v.end());
		    int score1 = 0 , score2 = 0, turn = 0;
		    while(v.size())
		    {
			      vector<int> to_erase;
			      to_erase.push_back(0);
			      for(int i = 1; i < v.size(); i++)
			      {
				        if(v[i].second > v[to_erase.back()].first)
						        to_erase.push_back(i);
			      }
			      if(turn == 0)
				        score1 = score1 ^ to_erase.size();
			      else
				        score2 = score2 ^ to_erase.size();
			      while(to_erase.size())
			      {
				        v.erase(v.begin() + to_erase.back());
				        to_erase.pop_back();
			      }
			      turn = 1 - turn;
		    }
		    if(score1 > score2)
			      cout << "Alice" << endl;
		    else if(score1 == score2)
			      cout << "Tie" << endl;
		    else
			      cout << "Bob" << endl;
	  } 	
}

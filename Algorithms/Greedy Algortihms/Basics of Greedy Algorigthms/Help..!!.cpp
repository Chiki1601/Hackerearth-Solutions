#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int n, i = 0, dist, pet, d, p, curpet, flag = 0, ans = 0;
	  cin >> n;
	  vector<pair<int, int>>vec(n);
	  for(i = 0; i < n; i++)
		    cin >> vec[i].first >> vec[i].second;
	  cin >> d >> p;
	  for(i = 0; i < n; i++)
		    vec[i].first = d - vec[i].first;
	  sort(vec.begin(), vec.end());
	  priority_queue<int, vector<int>>pq;
	  curpet = p;
	  for(i = 0; i < n; i++)
	  {
		    if(curpet >= d)
			      break;
		    else
		    {
			      while(curpet < vec[i].first)
			      {
				        if(pq.empty())
				        {
					          flag = 1;
					          break;
				        }
				        ans++;
				        curpet += pq.top();
				        pq.pop();
			      }
		    }
		    if(flag == 1)
			      break;
		    pq.push(vec[i].second);
    }
	  while(!pq.empty() && curpet<d)
	  {
	    	curpet += pq.top();
		    pq.pop();
		    ans++;
	  }
	  if(curpet < d || flag == 1)
		    cout << "-1" << endl;
	  else
		    cout << ans << endl;
	  return 0;
}

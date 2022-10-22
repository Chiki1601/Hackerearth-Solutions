#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int t;
    cin >> t;
    while(t--)
	{
    	int N;
	    cin >> N;
	    map<string, priority_queue<long long>> Events;
	    for(int i = 1; i <= N; i++)
		{
	        string S;
    	    long long x;
        	cin >> S >> x;
	        Events[S].push(x);
    	}
	    pair<string, long long>res;
    	res.second = 0;
	    for(auto it : Events)
		{
	        long long sum = 0;
	        int top = min(3LL, (long long)it.second.size());
	        while(top--)
			{
	            sum += it.second.top();
    	        it.second.pop();
        	}
	        if(sum > res.second)
				res = {it.first, sum};
    	}
	    cout << res.first << " " << res.second << endl;
    }
    return 0;
}

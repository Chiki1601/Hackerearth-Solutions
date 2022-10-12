#include <bits/stdc++.h>
using namespace std;
 
long long NextBig(long long A[], long long i)
{
  	long long j = i - 1;
  	for( ;A[i] > A[j] && j >= 1; j--);
  	return (i - j);
}
 
int main()
{
  	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long N;
  	cin >> N;
  	long long A[N + 1], count = 0;
  	for(long long i = 1; i <= N; i++)
   		cin >> A[i];
  	unordered_map <long long, long long> map;
  	stack <long long> stk;
  	for(long long i = N; i >= 1; i--)
	{
   		while(!stk.empty() && A[i] > A[stk.top()])
     		stk.pop();
    	if(!stk.empty() && stk.top() - i)
		{
      		int temp = NextBig(A , i);
			if(map.find(stk.top() - i) == map.end())
       			map[stk.top() - i] = temp;
      		else
       			if(map[stk.top() - i] < temp)
         			map[stk.top() - i] = temp;
    	}
    	stk.push(i);
  	}
  	for(auto it : map)
   		count = count + it . second;
  	cout << count << endl;  
  	return 0;
}

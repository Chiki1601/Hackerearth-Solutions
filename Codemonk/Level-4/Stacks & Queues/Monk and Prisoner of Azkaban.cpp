#include <bits/stdc++.h>
using namespace std;
long long int a[1010000];
long int nge[1010000], pge[1010000];

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<long int> st;
	long int N;
	cin >> N;
	for(long int i = 1; i <= N; ++i) 
		cin >> a[i];
	st.push(1);
	for(long int i = 2; i <= N; ++i) 
    {
		while(st.size() && a[st.top()] < a[i]) 
        {
			nge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(st.size()) 
    {
		nge[st.top()] = -1;
		st.pop();
	}
	st.push(N);
	for(int i = N - 1; i >= 1; i--) 
    {
		while(st.size() && a[st.top()] < a[i]) 
        {
			pge[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(st.size()) 
    {
		pge[st.top()] = -1;
		st.pop();
	}
	for(int i = 1; i <= N; ++i) 
		cout << nge[i] + pge[i] << " ";
	return 0;
}

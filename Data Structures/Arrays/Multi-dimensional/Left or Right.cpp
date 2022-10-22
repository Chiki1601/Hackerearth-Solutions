#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, q, t, index, value;
    char ch;
    cin >> n >> q;
    map<long long int, vector<long long int>>graph; 
    for(long long int i = 0; i < n; i++)
    {
        cin >> t;
        graph[t].push_back(i);
    }
    while(q--)
    {
        cin >> index >> value >> ch;
        if(graph[value].size() == 0)
        {
            cout << "-1" << endl;
            continue;   
        }   
        long long int maxi = LLONG_MAX, mini = LLONG_MAX;
        if(ch == 'L')
        {
            for(auto i : graph[value])
            {   
                if(i <= index)
                    maxi = min(index - i, maxi);
                else
                    mini = min(index + n - i, mini);
            }
            if(maxi != LLONG_MAX)
            	cout << maxi << endl;
            else
            	cout << mini << endl;
        }
        else
        {
            for(auto i : graph[value])
            {
                if(index <= i)
                	maxi = min(i - index,maxi);
                else
                	mini = min(n - index + i,mini);
            }
            if(maxi != LLONG_MAX)
            	cout << maxi << endl;
            else
            	cout << mini << endl;
        }
    }
}

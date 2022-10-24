#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> D(n,vector<int>(n, INT_MAX));
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		D[i][j] = 999;
    for(int i = 0; i < n; i++)
    	D[i][i] = 0;
    unordered_map<string, int> map;
	string station_names;
    for(int i = 0; i < n; i++)
    {
        cin >> station_names;
        map[station_names] = i;
    }
    while(m--)
    {
        int cost;
        string source, destination;
        cin >> source >> destination >> cost;
        D[map[source]][map[destination]] = cost;
        D[map[destination]][map[source]] = cost;
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(D[i][j] > D[i][k] + D[k][j])
	                D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        string source, destination;
        cin >> source >> destination;
        cout << D[map[source]][map[destination]] << endl;
    }
}

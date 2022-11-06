#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, val;
    cin >> n;
    int t = 1 << n;
    queue < int > players;
    for(int i = 0; i < t; i++)
        players.push(i);
    vector < vector < int > > A(t);
    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cin >> val;
            A[i].push_back(val);
        }
    }
    int p1, p2;
    while(players.size() != 1)
    {
        p1 = players.front();
        players.pop();
        p2 = players.front();
        players.pop();
        if(A[p2][p1])
            players.push(p2);
        else
            players.push(p1);
    }
    cout << players.front() + 1 << endl;
}

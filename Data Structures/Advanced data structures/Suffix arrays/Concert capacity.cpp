#include<bits/stdc++.h>
using namespace std;

string solution (int N, int C, vector<vector<int>> audience) 
{
    int temp = C - audience[0][0], res = 1;
    for(int i = 1; i < N; i++)
    {
        if(audience[i - 1][2] < audience[i][1])
            temp = C - audience[i][0];
        else
            temp -= audience[i][0];
        if(temp < 0)
        {
            res = 0;
            break;
        }
    }
    if(res == 1)
        return "Yes";
    else
        return "No";
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C;
    cin >> N >> C;
    vector<vector<int>> audience(N, vector<int>(3));
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < 3; j++)
    		cin >> audience[i][j];
    }
    cout << solution(N, C, audience);
}

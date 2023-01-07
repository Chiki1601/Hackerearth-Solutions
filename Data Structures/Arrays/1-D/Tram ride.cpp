#include<bits/stdc++.h>
using namespace std;
 
long long solve (int N, int start, int finish, vector<int> Ticket_cost) 
{
    start--;
    finish--;
    vector<long long> sumTill(N);
    sumTill[0] = Ticket_cost[0];
    for(int i = 1; i < N; i++)
        sumTill[i] = sumTill[i - 1] + Ticket_cost[i];
    long long directSum = 0, indirectSum = 0;
    directSum = sumTill[finish - 1] - (start > 0 ? sumTill[start - 1] : 0);
    indirectSum = (start > 0? sumTill[start - 1] : 0) + sumTill[N - 1] - sumTill[finish - 1];
    return directSum > indirectSum ? abs(indirectSum) : abs(directSum); 
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, start, finish;
    cin >> N >> start >> finish;
    vector<int> Ticket_cost(N);
    for(int i = 0; i < N; i++)
    	cin >> Ticket_cost[i];
    cout << solve(N, start, finish, Ticket_cost);
}

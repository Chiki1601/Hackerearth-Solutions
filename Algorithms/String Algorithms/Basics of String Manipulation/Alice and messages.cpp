#include<bits/stdc++.h>
using namespace std;
     
int findMessages(int N, vector<string> A) 
{
    int ans = N;
    set<string> st;
    for(int i = 0; i < N; i++) 
    {
        string s;
        for(int j = 0; j < A[i].size(); j++)
            s += 'a' + ('z' - A[i][j]);
        if(st.find(s) != st.end())
            ans -= 1;
        st.insert(A[i]);
    }
    return ans;
}
     
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, out_;
    cin >> N;
    vector<string> A(N);
    for(int i_A = 0; i_A < N; i_A++)
        cin >> A[i_A];
    cout << findMessages(N, A);
}

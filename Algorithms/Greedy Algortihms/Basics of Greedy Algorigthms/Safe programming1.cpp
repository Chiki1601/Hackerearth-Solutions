#include<bits/stdc++.h>
using namespace std;

bool SafeProgramming(int N, vector<int> A) 
{
    sort(A.begin(), A.end());
    if(A[0] == A[N - 1])
        return 1;
    set<int> st;
    for(int i = 0; i < A.size(); i++)
        st.insert(A[i]);
    return (*(----st.end()) * 3 <= *(--st.end()));
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
        cin >> A[i_A];
    cout << (SafeProgramming(N, A) ? 1 : 0);
}

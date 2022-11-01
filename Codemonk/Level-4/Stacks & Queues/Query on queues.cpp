#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
    {
        int n, k;
        cin >> n >> k;
        int a[n], q[k];
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        for(int i = 0; i < k; i++) 
            cin >> q[i];
        stack<int> st, st1;
        vector<int> pge(n, -1), nge(n, n);
        for(int i = 0, j = n - 1; i < n; i++, j--) 
        {
            while(!st.empty() && a[st.top()] <= a[i]) 
                st.pop();
            while(!st1.empty() && a[st1.top()] <= a[j]) 
                st1.pop();
            if(!st.empty()) 
                pge[i] = st.top();
            if(!st1.empty()) 
                nge[j] = st1.top();
            st.push(i);
            st1.push(j);
        }
        for(int i = 0; i < k; i++) 
        {
            int x = q[i] - 1;
            int seg = nge[x] - pge[x] - 1;
            cout << seg << "\n";
        }
    }
}

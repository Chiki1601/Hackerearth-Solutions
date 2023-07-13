#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], left[n] = {0}, right[n] = {0};
        for(int i = 0; i < n; i++)
        cin >> a[i];
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && a[st.top()] >= a[i])
                st.pop();
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && a[st.top()] >= a[i])
                st.pop();
            if(st.empty())
                right[i] = -1;
            else
                right[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++)
        {
            if(left[i] == -1 || right[i] == -1)
                cout << "-1 ";
            else
                cout << right[i] - left[i] - 2 << " ";
        }
        cout << "\n";
    }
}

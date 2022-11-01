#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int a[n], count = 0, ans = 0;
    stack<int> st;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    st.push(0);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > 0)
            st.push(i);
        else
        {
            int top = st.top();
            st.pop();
            if(-1 * a[i] == a[top] )
            {
                if(!st.empty())
                    ans = max(ans, abs(i - st.top()));
                else
                    st.push(i);
            }
            else
                st.push(i);
        }
    }
    cout << ans << endl;
    return 0;
}

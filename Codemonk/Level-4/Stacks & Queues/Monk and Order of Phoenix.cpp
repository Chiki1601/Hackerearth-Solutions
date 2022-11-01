#include <bits/stdc++.h>
using namespace std;
vector <long long> v[100];
stack <long long> st;
int n;

int bs(int i, int val)
{
    int l = 0, r = v[i].size();
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(v[i][mid] > val)
            r = mid;
        else
            l = mid + 1;
    }
    if(v[i][l] > val)
        return l;
    return -1;
}

bool check()
{
    long long cur = st.top();
    for(int i = 1; i < n; i++)
    {
        int ans = bs(i, cur);
        if(ans == -1)
            return false;
        else
            cur = v[i][ans];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, y, q, c = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        for(int j = 0; j < x; j++)
        {
            cin >> y;
            v[i].push_back(y);
        }
    }
    st.push(v[0][0]);
    for(int i = 1; i < v[0].size(); i++)
    {
        if(v[0][i] < st.top())
            st.push(v[0][i]);
        else
        st.push(st.top());
    }
    cin >> q;
    long long ind, k, val;
    for(int i = 0; i < q; i++)
    {
        cin >> ind;
        if(ind == 1)
        {
            cin >> k >> val;
            k -= 1;
            v[k].push_back(val);
            if(k == 0)
            {
                if(val < st.top())
                    st.push(val);
                else
                    st.push(st.top());
            }
        }
        else if(ind == 0)
        {
            cin >> k;
            k -= 1;
            v[k].pop_back();
            if(k == 0)
                st.pop();
        }
        else
        {
            if(check())
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}

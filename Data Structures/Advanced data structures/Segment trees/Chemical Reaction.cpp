#include<bits/stdc++.h>
using namespace std;
vector<int> st;
 
void buildst(int idx,int ss,int se)
{
    if(ss == se)
    {
        st[idx] = 1;
        return ;
    }
    int mid = (ss + se) >> 1;
    buildst(2 * idx + 1, ss, mid);
    buildst(2 * idx + 2, mid + 1, se);
    st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
}
 
void update(int idx, int ss, int se, int index)
{
    if(ss == se)
    {
        st[idx] = 0;
        return;
    }
    int mid = (ss + se) >> 1;
    if(index <= mid) 
        update(2 * idx + 1, ss, mid, index);
    else 
        update(2 * idx + 2, mid + 1, se, index);
    st[idx] = st[2 * idx + 1] + st[2 *idx + 2];
}
 
int query(int idx, int ss, int se, int k)
{
    if(ss == se) 
        return ss;
    int mid = (ss + se) >> 1;
    return st[2 * idx + 1] >= k ? query(2 * idx + 1, ss, mid, k) : query(2 * idx + 2, mid + 1, se, k - st[2 * idx + 1]);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    assert(t <= 10);
    while(t--)
    {
        int n, i;
        cin >> n;
        assert(n <= 1000000);
        vector<int> arr(n);
        char str[500000][15];
        for(int i = 0; i < n; i++) 
            cin >> str[i];
        for(int i = 0; i < n; i++) 
            cin >> arr[i];
        int size = (ceil)(log2(n)) + 1, MAX = -1;
        st.resize(1 << size);
        buildst(0, 0, n - 1);
        for(int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            int getx = query(0, 0, n - 1, x);
            MAX = max(MAX, arr[getx]);
            cout << str[getx] << " " << MAX << "\n";
            update(0, 0, n - 1, getx);
        }
        int getx = query(0, 0, n - 1, 1);
        MAX = max(MAX, arr[getx]);
        cout << str[getx] << " " << MAX << "\n";
        update(0, 0, n - 1, getx);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<long long> arr, PW;
long long st[800004], A[800004];
bool F[800004];
 
void pre_process(int n)
{
    PW.resize(n + 1);
    PW[0] = 1;
    for(int i = 1; i < n + 1; i++)
        PW[i] = (2 * PW[i - 1]) % 1000000007;
    for(int i = 1; i < n + 1; i++)
        PW[i] = (PW[i] + PW[i - 1]) % 1000000007;
}
 
void adjust(int idx, int ss, int se)
{
    st[idx] = (st[idx] + ((A[idx] % 1000000007) * ((PW[se - ss]) % 1000000007)) % 1000000007) % 1000000007;
    int mid = (ss + se)>>1;
    if(ss != se)
    {
        A[2 * idx + 1] = (A[2 * idx + 1] + A[idx]) % 1000000007;
        A[2 * idx + 2] = (A[2 * idx + 2] + ((A[idx] % 1000000007) * (((PW[mid - ss + 1] - PW[mid - ss]) % 1000000007 + 1000000007) % 1000000007)) % 1000000007) % 1000000007;
        F[2 * idx + 1] = F[2 * idx + 2] = true;
    }
    F[idx] = 0;
    A[idx] = 0;
    return ;
}
 
void update(int idx, int ss, int se, int l, int r)
{
    if(F[idx])
        adjust(idx, ss, se);
    if(l > se || r < ss) 
        return ;
    if(l <= ss && se <= r)
    {
        st[idx] = (st[idx] % 1000000007 + ((PW[se - l + 1] - PW[ss - l]) % 1000000007 + 1000000007) % 1000000007) % 1000000007;
        if(ss != se)
        {
            int mid = (ss + se)>>1;
            A[2 * idx + 1] = (A[2 * idx + 1] + ((PW[ss - l + 1] - PW[ss - l]) % 1000000007 + 1000000007) % 1000000007) % 1000000007;
            A[2 * idx + 2] = (A[2 * idx + 2] + ((PW[mid - l + 2] - PW[mid + 1 - l]) % 1000000007 + 1000000007) % 1000000007) % 1000000007;
            F[2 * idx + 1] = F[2 *idx + 2] = true;
        }
        return ;
    }
    int mid = (ss + se)>>1;
    update(2 * idx + 1, ss, mid, l, r);
    update(2 * idx + 2, mid + 1, se, l, r);
    st[idx] = (st[2 * idx + 1] + st[2 * idx + 2]) % 1000000007;
}
 
long long query(int idx, int ss, int se, int l, int r)
{
    if(F[idx]) 
        adjust(idx, ss, se);
    if(l > se || r < ss) 
        return 0;
    if(l <= ss && se <= r) 
        return st[idx] % 1000000007;
    int mid = (ss + se)>>1;
    long long L = query(2 * idx + 1, ss, mid, l, r), R = query(2 * idx + 2, mid + 1, se, l, r);
    return (L + R) % 1000000007;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, q;
    cin >> n;
    pre_process(n);
    arr.resize(n + 1);
    for(int i = 1; i < n + 1; i++)
    {
        long long x;
        cin >> x;
        arr[i] = (x + arr[i - 1]) % 1000000007;
    }
    cin >> q;
    while(q--)
    {
        int c, l, r;
        cin >> c >> l;
        l--;
        cin >> r;
        r--;
        if(!c)
            update(0, 0, n - 1, l, r);
        else
        {
            long long ans1 = query(0, 0, n - 1, l, r) % 1000000007, ans2 = ((arr[r + 1] - arr[l]) % 1000000007 + 1000000007) % 1000000007;
            ans1 = (ans1 + ans2) % 1000000007;
            cout << ans1 << endl;
        }
    }
    return 0;
}

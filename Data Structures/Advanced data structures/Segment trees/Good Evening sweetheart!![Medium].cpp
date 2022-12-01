#include<bits/stdc++.h>
using namespace std;
int N, M, H[111111],C[111111];
 
struct segtree
{
    vector<int> dat, put;
    segtree() : dat((1 << 17) * 2), put((1 << 17) * 2){}
    inline void push(int k, int l, int r)
    {
        dat[k] += put[k] * (r - l);
        if(k < (1 << 17) - 1)
        {
            put[k * 2 + 1] += put[k];
            put[k * 2 + 2] += put[k];
        }
        put[k] = 0;
    }
    void update(int a, int b, int x, int k = 0, int l = 0, int r = (1 << 17))
    {
        push(k, l, r);
        if(r <= a | b <= l)
            return;
        if(a <= l && r <= b)
        {
            put[k] += x;
            push(k, l, r);
            return;
        }
        update(a, b, x, k * 2 + 1, l, (l + r) / 2);
        update(a, b, x, k * 2 + 2, (l + r) / 2, r);
        dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
    }
    int query(int a, int b, int k = 0, int l = 0, int r = (1 << 17))
    {
        push(k, l, r);
        if(r <= a || b <= l)
            return 0;
        if(a <= l && r <= b)
            return dat[k];
        return query(a, b, k * 2 + 1, l, (l + r) / 2) + query(a, b, k * 2 + 2, (l + r) / 2, r);
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> H[i];
    for(int i = 0; i < M; i++)
        cin >> C[i];
    sort(H, H + N);
    segtree seg;
    for(int i = 0; i < N; i++)
        seg.update(i, i + 1, H[i]);
    for(int i = 0; i < M; i++)
    {
        int x = seg.query(N - C[i], N - C[i] + 1), lb = -1, ub = N - C[i];
        while(ub - lb > 1)
        {
            int mid = (ub + lb) / 2;
            if(seg.query(mid, mid + 1) == x)
                ub = mid;
            else 
                lb = mid;
        }
        int l = ub;
        lb = N - C[i], ub = N;
        while(ub - lb > 1)
        {
            int mid = (ub + lb) / 2;
            if(seg.query(mid, mid + 1) == x)
                lb = mid;
            else 
                ub = mid;
        }
        int r = ub;
        if(x == 0)
        {
            cout << i << endl;
            return 0;
        }
        seg.update(r, N, -1);
        seg.update(l, l + C[i] - (N - r), -1);
    }
    cout << M << endl;
}

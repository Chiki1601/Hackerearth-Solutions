#include <bits/stdc++.h>
using namespace std;
long long bt1[2000010], bt2[2000010], nb;
 
inline void updh(long long x, long long val, long long *bt) 
{
    x++;
    for(long long i = x; i <= nb; i += i & -i)
        bt[i] += val;
}
 
inline void upd(long long x, long long X, long long val) 
{
    X++;
    updh(X, -val, bt1); 
    updh(X, -val * X, bt2);
    updh(x, val, bt1); 
    updh(x, val * x, bt2);
}
 
inline long long sumhh(long long x, long long *bt) 
{
    long long sum = 0;
    for(long long i = x; i > 0; i ^= i & -i)
        sum += bt[i];
    return sum;
}
 
inline long long sumh(long long x) 
{
    return sumhh(x, bt1) * x - sumhh(x, bt2);
}
 
inline long long sum(long long x, long long X) 
{
    X++;
    return sumh(X) - sumh(x);
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n; 
    cin >> n;
    nb = n + 2;
    set<long long> s;
    queue<long long> q;
    for(long long i = 0, _n = (n); i < _n; i++) 
    {
        long long e, l, r;
        cin >> e >> l >> r;
        if(s.count(e)) 
        {
            while(q.front() != e) 
            {
                s.erase(q.front());
                q.pop();
            }
            q.pop();
        }
        else 
            s.insert(e);
        q.push(e);
        long long x = q.size();
        upd(1, x, 1);
        if(l > r) 
            cout << "0" << endl; 
        else 
            cout << sum(l, r) << endl;
    }
    return 0;
}

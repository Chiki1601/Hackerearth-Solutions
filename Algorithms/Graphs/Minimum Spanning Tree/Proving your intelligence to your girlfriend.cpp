#include<bits/stdc++.h>
using namespace std;
long long sum;
int par[1000010];
 
inline void mult(long long c[], const long long a[], const long long b[])
{
    int x1 = (a[0] * b[0] + a[1] * b[2]) % 1000000007, x2 = (a[0] * b[1] + a[1] * b[3]) % 1000000007, x3 = (a[2] * b[0] + a[3] * b[2]) % 1000000007, x4 = (a[2] * b[1] + a[3] * b[3]) % 1000000007;
    c[0] = x1; c[1] = x2; c[2] = x3; c[3] = x4;
}
 
long long fib(long long n)
{
    long long res[4], c[4];
    res[0] = 1; res[1] = 0; res[2] = 0; res[3] = 1;
    c[0] = 1; c[1] = 1; c[2] = 1; c[3] = 0;
    while(n > 0)
    {
        if(n & 1)
            mult(res, res, c);
        mult(c, c, c);
        n /= 2;
    }
    return res[1];
}
 
int find_par(int x)
{
    return (x == par[x]) ? x : par[x] = find_par(par[x]);
}
 
void init(int n)
{
    for(int i = 0; i < n; i++)
        par[i] = i;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j;
    long long k1, k2, k3, k4;
    cin >> n;
    assert(1 <= n && n <= 1000);
    init(n * n);
    cin >> k1 >> k2 >> k3 >> k4;
    assert(1<= k1 && k1 <= 1000000000000000000);
    assert(1<= k1 && k1 <= 1000000000000000000);
    assert(1<= k1 && k1 <= 1000000000000000000);
    assert(1<= k1 && k1 <= 1000000000000000000);
    long long fk1 = fib(k1) , fk2 = fib(k2) , fk3 = fib(k3) , fk4 = fib(k4);
    long long fk_1 = fib(k1 - 1) , fk_2 = fib(k2 - 1) , fk_3 = fib(k3 - 1), fk_4 = fib(k4 - 1);
    vector<pair<int, pair<int, int>>> graph;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            int u = n * i + j , v, w = 0;
            if(j < n - 1)
            {
                v = n * i + j + 1;
                w = (fk1 + fk2) % 1000000007;
                long long tmp = fk1;
                fk1 += fk_1;
                if(fk1 >= 1000000007)
                    fk1 %= 1000000007;
                fk_1 = tmp;
                tmp = fk2;
                fk2 += fk_2;
                if(fk2 >= 1000000007)
                    fk2 %= 1000000007;
                fk_2 = tmp;
                graph.push_back(make_pair(w, make_pair(u, v)));
            }
        }
    }
    for(j = 0; j < n; j++)
    {
        for(i = 0; i < n; i++)
        {
            int u = n * i + j, v, w = 0;
            if(i < n - 1)
            {
                v = n * (i + 1) + j;
                w = (fk3 + fk4) % 1000000007;
                graph.push_back(make_pair(w, make_pair(u, v)));
                long long tmp = fk3;
                fk3 += fk_3;
                if(fk3 >= 1000000007)
                    fk3 %= 1000000007;
                fk_3 = tmp;
                tmp = fk4;
                fk4 += fk_4;
                if(fk4 >= 1000000007)
                    fk4 %= 1000000007;
                fk_4 = tmp;
            }
        }
    }
    sort(graph.begin(), graph.end());
    for(int i = 0; i < graph.size(); i++)
    {
        int pu = find_par(graph[i].second.first), pv = find_par(graph[i].second.second);
        if(pu != pv)
        {
            sum += graph[i].first;
            par[pu] = pv;
        }
    }
    cout << sum << endl;
    return 0;
}

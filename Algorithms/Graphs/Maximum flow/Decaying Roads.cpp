#include<bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, z, voog, mit;
vector<long long> v[4005];
bool b, kul[4005];
 
struct tee
{
    long long a, l, v;
};tee p;
vector<tee> t;
 
void rek(long long l)
{
    if(l == n + m + 1)
    {
        b = 1;
        voog++;
        return;
    }
    kul[l] = 1;
    long long o;
    for(int i = 0; i < v[l].size(); i++)
    {
        o = v[l][i];
        if(t[o].v && !kul[t[o].l])
            rek(t[o].l);
        if(!t[o].v && !kul[t[o].a])
            rek(t[o].a);
        if(b)
        {
            if(t[o].a == l) 
                t[o].v--;
            else 
                t[o].v++;
            return ;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    p.v = 1;
    p.a = 0;
    for(int i = 1; i <= n; i++)
    {
        p.l = i;
        t.push_back(p);
        v[0].push_back(t.size() - 1);
        v[i].push_back(t.size() - 1);
    }
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        p.a = x;
        p.l = n + y;
        t.push_back(p);
        v[x].push_back(t.size() - 1);
        v[n + y].push_back(t.size() - 1);
    }
    p.l = n + m + 1;
    for(int i = 1; i <= m; i++)
    {
        cin >> x;
        p.a = n + i;
        p.v = x;
        t.push_back(p);
        v[n + i].push_back(t.size() - 1);
        v[n + m + 1].push_back(t.size() - 1);
    }
    b = 1;
    while(b)
    {
        b = 0;
        memset(kul, 0, sizeof(kul));
        rek(0);
    }
    cin >> z;
    for(int i = 0; i < z; i++)
    {
        cout << voog << endl;
        cin >> x >> y;
        long long o = v[x + n][v[x + n].size() - 1];
        if(y > t[o].v)
        {
            mit = y - t[o].v;
            voog -= mit;
            t[o].v = 0;
            b = 1;
            while(mit && b)
            {
                b = 0;
                memset(kul, 0, sizeof(kul));
                rek(n + x);
                mit--;
            }
        }
        else 
            t[o].v -= y;
    }
}

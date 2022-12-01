#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int L[200010], R[200010], Count = 0;
bool KT[1000005];
vector <int> a[200010], SNT;
vector <pair<pair<int, int>, int>> Pos[78500];
 
long long rand(long long l, long long r)
{
    return 1LL * (1LL * rnd() * RAND_MAX + rnd()) % (r - l + 1) + l;
}
 
void DFS(int u) 
{
    L[u] = ++Count;
    for(int x : a[u]) 
        DFS(x);
    R[u] = Count;
}
 
int ID(int x) 
{
    return lower_bound(SNT.begin(), SNT.end(), x) - SNT.begin();
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int oo = 1e6, count = 0, Ans = 0, n, Q, Type[300010], Le[300010], Ri[300010], W[300010], p[1000002];
    cin >> n >> Q;
    for(int i = 1; i < n; i++) 
    {
        int x;
        cin >> x;
        a[x].push_back(i + 1);
    }
    for(int i = 1; i <= Q; i++) 
    {
        cin >> Type[i] >> Le[i] >> Ri[i];
        if(Type[i] == 1) 
            cin >> W[i];
        else 
            KT[Ri[i]] = 1;
    }
    for(int i = 2; i <= oo; i++) 
        p[i] = i;
    for(int i = 2; i <= oo; i++) 
    {
        if(p[i] == i) 
        {
            for(int j = i + i; j <= oo; j += i) 
                p[j] = i;
            SNT.push_back(i);
        }
    }
    DFS(1);
    for(int i = 1; i <= Q; i++) 
    {
        if(Type[i] == 1) 
        {
            int u, v, w;
            u = Le[i]; v = Ri[i]; w = W[i];
            u = (u + Ans - 1) % n + 1;
            v = (v + Ans - 1) % n + 1;
            if(L[u] > L[v]) 
                swap(u, v);
            int x = w;
            while(x > 1) 
            {
                int tmp = p[x];
                while(x > 1 && x % tmp == 0) 
                    x /= tmp;
                if(KT[tmp]) 
                    Pos[ID(tmp)].push_back(pair<pair<int, int>, int>(pair<int, int>(L[u], L[v]), w));
            }
        }
        else 
        {
            int v, p, Res = 0;
            v = Le[i]; 
            p = Ri[i];
            v = (v + Ans - 1) % (n - 1) + 2;
            for(pair<pair<int, int>, int> x : Pos[ID(p)]) 
            {
                int u = x.first.first, vv = x.first.second, w = x.second;
                if((u < L[v] && vv >= L[v] && vv <= R[v]) || (u >= L[v] && u <= R[v] && vv > R[v]))
                    Res += w;
            }
            cout << Res << endl;
            Ans = Res;
        }
    }
}

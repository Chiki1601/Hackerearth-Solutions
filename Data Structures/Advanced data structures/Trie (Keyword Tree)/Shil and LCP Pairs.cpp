#include <bits/stdc++.h> 
using namespace std; 
int n, ptr[1 << 20][26], cnt[1 << 20], nodes;
long long ans[1 << 20];
 
void walk(int u, int x) 
{
    ans[x] += (long long)cnt[u] * (cnt[u] - 1) / 2;
    for (int d = 0; d < 26; ++d) 
    {
        if (ptr[u][d]) 
            walk(ptr[u][d], x + 1);
    }
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int ks = 1; ks <= 1000000000 && 1 == scanf("%d", &n); ++ks) 
    {
        nodes = 1;
        int l = 0;
        char buf[1 << 20];
        for(int i = 0; i < n && 1 == scanf("%s", buf); ++i) 
        {
            const char* p = buf;
            int u = 0;
            while(*p) 
            {
                ++cnt[u];
                int d = *p - 'a';
                if(!ptr[u][d])
                ptr[u][d] = nodes++;
                u = ptr[u][d];
                ++p;
            }
            ++cnt[u];
            l = max(l, int(p - buf));
        }
        walk(0, 0);
        for(int i = 0; i < l; ++i) 
            ans[i] -= ans[i + 1];
        for(int i = 0; i <= l; ++i) 
            cout << ans[i] << " ";
        puts("");
    }
    return 0;
}

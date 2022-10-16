#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> c_all, p_all;
 
int lcs(int i, int j) 
{
    int ans = 0;
    for(int k = c_all.size() - 1; k >= 0; k--) 
    {
        if((i + 1 - (1 << k)) < 0 || (j + 1 - (1 << k)) < 0) 
            continue;
        if(c_all[k][i + 1 - (1 << k)] == c_all[k][j + 1 - (1 << k)]) 
        {
            ans += 1 << k;
            i -= 1 << k;
            j -= 1 << k;
        }
    }
    return ans;
}
 
vector<int> suffix_array(string s) 
{
    s += "$";
    int n = s.size(), classes = 0, length = 1;
    vector<int> p(n), c(n), cnt(max(256, n), 0);
    for(int i = 0; i < n; i++)
        cnt[s[i]]++;
    for(int i = 1; i < 256; i++)
        cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    for(int i = 1; i < n; i++) 
    {
        if(s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes;
    }
    c_all.push_back(c);
    p_all.push_back(p);
    vector<int> pn(n), cn(n);
    while(length < n)
    {
        fill(cnt.begin(), cnt.end(), 0);
        for(int i = 0; i < n; i++) 
            pn[i] = (p[i] - length + n) % n;
        for(int i = 0; i < n; i++) 
            cnt[c[pn[i]]]++;
        for(int i = 1; i < n; i++) 
            cnt[i] += cnt[i - 1];
        for(int i = n-1; i >= 0; i--) 
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 0;
        for(int i = 1; i < n; i++) 
        {
            pair<int, int> cur = {c[p[i]], c[(p[i] + length) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + length) % n]};
            if (cur != prev) 
                classes++;
            cn[p[i]] = classes;
        }
        c.swap(cn);
        length *= 2;
        c_all.push_back(c);
        p_all.push_back(p);
    }
    p.erase(p.begin());
    return p;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    string s;
    cin >> s;
    int n = s.size(), q;
    vector<int> sa = suffix_array(s);
    vector<int> ans(n);
    for(int i = 0; i < n; i ++)
        ans[i] = lcs(i, n - 1);
    cin >> q;
    for(int i = 0; i < q; i ++)
    {
        int a;
        cin >> a;
        cout << ans[a - 1] << endl;
    }
}

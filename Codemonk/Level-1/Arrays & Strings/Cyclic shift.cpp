#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i) 
	{
        if(i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> sort_cyclic_shifts(string const& s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for(int i = 0; i < n; i++)
        cnt[s[i]]++;
    for(int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i++) 
	{
        if(s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; ++h) 
	{
        for(int i = 0; i < n; i++) 
		{
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for(int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) 
		{
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if(cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

string flip(string s)
{
    string a;
    for(long long int  i = 0; i < s.length(); i++)
    {
        if(s[i] == '0')
            a += '1';
        else
            a += '0';
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t;
    cin >> t;
    while(t--)
    {
        string s;
        long long int n, p;
        cin >> n >> p;
        cin >> s;
        s = flip(s);
        vector<int> z = z_function(s);
        long long int period = n;
        for(long long int i = 1; i < n; i++)
        {
            if(i + z[i] == n && n % i == 0)
            {
                period = i;
                break;
            }
        }
        string A = s.substr(0,period);
        vector<int> v = sort_cyclic_shifts(A);
        long long int  ans = v[0] + (p - 1) * period;
        cout << ans << "\n";
    }
	return 0;
}

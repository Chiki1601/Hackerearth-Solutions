#include <bits/stdc++.h>
using namespace std;
char T[1000005];
int sa[1000005], tsa[1000005], ra[1000005], tra[1000005], lcp[1000005], plcp[1000005], phi[1000005], c[1000005], K, n, N;
 
void sort(int k) 
{
    memset(c, 0, sizeof c);
    for(int i = 0; i < N; i++) 
        c[i + k < N ? ra[i + k] : 0]++; 
    int sum = 0, maxi = max(300, N);
    for(int i = 0; i < maxi; i++) 
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for(int i = 0; i < N; i++) 
    {
        int cur = sa[i] + k < N ? ra[sa[i] + k] : 0; 
        tsa[c[cur]++] = sa[i];
    }
    memcpy(sa, tsa, sizeof(int) * N);
}
 
void build_sa() 
{
    for(int i = 0; i < N; i++) 
    {
        ra[i] = T[i];
        sa[i] = i;
    }
    for(int k = 1; k < N; k *= 2) 
    {
        sort(k);
        sort(0);
        int r = tra[sa[0]] = 0;
        for(int i = 1; i < N; i++) 
        {
            if(ra[sa[i]] == ra[sa[i - 1]]) 
            {
                int cur = (sa[i] + k) < N ? ra[sa[i] + k] : 0;
                int prev = (sa[i - 1] + k) < N ? ra[sa[i - 1] + k] : 0;
                if(cur == prev) 
                    tra[sa[i]] = r;
                else 
                    tra[sa[i]] = ++r;
            }
            else 
                tra[sa[i]] = ++r;
        }
        if(tra[sa[N - 1]] == N - 1) 
            break;
        memcpy(ra, tra, sizeof(int) * N);
    }
}
 
void build_lcp() 
{
    phi[sa[0]] = -1;
    for(int i = 1; i < N; i++) 
        phi[sa[i]] = sa[i - 1];
    int l = 0;
    for(int i = 0; i < N; i++) 
    {
        if(phi[i] == -1) 
        {
            plcp[i] = 0;
            continue;
        }
        while(T[i + l] == T[phi[i] + l]) 
            l++;
        plcp[i] = l;
        l = max(l - 1, 0);
    }
    for(int i = 0; i < N; i++) 
        lcp[i] = plcp[sa[i]];
}
 
int main() 
{
    cin >> K >> n;
	cin >> T;
	N = strlen(T);
	if(K == 1) 
    {
		cout << N << endl;
		return 0;
	}
	T[N++] = '$';
	build_sa();
	build_lcp();
	multiset<int> ms;
	for(int i = 1; i < K; i++) 
		ms.insert(lcp[i]);
	int ans = max(1, *ms.begin());
	for(int i = K; i < N; i++) 
    {
		ms.erase(ms.find(lcp[i - K + 1]));
		ms.insert(lcp[i]);
		ans = max(ans, *ms.begin());
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[2000001], t[100001];
int F[2000001], sa[2000001], idx[2000001], tmp[2000001], N, gap, T[2][5000000];
pair<string, int> A[100001];
 
void make(int n, int start, int end)
{
	if(start == end) 
    {
		T[0][n] = T[1][n] = sa[start-1];
		return;
	}
	int mid = (start + end) >> 1;
	make(n<<1, start, mid);
	make(n<<1|1, mid + 1, end);
	int a = T[0][n<<1], b = T[0][n<<1|1];
	if(tmp[a] <= tmp[b]) 
        T[0][n] = a; 
    else 
        T[0][n] = b;
	a = T[1][n<<1], b = T[1][n<<1|1];
	if(tmp[a] >= tmp[b]) 
        T[1][n] = a; 
    else 
        T[1][n] = b;
}
 
int query(int n, int start, int end, int l, int r, int t)
{
	if(start > end || start > r || end < l) 
        return t == 0 ? N : N + 1;
	if(start >= l && end <= r) 
        return T[t][n];
	int mid = (start + end) >> 1, a = query(n<<1, start, mid, l, r, t), b = query(n<<1|1, mid + 1, end, l, r, t);
	if(t == 0) 
    {
		if(tmp[a] <= tmp[b]) 
            return a; 
        else 
            return b;
	} 
    else 
    {
		if(tmp[a] >= tmp[b]) 
            return a; 
        else 
            return b;
	}
}
 
bool comp(int i, int j)
{
	if(idx[i] != idx[j]) 
        return idx[i] < idx[j]; i += gap; j += gap;
	return (i < N && j < N ? idx[i] < idx[j] : i > j);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, k, x, y, z, start, mid, end, a, b;
	cin >> n >> m;
	for(i = 0; i < 4 * n; ++i) 
		T[0][i] = 1000000007;
	j = 0;
	z = 0;
	for(i = 0; i < n; ++i) 
    {
		cin >> t;
		A[i].first = string(t) + '$';
		A[i].second = z;
		z += A[i].first.size();
		for(k = 0; t[k]; ++k)
			s[j++] = t[k];
		s[j++] = '$';
		F[i] = k + 1;
		if(i) 
            F[i] += F[i-1];
		else 
            F[i]--;
	}
	N = j;
	for(int i = 0; i < N; ++i) 
        sa[i] = i, idx[i] = s[i];
 	for(gap = 1; ; gap *= 2) 
     {
		sort(sa, sa + N, comp);
		for(i = 0; i < N - 1; ++i) 
            tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
		for(i = 0; i < N; ++i) 
            idx[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) 
            break;
	}
	s[N] = '\0';
	sort(A, A + n);
	for(i = 0; i < n; ++i) 
    {
		y = A[i].second;
		z = y + A[i].first.size();
		for(j = y; j < z; ++j) 
			tmp[j] = i;
	}
	tmp[N] = 1000000007;
	tmp[N + 1] = -1;
	make(1, 1, N);
	while(m--) 
    {
		cin >> t;
		y = strlen(t);
		a = b = -1;
		start = 0;
		end = N - 1;
		while(start <= end) 
        {
			mid = (start + end) >> 1;
			x = strncmp(t, s + sa[mid], y);
			if(x == 0) 
            {
				a = mid;
				end = mid - 1;
			} 
            else if(x < 0)
				end = mid - 1;
			else
				start = mid + 1;
		}
		start = 0;
		end = N - 1;
		while(start <= end) 
        {
			mid = (start + end) >> 1;
			x = strncmp(t, s + sa[mid], y);
			if(x == 0) 
            {
				b = mid;
				start = mid + 1;
			}
            else if(x < 0)
			    end = mid - 1;
			else 
			    start = mid + 1;
		}
        	if(a != -1 && b != -1) 
            {
			x = query(1, 1, N, a + 1, b + 1, 0);
			y = query(1, 1, N, a + 1, b + 1, 1);
			a = lower_bound(F, F + n, x) - F;
			b = lower_bound(F, F + n, y) - F;
        	}
		cout << a << " " << b << endl;
	}
	return 0;
}

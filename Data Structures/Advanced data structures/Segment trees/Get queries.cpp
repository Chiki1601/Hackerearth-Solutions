#include <bits/stdc++.h>
using namespace std;
vector<int> T;
int N, M;
 
int sum(int n)
{
    int s = 0;
    while (n >= 0) 
    {
        s += T[n]; 
        n = (n & (n + 1)) - 1;
    }
    return s;
}
 
void add(int n, int d)
{
    while(n < N) 
    {
        T[n] += d; 
        n |= n + 1;
    }
}
 
int query(int a, int b)
{
    return sum(b) - sum(a - 1);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<string> A(N);
	int i, j;
	T = vector<int>(N);
	for(i = 0; i < N; i++)
	{
		int T1;
		cin >> T1;
		A[i] += to_string(T1);	
		add(i, A[i].size());
	}
	for(i = 0; i < M; i++)
	{
		string C;
		cin >> C;
		if(C[0] == 'u')
		{
			int P, V;
			cin >> P >> V;
			P--;
			int T = -A[P].size();
			A[P] = to_string(V);
			T += A[P].size();
			add(P, T);
		}
		else
		{
			int L, R, K;
			cin >> L >> R >> K;
			L--;
			R--;
			if(query(L, R) < K)
				cout << -1 << "\n";
			else
			{
				int S = L, E = R;
				while(S < E)
				{
					int C = (S + E) / 2;
					if(query(L, C) >= K)
						E = C;
					else
						S = (C + 1);
				}			
				cout << A[S][(K - query(L, (S - 1)) - 1)] << "\n";
			}
		}
	}
	cout << "\n";
    return 0;
}

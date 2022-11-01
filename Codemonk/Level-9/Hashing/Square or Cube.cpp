#include<bits/stdc++.h>
using namespace std;
long long ara[500005], h1[500005], h2[500005], zr[500005], neg[500005], cnt[100005];

inline long long BigMod(long long B, long long P, long long M)
{
	long long R = 1;
	while(P > 0)
	{
		if(P % 2 == 1)
			R = (R * B) % M;
		P /= 2;
		B = (B * B) % M;
	}
	return R;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	bool stat[100005];
	vector<int>G[100005];
    int sq = sqrt(100000), n, q;
	for(int i = 4; i <= 100000; i += 2)
		stat[i] = 1;
    for(int i = 3; i <= sq; i += 2)
		if(!stat[i])
			for(int j = i * i; j <= 100000; j += 2 * i)
				stat[j] = 1;
    for(int i = 2; i <= 100000; i++)
    {
        if(stat[i] == 0)
		{
            for(int j = i; j <= 100000; j += i)
            {
                int temp = j, cnt = 0;
                while(temp % i == 0)
				{
                    temp /= i;
                    cnt++;
                }
                cnt %= 6;
                while(cnt--)
					G[j].push_back(i);
            }
        }
    }
    long long base = 101, hsq = 0, hcb = 0;
    cin >> n >> q;
    assert(n >= 1 and n <= 300000 and q >= 1 and q <= 300000);
    for(int i = 1; i <= n; i++)
	{
        cin >> ara[i];
        assert(-100000 <= ara[i] and ara[i] <= 100000);
        zr[i] = zr[i - 1] + (ara[i] == 0);
        neg[i] = neg[i - 1] + (ara[i] < 0);
        ara[i] = ((ara[i]) < 0 ? -(ara[i]) : (ara[i]));
        for(int j = 0 ; j < G[ara[i]].size(); j++)
		{
            long long p = G[ara[i]][j];
            long long val = BigMod(base, p, 1000000007);
            if(cnt[p] % 2 == 0)
				hsq = (hsq + val) % 1000000007;
            else 
				hsq = (hsq - val) % 1000000007;
            if(cnt[p] % 3 != 2)
				hcb = (hcb + val) % 1000000007;
            else 	
				hcb = (hcb - 2 * val) % 1000000007;
            cnt[p]++;
        }
        hsq = (hsq + 1000000007) % 1000000007;
        hcb = (hcb + 1000000007) % 1000000007;
        h1[i] = hsq;
        h2[i] = hcb;
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        assert(1 <= l and l <= n and 1 <= r and r <= n and l <= r);
        bool issq = 0, iscb = 0;
        long long sqhash = h1[r] - h1[l - 1], cbhash = h2[r] - h2[l - 1];
        if(zr[r] - zr[l - 1] > 0)
			issq = iscb = 1;
        if((neg[r] - neg[l - 1]) % 2 == 0 and sqhash == 0)
			issq = 1;
        if(cbhash == 0)
			iscb = 1;
        if(issq and iscb)
			cout << "Both" << "\n";
        else if(issq)
			cout << "Square" << "\n";
        else if(iscb)
			cout << "Cube" << "\n";
        else 
			cout << "None" << "\n";
    }
}

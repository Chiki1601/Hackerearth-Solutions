#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	  int n, k, l, r;
    	  cin >> n >> k >> l >> r;
    	  string str, special;
    	  cin >> str >> special;
    	  int check[257] = {0};
    	  for(int i = 0; i < k; i++)
    		    check[special[i]] = 1;
        int cnt[n + 1] = {0};
        if(check[str[0]])   
            cnt[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            cnt[i] = cnt[i-1];
            if(check[str[i - 1]])   
                cnt[i]++;
        }
        int sol = 0, j = 1, K = 1;
        //for(int i = 1; i <= n; i++)  cout << cnt[i] << " ";
        for(int i = 1; i <= n; i++)
        {
            j = max(j, i);
            K = max(K, i);
            while(j <= n && cnt[j] - cnt[i-1] < l)  
                j++;
            while(K <= n && cnt[K] - cnt[i-1] <= r) 
                K++;
            if(j <= n)  
                sol += K - j;
            //cout << i << " " << K << " " << j << " " << sol << endl;
        }
        cout << sol << endl;
    }
}

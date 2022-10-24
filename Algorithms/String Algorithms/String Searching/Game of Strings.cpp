#include<bits/stdc++.h>
using namespace std;
string ss;
int pf[1000005], mxp = 0;
 
void kmp(int pos)
{
    int i, k = 0;
    pf[0] = 0;
    for(i = 1; i < ss.size(); i++)
    {
        while(k && ss[i] != ss[k])
        	k = pf[k - 1];
        if(ss[i] == ss[k])
        	k++;
        pf[i] = k;
        if(i <= pos) 
			mxp = max(mxp, pf[i]);
    }
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{	
	    int i, j, k, pos;
	    cin >> ss >> pos;
	    assert(1 <= ss.size() && ss.size() <= 1000000);
	    assert(1 <= pos && pos <= ss.size());
	        pos--;
	    mxp = 0;
	    memset(pf, 0, sizeof(pf));
	    kmp(pos);
	    k = pf[ss.size() - 1];
	    while(k > mxp && k) 
			k = pf[k - 1];
	    if(k == 0) 
			cout << "Puchi is a cheat!";
	    else for(i = 0; i < k; i++) 
			cout << ss[i];
	    cout << endl;
	}
    return 0;
}

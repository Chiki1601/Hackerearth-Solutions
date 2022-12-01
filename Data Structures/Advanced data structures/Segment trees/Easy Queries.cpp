#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    set<int> s;
    int n, q;
    cin >> n >> q;
    assert(n >= 1 && n <= 100000);
    assert(q >= 1 && q <= 100000);
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        assert(val >= 0 && val <= 1);
        if(val == 1)
            s.insert(i);
    }
    while(q--)
    {
        int type, idx;
        cin >> type >> idx;
        assert(type >= 0 && type <= 1);
        assert(idx >= 0 && idx < n);
        if(type == 1)
            s.insert(idx);  
        else
        {
            int ans_l = -1, ans_r = -1;
            set<int>::iterator it_l = s.lower_bound(idx), it_r = s.upper_bound(idx);
            if(it_l != s.begin() && s.size())
            {
                --it_l;
                ans_l = *(it_l);
            }
            if(it_r != s.end() && s.size())                         
                ans_r = *(it_r);                         
            cout << ans_l << " " << ans_r << endl;
        }
    }
}

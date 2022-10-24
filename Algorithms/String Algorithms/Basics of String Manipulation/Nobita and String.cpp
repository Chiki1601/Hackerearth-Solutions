#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
    cin >> t;
    cin.ignore(1,'\n');
    while(t--)
	{
        string nobi , dore;
        getline(cin, nobi);
        stringstream out(nobi);
        vector<string> swapper;
        while(out>>dore)
            swapper.push_back(dore);
        for(int i = swapper.size() - 1; i >= 0; i--)
            cout << swapper[i] << " ";
        cout << endl;
    }
}

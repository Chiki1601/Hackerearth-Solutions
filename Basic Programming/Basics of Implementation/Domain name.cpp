#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        string x;
        cin >> x;
        for(auto it : x)
        {
            int c = 0;
            if((int(it) >= 65 && int(it) <= 90) || (int(it) >= 97 && int(it) <= 122) || (int(it) >= 48 && int(it) <= 57) || (it == '.') || (it == '-'))
                c = 1;
            assert(c == 1);
        }
        regex integer_expr("(?=^.{4,253}$)(^((?!-)[a-zA-Z0-9-]{0,62}[a-zA-Z0-9]\\.)+[a-zA-Z]{2,63}$)");
    if(regex_match(x, integer_expr))
        cout << "true" << "\n";
    else
        cout << "false" << "\n";
    }
}

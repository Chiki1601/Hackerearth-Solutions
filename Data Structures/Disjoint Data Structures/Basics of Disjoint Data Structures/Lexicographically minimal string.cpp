#include<bits/stdc++.h>
using namespace std;
char par[150];
 
char find(char x)
{
    if(par[x] == x)
        return par[x];
    return par[x] = find(par[x]);
}
 
void unionset(char x, char y)
{
    char parx = find(x), pary = find(y);
    if(parx == pary)
        return;
    if(parx < pary)
        par[pary] = parx;
    else 
        par[parx] = pary;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b, c;
    cin >> a >> b >> c;
    assert(a.size() == b.size());
    for(char i = 'a'; i <= 'z'; i++)
        par[i] = i;
    for(int i = 0; i < a.size(); i++)
        unionset(a[i], b[i]);
    for(int i = 0; i < c.size(); i++)
        cout << find(c[i]);
    cout << endl;
    return 0;
}

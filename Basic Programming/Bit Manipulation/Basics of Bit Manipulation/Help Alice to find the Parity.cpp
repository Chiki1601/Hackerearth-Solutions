#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long L, R;
	cin >> L >> R;
	long long odd = (R - L + 1) / 2;
	if(L % 2 && R % 2) 
        odd++;
	if(odd % 2) 
        cout << "odd" << endl;
	else 
        cout << "even" << endl;
}

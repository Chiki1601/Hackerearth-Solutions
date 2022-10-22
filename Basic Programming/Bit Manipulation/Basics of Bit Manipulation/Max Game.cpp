#include<bits/stdc++.h>
using namespace std;
 
int main() 
{ 
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, sum;
        cin >> N;
        sum = pow(2, (int)log2(N));
        cout << sum << endl;
    }
}

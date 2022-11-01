#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long int> boxes(n);
    for(int i = 0; i < n; i++)
        cin >> boxes[i];
    sort(boxes.begin(), boxes.end());
    long long int ans = 1, prev = boxes[0], temp = 0, count = 1, t_count = 0;
    for(int i = 1; i < n; i++)
	{
        temp += boxes[i]; 
        t_count += 1;
        if(temp > prev and t_count > count)
		{
            prev = temp;
            temp = 0;
            count = t_count;
            t_count = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

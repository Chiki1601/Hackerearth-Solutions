#include <bits/stdc++.h>
using namespace std;
int weight[1009], people[1009], arr[1009], people_data[109];
 
int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; 
	  cin >> t;
    while(t --> 0)
	  {
        int n, max_w, max_p; 
		    cin >> n >> max_p >> max_w;
        for(int i = 1; i < n; ++i)
            cin >> arr[i];
        int total_weight = 0; int total_people = 0;
        for(int i = 1; i <= n; ++i)
            weight[i] = people[i] = 0;
        int result = n; 
		    bool flag = false;
        for(int i = 1; i < n; ++i)
		    {
            total_weight -= weight[i];
            total_people -= people[i];
            for(int j = 1; j <= arr[i]; ++j)
			      {
                cin >> people_data[j];
                ++people[people_data[j]];
            }
            total_people += arr[i];
            int data;
            for(int j = 1; j <= arr[i]; ++j)
			      {
                cin >> data;
                weight[people_data[j]] += data;
                total_weight += data;
            }           
            if(!flag && (total_people > max_p || total_weight > max_w))
            {
                result = i;
                flag = true;
            }
        }
        cout << result << endl;
    }
    return 0;
}

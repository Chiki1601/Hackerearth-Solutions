#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long id, z, p, l, c, s;
    cin >> n;
    vector<pair<long long, long long>> topics;
    map<long long,long long> id_zscore_map;
    for(int i = 0; i < n; i++)
    {
        cin >> id >> z >> p >> l >> c >> s;
        topics.push_back(make_pair((p * 50 + l * 5 + c * 10 + s * 20 - z), id));
        id_zscore_map[id] = z;
    }
    make_heap(topics.begin(), topics.end());
    for(int i = 0; i < 5; i++)
    {
        cout << topics.front().second << " " << id_zscore_map[topics.front().second] + topics.front().first << endl;
        pop_heap (topics.begin(), topics.end()); 
        topics.pop_back();
    }
    return 0;
}

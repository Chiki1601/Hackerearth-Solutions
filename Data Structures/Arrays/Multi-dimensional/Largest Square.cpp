#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  assert(n >= 1 and n <= 2000);
  map<pair<int, int> , bool> is;
  map<int, vector<int> > v;
  for(int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    assert(x >= 1 and x <= 1000000000 and y >= 1 and y <= 1000000000);
    is[make_pair(x, y)] = true;
    v[y].push_back(x);
  }
  for(auto &it : v) {
    sort(it.second.begin(), it.second.end());
  }
  int mx = -1, ansX, ansY;
  for(auto it : v) {
    for(int j = 0; j < (int)it.second.size(); j++) {
      int x1 = it.second[j], y = it.first;
      for(int k = j + 1; k < (int)it.second.size(); k++) {
        int x2 = it.second[k];
        int dif = x2 - x1;
        if(dif == 0 or dif <= mx) continue;
        if(is.find(make_pair(x1, y + dif)) == is.end()) continue;
        if(is.find(make_pair(x2, y + dif)) == is.end()) continue;
        ansX = x1, ansY = y;
        mx = dif;
      }
    }
  }
  if(mx == -1) cout << mx << endl;
  else cout << ansX << " " << ansY << endl;
  return 0;
}

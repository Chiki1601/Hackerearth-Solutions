#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 
 
const int N = 2050;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;
 
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}
 
int n, cnt[26];
char a[N];
ll ans;
 
void solve() { 
  cin >> n;
  assert(1 <= n && n <= 2000);
  for (int i = 1;i <= n;i++) {
    cin >> a[i];
    assert('a' <= a[i] && a[i] <= 'z');
  } 
  for (int i = 1;i <= n;i++) {
    ll now = 0;
    for (int j = i + 1;j <= n;j++) {
      if (a[j] == a[i]) {
        ans += now;
      }
      now += cnt[a[j] - 'a'];
    }
    cnt[a[i] - 'a']++;
  }
  cout << ans << endl;
}
 
int main() {
  #ifdef wws
   freopen("in", "r", stdin);
  #endif 
  ios_base::sync_with_stdio(0);
  int tt = 1; 
  while(tt--) solve();
  return 0;
}

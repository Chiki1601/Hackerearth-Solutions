#include<bits/stdc++.h>
using namespace std;
 
typedef struct data
{
      data* bit[2];
      long long below = 0;
}trie;
trie* head;
 
void insert(long long x)
{
      trie* cur = head;
      long long y = x;
      for(long long i = 63; i >= 0; i--)
      {
            long long t = (1ll << i ), b = (x>>i) & 1;
            cur -> below++  ;
            if(!cur -> bit[b])
                  cur -> bit[b] = new trie();
            cur = cur -> bit[b];
      }
      cur -> below++;
}
 
long long query(long long y, long long k)
{
      long long ans = 0;
      trie* curr = head;
      for(long long i = 63; i >= 0; i--)
      {
            long long t = ( 1ll << i ), b = ( y >> i ) & 1, ava = 0;
            if(curr -> bit[b])
                  ava = curr -> bit[b] -> below;
            if(ava >= k)
                  curr = curr -> bit[b];
            else
            {
                  ans += t;
                  k -= ava; 
                  if(!curr -> bit[!b])
                        curr -> bit[!b] = new trie();
                  curr = curr -> bit[!b];
            }
      }
      return ans;
}
 
int main()
{
      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
      head = new trie();
      long long q;
      cin >> q;
      while(q--)
      {
            long long t;
            cin >> t;
            if(t == 1)
            {
                  long long x;
                  cin >> x;
                  insert(x);
            }
            else
            {
                  long long x, k;
                  cin >> x >> k;
                  cout << query(x, k) << endl;
            }
      }
}

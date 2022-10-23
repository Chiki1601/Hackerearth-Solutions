#include<bits/stdc++.h>
using namespace std;
vector<int>vc[100100];
 
int get(int n, int x, int i = 0, int sgn = 1, int val = 1)
{
    if(i == vc[n].size())
	      return sgn * x / val;
    return get(n, x, i + 1, sgn * -1, val * vc[n][i]) + get(n, x, i + 1, sgn * + 1, val);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 2; i < 100100; i ++)
    {
	      int x = i;
	      for(int j = 2; j * j <= x; j ++)
	          if(x % j == 0)
            {
		            while(x % j == 0)
		                x /= j;
		            for(int p: vc[x])
		                vc[i].push_back(p);
		            vc[i].push_back(j);
		            break;
	          }
	          if(x == i)
	              vc[i].push_back(i);
    } 
    cerr << "pre_process done" << endl;
    int n, a = 0, b = 1;
    long long k;
    cin >> n >> k;
    long double st = 0, en = 1./2, dis = 10;
    for(int i = 0; i < 40; i++)
    {
	      long double mid = (st + en) / 2;
	      long long count = 1; 
	      for(int i = 1; i <= n; i++)
	          count += get(i, floor(mid * i));
	      cerr << mid << ": " << count << endl;
	      if(count >= k)
	          en = mid;
	      else
	          st = mid;
    }
    cerr << "binary search done" << endl;
    cerr << st << endl;
    for(int i = 1; i <= n; i++)
    {
	      int x = st * i;
	      if(abs((long double)(x) / i - st) < dis)
	          a = x, b = i, dis = abs((long double)(x) / i - st);
	      x = st * i + 1;
	      if(abs((long double)(x) / i - st) < dis)
	          a = x, b = i, dis = abs((long double)(x) / i - st);
    }
    cout << a << "/" << b << endl;
}

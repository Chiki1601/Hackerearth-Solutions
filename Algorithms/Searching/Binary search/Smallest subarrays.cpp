#include <bits/stdc++.h> 
using namespace std;
int A[1010101], B[1010101], F[1010101], Ans[1010101], N;
 
int count(int i) 
{
    int sum = 0;
    while (i > 0) 
		    sum += F[i], i -= ((i) & -(i));
    return sum;
}
 
void add(int i) 
{
    while(i <= N) 
		    F[i]++, i += ((i) & -(i));
}
 
int f(int t) 
{
  	int l = 1; int r = N;
  	if(count(r) < t) 
  		  return -1;
  	while(l < r) 
  	{
    	  int mid = (l + r) / 2;
    	  if(count(mid) < t) 
      		  l = mid + 1;
		    else 
      		  r = mid;
  	}
  	return l;
}
 
int main() 
{
  	cin >> N;
  	for(int i = 0; i < N; i++) 
	  	  cin >> A[i];
  	for(int i = 0; i < N; i++) 
	  	  cin >> B[i];
  	vector<int> idx;
  	for(int i = 0; i < N; i++) 
	  	  idx.push_back(i);
  	sort(idx.begin(), idx.end(), [&](int a, int b) {return A[a] > A[b] || (A[a] == A[b] && a > b); });
   	for (int i : idx) 
	  {
    	  add(i + 1);
    	  Ans[i] = f(B[i] + count(i)) - i;
  	}
  	for(int i = 0; i < N; i++) 
	  	  cout << max(-1, Ans[i]) << " ";
}

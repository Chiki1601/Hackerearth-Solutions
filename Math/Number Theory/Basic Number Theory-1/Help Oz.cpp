#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a,int b)
{
	if(b==0) return a;
	if(a%b==0)return b;
	return gcd(b,a%b);
}
 
int main() {
	int M;cin>>M;
	int a[M];
	for(int i=0;i<M;i++){
		cin>>a[i];
	}
 
	int b[M];
	for(int i=0;i<M;i++){
		if(i==M-1)
			b[i]=abs(a[i]-a[0]);
		else
			b[i]=abs(a[i]-a[i+1]);
	}
 
	int g=b[0];
	for(int i=1;i<M;i++)
		g=gcd(g,b[i]);
 
	for(int i=2;i<=g;i++){
		if(g%i==0)
			cout<<i<<" ";
	}
}

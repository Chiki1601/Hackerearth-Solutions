#include<iostream>
using namespace std;
 
// Recursive function to return gcd of a and b
 
long long gcd(long long int a, long long int b)
 
{
 
	if (b == 0)
 
    	return a;
 
	return gcd(b, a % b);
 
}
 
// Function to return LCM of two numbers
 
long long lcm(int a, int b)
 
{
 
    return (a / gcd(a, b)) * b;
 
}
 
int main()
 
{
 
long long int t,a,b;
 
cin>>t;
 
while(t--)
 
{
 
cin>>a>>b;
 
long long int x=lcm(a,b);
 
cout<<x/a<<" "<<x/b<<"\n";
 
}
 
return 0;
 
}

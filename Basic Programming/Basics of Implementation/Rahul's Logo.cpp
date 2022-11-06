#include<bits/stdc++.h>
using namespace std;
 
void g(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2 + i; j++)
			    cout << " ";
        for(int j = 0; j < n - i; j++)
            if(j % 2 == 0)
				        cout << "\\"; 
            else 
				        cout << " ";
        for(int j = n - i; j > 0; j--)
            if(j % 2)
				        cout << "/"; 
            else 
				        cout << " ";
        cout << endl;
    }
}
 
void f(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n - i; j++)
			      cout << " ";
        for(int j = 0; j < i + 1; j++)
            if(j % 2 == 0)
				        cout << "/"; 
            else 
				        cout << " ";
        for(int j = 0; j < i + 1; j++)
            if((i - j) % 2 == 0)
				        cout << "\\"; 
            else 
				        cout << " ";
        cout << endl;
    }
}
 
int main()
{
    int n; 
	  cin >> n; 
    f(n); g(n);
    n++; f(n); g(n);
    return 0;
}

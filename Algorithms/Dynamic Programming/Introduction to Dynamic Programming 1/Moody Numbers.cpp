#include <bits/stdc++.h>
inline void in(int&p) 
{
    p = 0; 
    register char ch = 0;
    while(ch < '0' or ch > '9') 
        ch = getchar();
    while(ch >= '0' and ch <= '9') 
    {
        p = (p<<1) + (p<<3) + ch - '0'; 
        ch = getchar();
    }
}
 
bool f(long long n) 
{
    if(n == 1 || n == 4) 
        return true;
    if(n == 9 || n == 16) 
        return false;
    n *= n;
    int x = 0;
    while(n) 
    {
        x += n % 10;
        n /= 10;
    }
    return f(x);
}
 
int main()
{
    int n, t; 
    in(t); 
    while(t--) 
    { 
        in(n);
        puts(f(n) ? "YES" : "NO");
    }
    return 0;
}

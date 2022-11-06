#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
char *player[] = {"Hacker", "Mishki"};
int dp[1000001];
inline int read() 
{
    int x = 0, c = gc();
    while (c < '0')
        c = gc();
    while (c > '/')
        c ^= '0', x *= 10, x += c, c = gc();
    return x; 
}
 
inline void write(char *s) 
{ 
    while(*s) 
        pc(*s++); 
}
 
int main() 
{
    int n = read(), q = read();
    for (int i = 1; i <= n; dp[i] += dp[i - 1], ++i)
        dp[i] = __builtin_clz(read())&1;
    for (int l, r, w; q--; write(player[w]), pc('\n'))
        l = read(), r = read(), w = dp[r] - dp[l - 1], w &= 1; 
}

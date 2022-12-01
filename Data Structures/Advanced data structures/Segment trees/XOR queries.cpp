#include <bits/stdc++.h>
using namespace std;
int A[50004], Fen[330][100004], CFen[330][100004], Start[50004], Finish[50004], Block[50004];
 
long long int powP(long long int a, long long int b)
{
    if(b == 0) 
        return 1 % 1000000007;
    long long int k;
    k = powP(a, b / 2);
    k = k * k % 1000000007;
    if(b % 2 == 0) 
        return k;
    else 
        return a * k % 1000000007;
}
 
bool bitSet(long long int n, long long int i)
{
    if((n & (1LL<<i)) != 0) 
        return true;
    else 
        return false;
}
 
long long int findGcd(long long int a, long long int b)
{
    if(a == 0) 
        return b;
    else 
        return findGcd(b % a, a);
}
 
int findSum(int Fen[], int ind, int n)
{
    int i, ans = 0;
    for(i = ind; i > 0; i -= (i & -i))
        ans += Fen[i]; 
    return ans;
}
 
void update(int Fen[], int ind, int val, int n)
{
    for(int i = ind; i <= n; i += (i & -i))
        Fen[i] += val;
}
 
int findSumXor(int Fen[],int ind,int n)
{
    int i, ans = 0;
    for(i = ind; i > 0; i -= (i & -i))
        ans ^= Fen[i];
    return ans;
}
 
void updateXor(int Fen[], int ind, int val, int n)
{
    for(int i = ind; i <= n; i += (i & -i))
        Fen[i] ^= val;
}
 
int get_count(int l,int r,int x)
{
    int res = 0;
    for(int i = Block[l]; i <= Block[r]; ++i)
    {
        if(Start[i] >= l && Finish[i] <= r)
            res += findSum(CFen[i] , x, 100004);
        else
        {
            for(int j = max(Start[i] , l); j <= min(Finish[i] , r); ++j)
                res += (A[j] <= x);
        }
    }
    return res;
}
 
int get_xor(int l,int r,int x)
{
    int res = 0;
    for(int i = Block[l] ; i <= Block[r] ; ++i)
    {
        if(Start[i] >= l && Finish[i] <= r)
            res ^= findSumXor(Fen[i] , x, 100004);
        else
        {
            for(int j = max(Start[i] , l) ; j <= min(Finish[i] , r) ; ++j)
            {
                if(A[j] <= x) 
                    res ^= A[j];
            }
        }
    }
    return res;
}
 
int solve(int a,int b,int k)
{
    if(k == 0) 
        return 0;
    int low = 1, mid, high = 100000, val, res;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        val = get_count(a, b, mid);
        if(val >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    return get_xor(a, b, res);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, n, m, j, l, r, b, k, q, a, x, curr, ans;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) 
        cin >> A[i];
    i = 1;
    curr = 0;
    while(i <= n)
    {
        j = i;
        curr++;
        Start[curr] = i;
        while(j <= n && j < i + 330)
        {
            Block[j] = curr;
            updateXor(Fen[curr], A[j], A[j], 100004);
            update(CFen[curr], A[j], 1, 100004);
            j++;
        }
        Finish[curr] = j - 1;
        i = j;
    }
    ans = 0;
    while(q--)
    {
        cin >> k;
        if(k==2)
        {
            cin >> l >> r;
            cin >> a >> b;
            l = 1 + ((ans ^ l) % n);
            r = 1 + ((ans ^ r) % n);
            if(l > r) 
                swap(l, r);
            a = 1 + ((a ^ ans) % (r - l + 1));
            b = 1 + ((b ^ ans) % (r - l + 1));
            if(a > b) 
                swap(a, b);
            printf("%d\n", ans = solve(l, r, b) ^ solve(l, r, a - 1));
        }
        else
        {
            cin >> k >> x;
            updateXor(Fen[Block[k]], A[k], A[k], 100004);
            update(CFen[Block[k]], A[k], -1, 100004);
            A[k] = x;
            updateXor(Fen[Block[k]], A[k], A[k], 100004);
            update(CFen[Block[k]], A[k], 1, 100004);
        }
    }
    return 0;
}

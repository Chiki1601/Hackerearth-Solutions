#include <bits/stdc++.h>     
using namespace std;
int n;
long long tree[5][5][100005];
 
void update(int i, int v, long long tree[]) 
{
    while(i <= n)
    { 
        tree[i] += v; 
        i += i & -i;
    }
}
 
long long query(int i, long long tree[]) 
{
    long long ret = 0;
    while(i > 0) 
    {
        ret += tree[i]; 
        i -= i & -i;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scanf("%d",&n);
    int a[5][100005], p[] = {0, 1, 2, 3, 4};
    for(int j = 0; j <= 4; j++) 
        for(int i = 1; i <= n; i++) 
            scanf("%d",&a[j][i]);
    char str[100005];
    scanf("%s" , str+1);
    for(int k = 0; k <= 4; k++) 
        for(int j = 0; j <= 4; j++) 
            for(int i = 1; i <= n; i++) 
                if(str[i] - 'A' == k)
        update(i, a[j][i], tree[k][j]);
    int q;
    scanf("%d",&q);
    while (q--) 
    {
        char ch;
        scanf(" %c%c",&ch,&ch);
        if(ch == 'e') 
        {
            char x, y;
            scanf(" %c %c",&x,&y);
            swap(p[x - 'A'], p[y - 'A']);
        }
        else if(ch == 'c') 
        {
            int x;
            char y;
            scanf("%d %c",&x,&y);
            for(int i = 0; i <= 4; i++)  
                update(x, -a[i][x], tree[str[x] - 'A'][i]);
            for(int i = 0; i <= 4; i++) 
                update(x, a[i][x], tree[y - 'A'][i]);
            str[x] = y;
        }
        else  
        {
            int x, y;
            scanf("%d%d",&x,&y);
            long long ans = 0;
            for(int i = 0; i <= 4; i++) 
                ans += query(y, tree[i][p[i]]) - query(x - 1, tree[i][p[i]]);
            cout << ans << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int sum[100005], a[105];
 
struct node
{
    struct node *lchild,*rchild;
    node()
    {
        lchild = NULL;
        rchild = NULL;
    }
};
 
void ins(struct node *root, int val)
{
    for(int j = 30; j >= 0; j--)
    {
        int x = val & (1<<j);
        if(x)
        {
            if(root->rchild == NULL)
                root->rchild = new node();
            root = root->rchild;
        }
        else
        {
            if(root->lchild == NULL)
                root->lchild = new node();
            root = root->lchild;
        }
    }
}
 
int quey(struct node *root, int val)
{
    int ans = 0;
    for(int j = 30; j >= 0; j--)
    {
        int x = val & (1<<j);
        if(x == 0)
        {
            if(root->lchild)
                root = root->lchild;
            else
            {
                ans |= (1<<j);
                root = root->rchild;
            }
        }
        else
        {
            if(root->rchild)
            {
                ans |= (1<<j);
                root = root->rchild;
            }
            else
                root = root->lchild;
        }
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, i, j, q, u;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    sum[0] = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 100000; j >= a[i]; j--)
        {
            if(sum[j - a[i]])
            {
                sum[j] += sum[j - a[i]];
                if(sum[j] >= 1000000007)
                    sum[j] %= 1000000007;
            }
        }
    }    
    node *root = new node();
    for(i = 1; i <= 100000; i++)
    {
        if(sum[i])
            ins(root, i);
    }
    cin >> q;
    while(q--)
    {
        cin >> u;
        int ans = quey(root, u);
        cout << ans << " " << sum[ans] << endl;
    }
    return 0;
}

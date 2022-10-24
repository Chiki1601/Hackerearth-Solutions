#include<bits/stdc++.h>
using namespace std;
 
struct trie
{
    trie* node[36];
    int last;
    bool end;
    trie()
    {
        last = 0;
        end = false;
        for(int i = 0; i < 36; i++)
            node[i] = NULL;
    }
};
 
bool find(trie * root, string &s, int i)
{
    int y = 26 + s[i] - '0';
    if(root->node[y])
    {
        if(i + 1 != s.size())
            return find(root->node[y], s, i + 1);
        else
        {
            if(root->node[y]->end) 
                return true;
            else 
                return false;
        }
    }
    else
        return false;
}
 
int check(trie* root)
{
    for(int i = root->last; i < 1000005; i++)
    {
        string s = to_string(i);
        if(find(root, s, 0))
            continue;
        else
        {
            root->last = i;
            return i;
        }
    }
    return -1;
}
 
int insert(trie* root, string &s, int i)
{
    if(i >= (int)s.size()) 
        return -1;
    int y = s[i] - 'a';
    if(y < 0)
        y = 26 + s[i] - '0';
    if(root->node[y])
    {
        if(i + 1 != (int)s.size())
            return insert(root->node[y], s, i + 1);
        else
        {
            if(root->node[y]->end)
            {
                int x = check(root->node[y]);
                string s2 = to_string(x);
                insert(root->node[y], s2, 0);
                return x;
            }
            root->node[y]->end = true;
            return -1;
        }
    }
    else
    {
        root->node[y] = new trie();
        root->node[y]->end = false;
        if(i + 1 != s.size())
            return insert(root->node[y], s, i + 1);
        else
        {
            root->node[y]->end = true;
            return -1;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    int n;
    cin >> n;
    string s;
    trie* root = new trie();
    if(n == 1)
    {
        cin >> s;
        cout << s;
        exit(0);
    }
    while(n--)
    {
        cin >> s;
        int x = insert(root, s, 0);
        if(x == -1)
            cout << s << endl;
        else
            cout << s << x << endl;
    }
}

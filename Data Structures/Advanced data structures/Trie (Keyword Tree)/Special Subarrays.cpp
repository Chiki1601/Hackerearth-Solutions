#include<bits/stdc++.h>
using namespace std;
 
class node
{
public:
    char data;
    unordered_map<char, node*> hash;
    bool isTerminal;
    node(char d)
	{
        data = d;
        isTerminal = false;
    }
};
 
class trie
{
    node* root;
public:
    trie()
	{
        root = new node('2');
    }
    void addword(string &s)
    {
        node* temp = root;
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(temp->hash.count(ch) == 0)
			{
                node* child=new node(ch);
                temp->hash[ch] = child;
                temp = child;
            }
            else
                temp = temp->hash[ch];
        }
    }
    int dfs(node *currentNode, int zeroesSeen, bool seenZero)
    {
        seenZero |= (currentNode->data == '0');
        zeroesSeen = (zeroesSeen + (currentNode->data == '0')) % 1000000007;
        int ans = 0LL;
        if(seenZero)
            ans = (zeroesSeen-1LL + 1000000007) % 1000000007;
        for(auto &x : currentNode->hash) 
            ans = (ans + dfs(x.second, zeroesSeen, seenZero) % 1000000007) % 1000000007;
        return ans;
    }
    node *getRoot()
	{
        return root;
    }
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0; 
	cin >> n;
    trie uniquePrefixes;
    for(int i = 0; i < n; i++)
	{
        string s; 
		cin >> s;
        uniquePrefixes.addword(s);
    }
    ans = uniquePrefixes.dfs(uniquePrefixes.getRoot(), 0, false) % 1000000007;
    cout << ans << endl;
    return 0;
}

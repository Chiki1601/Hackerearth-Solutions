#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node* create(int data)
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = 0;
    temp->right = 0;
    return temp;
}

void insert(struct Node *root, int data)
{
    if(data > root->data)
    {
        if(root->right == 0)
            root->right = create(data);
        else
            insert(root->right, data);
    }
    else
    {
        if(root->left == 0)
            root->left = create(data);
        else
            insert(root->left, data);
    }
}

struct Node* findCommonRoot(struct Node* root, int x, int y)
{
    if(x > root->data && y > root->data)
        return findCommonRoot(root->right, x, y);
    else if(x < root->data && y < root->data)
      return findCommonRoot(root->left, x, y);
    else
        return root;
}

int findMax(struct Node * parent, int x, int max) 
{
    if(max < parent->data)
        max = parent->data;
    if(x == parent->data)
        return max;   
    else if(x > parent->data)
        return findMax(parent->right, x, max);
    else if(x < parent->data)
        return findMax(parent->left, x, max);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x, y, data;
    cin >> n >> data;
    struct Node*root = create(data);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> data;
        insert(root, data);
    }
    cin >> x >> y;
    struct Node* parent = findCommonRoot(root, x, y);
    int max1 = findMax(parent, x, 0), max2 = findMax(parent, y, 0);
    if(max2 > max1)
        cout << max2;
    else
        cout << max1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ele;
    cin >> n;
    stack<int> stack;
    for(int i = 0; i < n; i++)
    {
        cin >> ele;
        if(ele == 0)
        {
            cout << stack.top() << " ";
            stack.pop();
        }
        else
            stack.push(ele); 
    }
    return 0;
}

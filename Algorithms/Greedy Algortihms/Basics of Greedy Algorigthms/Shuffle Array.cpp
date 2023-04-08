#include<bits/stdc++.h>
using namespace std;

int getNum(vector<int>& v)
{
    int n = v.size();
    srand(time(NULL));
    int index = rand() % n;
    int num = v[index];
    swap(v[index], v[n - 1]);
    v.pop_back();
    return num;
}

void generateRandom(int n)
{
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        v[i] = i + 1;
    while (v.size()) 
        cout << getNum(v) << " ";
}

int main() 
{
	int n, k, a, d = 0, c = 1;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a;
	while(d < k - 1)
	{
		if(n - c > k - d + 4)
		    c += 5;
		else if(n - c > k - d + 3)
		    c += 4;
		else if(n - c > k - d + 2)
		    c += 3;
		else if(n - c > k - d + 1)
		    c += 2;
		else
		    c++;
		d++;
		cout << c << endl;
	}
	cout << n << endl;
	generateRandom(k);
}

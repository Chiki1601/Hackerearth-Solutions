#include<bits/stdc++.h> 
using namespace std; 
 
int main() 
{ 
	int n, hash[26] = {0}; 
	cin >> n;
   	string str; 
	cin >> str;
    for(char c : str) 
      	hash[c - 'a']++;
    cout << *max_element(hash, hash + 26);
}

#include<bits/stdc++.h>
 
using namespace std;
 
bool isPrime(int n) {
	if (n < 4)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	int i = 5;
	int w = 2;
	while (i * i <= n) {
		if (n % i == 0)
			return false;
		i += w;
		w = 6 - w;
	}
	return true;
}
 
vector<vector<int> > queue_and_stack(vector<int> A) {
	vector<int> prime;
	vector<int> composite;
	stack<int> st;
	for (int n:A) {
		if (isPrime(n))
			prime.push_back(n);
		else
			st.push(n);
	}
	vector<vector<int>> ans;
	while (!st.empty()) {
		composite.push_back(st.top());
		st.pop();
	}
	ans.push_back(prime);
	ans.push_back(composite);
	return ans;
}
 
int main() {
 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i_A = 0; i_A < n; i_A++) {
		cin >> A[i_A];
	}
 
	vector<vector<int> > out_;
	out_ = queue_and_stack(A);
	for (int i_out_ = 0; i_out_ < out_.size(); i_out_++) {
		cout << out_[i_out_][0];
		for (int j_out_ = 1; j_out_ < out_[i_out_].size(); j_out_++) {
			cout << " " << out_[i_out_][j_out_];
		}
		cout << "\n";
	}
}

#include<bits/stdc++.h>
using namespace std;
int n, alp, mod, pow_alp[25], len, p[25], str[25], gl_ans; 
bool used[25]; 
 
template <class T1, class T2> ostream& operator << (ostream& os, const pair<T1, T2> &p) 
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}
 
template <class T> ostream& operator << (ostream& os, const vector<T>& v) 
{
	os << "[";
	bool first = true;
	for(typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if(!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}
 
vector<string> _split(const string& s, char c) 
{
	vector<string> v;
	stringstream ss(s);
	string x;
	while(getline(ss, x, c))
		v.emplace_back(x);
	return v;
}
 
void _print(vector<string>::iterator) {}
template<typename T, typename... Args> void _print(vector<string>::iterator it, T a, Args... args) 
{
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if(isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}
 
int add(int a, int b) 
{
    return (a + b) % mod;
}
 
int mul(int a, int b) 
{
    return (long long int)a * b % mod;
}
 
int get_k() 
{
    int i = len - 1;
    if(i == 0) 
        return 0;
    int k = p[i - 1];
    while(k > 0 && str[i] != str[k]) 
        k = p[k - 1];
    if(str[i] == str[k]) 
        k++;
    return k;
}
 
int get_c(int cur_alp) 
{
    int i = len - 1;
    if(i == 0) 
        return -1;
    if(p[i] != 0) 
        return str[p[i] - 1];
    fill(used, used + cur_alp, false);
    int k = p[i - 1];
    while(true) 
    {
        used[str[k]] = true;
        if(k == 0) 
            break;
        k = p[k - 1];
    }
    for(int c = 0; c < cur_alp; c++) 
    {
        if(!used[c]) 
            return c;
    }
    return -1;
}
 
int get_used_cnt(int cur_alp) 
{
    if(len == 1) 
        return 0;
    int ret = 0;
    for(int i = 0; i < cur_alp; i++) 
    {
        if(used[i]) 
            ret++;
    }
    return ret;
}
 
void rec(int cur_alp, int cur_coef, int cur_mx) 
{
    int prev_p = -1;
    if(len != 0) 
        prev_p = p[len - 1];
    int last = n - len;
    if(cur_mx >= prev_p + last) 
    {
        int cur_ans = mul(cur_coef, cur_mx);
        cur_ans = mul(cur_ans, pow_alp[last]);
        gl_ans = add(gl_ans, cur_ans);
        return;
    }
    len++;
    for(int new_p = 0; new_p <= prev_p + 1; new_p++) 
    {
        p[len - 1] = new_p;
        int new_alp = cur_alp;
        int c = get_c(new_alp);
        if(c == -1) 
        {
            c = new_alp;
            new_alp++;
        }
        str[len - 1] = c;
        int k = get_k();
        if(k == new_p && new_alp <= alp) 
        {
            int new_coef = cur_coef;
            if(new_p == 0) 
            {
                int used_cnt = get_used_cnt(cur_alp);
                new_coef = mul(new_coef, alp - used_cnt);
            }
            rec(new_alp, new_coef, max(cur_mx, new_p));
        }
    }
    len--;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> alp >> mod;
    pow_alp[0] = 1;
    for(int i = 1; i < 25; i++) 
        pow_alp[i] = mul(pow_alp[i - 1], alp);
    rec(0, 1, 0);
    cout << gl_ans << endl;
	return 0;
}

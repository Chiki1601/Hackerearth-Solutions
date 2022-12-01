#include<bits/stdc++.h>
using namespace std;
 
template<class integer> inline integer to_int(const string& s, size_t* idx = 0, int base = 10) 
{
	size_t n = s.size(), i = idx ? *idx : 0; 
    bool sign = false; 
    integer x = 0;
	if(s[i] == '-')
    {
		++i; 
        sign = true;
    }
	function<int(char)> char_to_digit = [&](char c) 
    {
		static const int d[] = {'a' - 10, '0'}; 
		return tolower(c) - d[isdigit(c)]; 
    };
	while(i < n)
    {
		x *= base; 
        x += char_to_digit(s[i++]);
    }
	if(idx)
		*idx = i; 
	return sign ? -x : x; 
}
	
template<class integer>
inline string to_string(integer x, int base = 10) 
{
	bool sign = false; 
    string s;
	if(x < 0)
    {
		x = -x; 
        sign = true;
    }
	function<char(int)> digit_to_char = [](int d) 
    {
		static const char c[] = {'a' - 10, '0'};
		return c[d < 10] + d; 
    };
	do
    { 
		s += digit_to_char(x % base); 
        x /= base;
    }
	while(x > 0); 
	if(sign)
		s += '-';
	reverse(s.begin(), s.end());
	return s; 
}
 
template<class integer> inline istream& read(istream& is, integer& x) 
{
	string s; 
    is >> s, x = to_int<integer>(s); 
    return is; 
}
 
template<class integer> inline ostream& write(ostream& os, integer x) 
{ 
    return os << to_string(x); 
}
  	
inline istream& operator>>(istream& is, signed __int128 &x) 
{ 
    return  read(is, x); 
}
 
inline ostream& operator<<(ostream& os, signed __int128 x) 
{ 
    return write(os, x); 
}
  
int main()
{ 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unsigned long long test_case = 1;
	cin >> test_case;
	for(int i = 1; i <= test_case; i++)
	{	
        signed __int128 n, q;
        cin >> n;
        vector<signed __int128> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cin >> q;
        while(q--)
        {
            signed __int128 type;
            cin >> type;
            if(type == 1)
            {
                signed __int128 pos, val;
                cin >> pos >> val;
                pos--;
                v[pos] = val;
            }
            else
            {
                signed __int128 l, r, ans = 0;
                cin >> l >> r;
                l--, 
                r--;
                for(signed __int128 i = l; i <= r; i++)
                {
                    signed __int128 x = (r - i + 1), y = (i - l), z = v[i];
                    ans = ans + z * x * y;
                    ans = ans + z * x;
                }
                cout << ans << endl;
            }
        }	
    }
	return 0;
}

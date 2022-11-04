#include <bits/stdc++.h>
using namespace std; 
 
template<typename T>class vector2:public vector<vector<T>>
{
	public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}
};
 
/** Product of two 64-bit numbers modulo another. */
unsigned long long mulull(unsigned long long a, unsigned long long z, unsigned long long mod) 
{
#ifdef __SIZEOF_INT128__
	__int128 result = ((__int128) a * (__int128) z) % (__int128) mod;
	return (unsigned long long)result;
#else
    // schrage method
	unsigned long long q = mod / a, r = mod % a;
	unsigned long long rzq = (r < q) ? r * (z/q) : mulull(r, z/q, mod);
	unsigned long long azq = a * (z % q);
	if (azq >= rzq) return azq-rzq; else return azq-rzq+mod;
#endif
}
 
vector<int> SmallPrimes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257};
// 200ns-4us per call, depending on size
bool isPrime(long long n) 
{
    if(n == 2) 
		return true;
    for(int p : SmallPrimes)
        if(p < n && n % p == 0) 
			return false;
	long long d = n - 1, r = 0;
	while(d % 2 == 0) 
	{ 
		d /= 2; 
		r += 1; 
	}
	auto composite = [=](int a) 
	{
		long long x = 1, p = a, e = d;
		while(e > 0) 
		{ 
			if(e % 2 > 0)
				x = mulull(x, p, n);
			e /= 2; 
			p = mulull(p, p, n); 
		}
		if(x == 1 || x == n - 1) 
			return false;
        for(int i = 1; i < r; ++i) 
		{
            x = mulull(x, x, n);
            if(x == 1) 
				return true;
			if(x == n - 1) 
				return false;
		}
        return true;
	};
	return !(composite(2)) && (n < 2047 || !composite(3)) && (n < 1373653 || !composite(5)) && (n < 25326001 || !composite(7)) && (n < 3215031751LL || !composite(11)) && (n < 2152302898747LL || !composite(13)) && (n < 3474749660383LL || !composite(17)) && (n < 341550071728321LL || (!composite(19) && !composite(23))) && (n < 3825123056546413051LL || (!composite(29) && !composite(31) && !composite(37)));
}
 
class PrimeGame 
{
	public:
	    bool isPrime(string S) 
		{
        	stringstream SS(S);
        	long long x; SS >> x;
        	return ::isPrime((unsigned long long)(x));
        	bool prime = true; 
			for(long long i = 2; i * i <= x; ++i) 
			{
            	if(x % i == 0) 
					prime = false;
        	}
        	return prime;
    	}
		void solve(istream& cin, ostream& cout) 
		{
    		int T; 
			cin >> T;
    		for(int t = 0; t < T; ++t) 
			{
        		string S; 
				cin >> S;
        		if(isPrime(S)) 
				{
            		cout << "Prime" << endl;
            		continue;
        		}
        		vector2<bool> D(S.size() + 1, S.size(), true);
        		for(int l = 2; l <= S.size(); ++l) 
				{
            		for(int b = 0; b + l <= S.size(); ++b) 
					{
                		if(!isPrime(S.substr(b, l)) && D[l - 1][b] && D[l - 1][b + 1]) 
                    		D[l][b] = false;
            		}
        		}
        		if (D[S.size()][0])
            		cout << "Alice" << endl;
        		else 
            		cout << "Bob" << endl;
    		}
		}
};
 
int main() 
{
	PrimeGame solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}

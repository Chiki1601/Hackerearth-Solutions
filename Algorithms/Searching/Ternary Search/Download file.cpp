#include <bits/stdc++.h>
using namespace std;
 
int main () 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s, i, j, gcd_;
    long long nom = 0, den = 1, a, b, download[n + 1] = {0};
    cin >> n >> s;
    int t[n], d[n];
    for(i = 0; i < n; i++) 
		cin >> t[i] >> d[i];
    for(i = 1; i < n; i++)
        download[i] = download[i - 1] + (t [i] - t [i - 1]) * d [i - 1];
    download[n] = (s > download[n - 1]) ? s : download[n - 1];
    if(d[n - 1] > 0) 
	{	
		nom = s; 
		den = d[n - 1];
	}
    j = -1;
    i = lower_bound (download, download + (n + 1), s) - download;
    if(not i) 
		i = 1;
    while(i < n) 
	{
        while(download[i] - download[j + 1] >= s) 
			j++;
        a = s - (download[i - 1] - download[j]);
        if(a >= 0) 
		{
            b = d[i - 1];
            a += b * (t[i - 1] - t[j]);
            if(a * den < b * nom) 
			{
				nom = a; 
				den = b;
			}
        }
        a = s - (download[i] - download[j + 1]);
        if(a >= 0) 
		{
            b = d[j];
            a += b * (t[i] - t[j + 1]);
            if (a * den < b * nom) 
			{
				nom = a; 
				den = b;
			}
        }
        i++;
    }
    b = d[n - 1];
    while(j < n) 
	{
        a = s - (download[n - 1] - download[j]);
        if(a >= 0) 
		{
            a += b * (t[n - 1] - t[j]);
            if(a * den < b * nom) 
			{
				nom = a; 
				den = b;
			}
        }
        j++;
    }
    gcd_ = __gcd (nom, den);
    if(gcd_ != 1) 
	{
		nom /= gcd_; 
		den /= gcd_;
	}
    cout << nom << '/' << den << endl;
    return 0;
}

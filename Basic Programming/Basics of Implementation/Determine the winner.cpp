#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int T;
	  cin >> T;
    for(int Z = 0; Z < T; Z++)
	  {
	      long long int s_p, s_q, s_r, s_s;
		    cin >> s_p >> s_q >> s_r >> s_s;
		    long long int d_p, d_q, d_r, d_s;
		    cin >> d_p >> d_q >> d_r >> d_s;
		    long long int f_p, f_q, f_r, f_s;
	 	    cin >> f_p >> f_q >> f_r >> f_s;
		    long long int c_p, c_q, c_r, c_s;
		    cin >> c_p >> c_q >> c_r >> c_s;
		    long long int f_time, f_score, c_time, c_score;
		    f_time = max(max(f_p, f_q), max(f_r, f_s));
		    c_time = max(max(c_p, c_q), max(c_r, c_s));
 		    f_score = max(s_p / 2, s_p - d_p * f_p) + max(s_q / 2, s_q - d_q * f_q) + max(s_r / 2, s_r - d_r * f_r) + max(s_s / 2, s_s - d_s * f_s);
   	    c_score = max(s_p / 2, s_p - d_p * c_p) + max(s_q / 2, s_q - d_q * c_q) + max(s_r / 2, s_r - d_r * c_r) + max(s_s / 2, s_s - d_s * c_s);
 		    if(f_score == c_score)
		    {
		        if(f_time == c_time)
			          cout << "Tie" << endl;
			      else if(f_time > c_time)
			          cout << "Cisco" << endl;
			      else
			          cout << "Flash" << endl;
		    }
		    else
		    {
			      if(f_score > c_score)
			          cout << "Flash" << endl;
			      else
			          cout << "Cisco" << endl;
		    }	
	  }
}

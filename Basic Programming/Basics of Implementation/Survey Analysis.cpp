#include <bits/stdc++.h>
using namespace std;
double days [7 + 10];
 
int main()
{
	int n;
	double sum = 0, day = 0, average, var = 0, standard_Deviation;
	string s;
	for(int i = 0; i < 7; i++)
	{
		cin >> s;
		day = 0;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == '1') 
				days[i]++; // increase the number of visitors in that day
		}
		sum += days[i]; // increase the overall number of visitors	
	}
	average = sum / 7.0; // calculate the mean value
	for(int i = 0; i < 7; i++)  // calculate the summation of the variance
		var += (average - days[i]) * (average - days[i]);
	standard_Deviation = sqrt(var / 7.0); // calculate the standard_Deviation for the average of the variance
	printf("%.4lf\n", standard_Deviation);
	return 0;
}

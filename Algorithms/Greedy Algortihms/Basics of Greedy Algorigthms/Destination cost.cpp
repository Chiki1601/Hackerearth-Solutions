#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int n, count1 = 0, count2 = 0, k = 0; 
    cin >> n;
	  long long int car[n], bus[n], carMore[n], busMore[n], sum = 0;
	  for(int i = 0; i < n; i++) 
        cin >> car[i];
	  for(int i = 0; i < n; i++) 
        cin >> bus[i];
	  for(int i = 0; i < n; i++)
    {
		    sum += min(car[i], bus[i]);
		    if(car[i] < bus[i]) 
            busMore[count2++] = bus[i] - car[i];
		    else if(car[i] == bus[i]) 
            k++;
		    else 
            carMore[count1++] = car[i] - bus[i];
	  }
	  sort(busMore, busMore + count2);
	  sort(carMore, carMore + count1);
	  int z = n / 2 + (n % 2);
	  if(max(count1, count2) > z)
		    if(count1 > count2) 
            for(int i = 0; i < (count1 - z); i++) 
                sum += carMore[i];
		    else for(int i = 0; i < (count2 - z); i++) 
            sum += busMore[i];
	  cout << sum;
	  return 0;
}

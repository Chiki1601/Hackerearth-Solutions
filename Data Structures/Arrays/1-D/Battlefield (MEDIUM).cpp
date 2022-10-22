#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  	int T;
  	cin >> T;
    while(T--)
	{
        int N, k = 0, countK = 0;
        string slide;
        cin >> N;
        cin >> slide;
        slide += slide;
        for(int i = 0; i < N; i++)
			if(slide[i] == 'K')
				++k;
        for(int i = 0; i < k; i++)
            if(slide[i] == 'K')
				++countK;
        int maxK = countK;
        for(int i = k; i < (N + N); i++)
		{
            countK = countK + ((slide[i] == 'K') ? 1 : 0) - ((slide[i - k] == 'K')?1 : 0); 
            maxK = max(maxK, countK);
        }  
       	cout << k - maxK << endl;   
    }   
 	return 0;
}

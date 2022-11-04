#include<bits/stdc++.h>
using namespace std;
double x[200], y[200], H, dist[200][200];
 
double gd(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
bool check(int l, int r, double Y)
{
	for(int i = l; i <= r; i++)
		if(Y < y[i] - 1e-9 || Y > y[i] + H + 1e-9)
			return false;
	return true;
}
 
bool valid(double x1, double y1, double x2, double y2, int l, int r)
{
	for(int i = l; i <= r; i++)
	{
		double cx = x[i];
		double qy = (cx - x1) * (y2 - y1) / (x2 - x1) + y1;
		if(qy < y[i] - 1e-9 || qy > y[i] + H + 1e-9)
			return false;
	}
	return true;
}
 
int main()
{	
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++)
		cin >> x[i] >> y[i];
	cin >> H;
 	for(int i = 0; i <= n; i++)
		dist[i][0] = dist[i][1] = 1000000000;
 	dist[0][0] = dist[0][1] = 0;
 	for(int i = 1; i <= n; i++)
	{
		if(check(0, i - 1, y[i]))
			dist[i][0] = min(dist[i][0], x[i] - x[0]);
		if(check(0, i - 1, y[i] + H))
			dist[i][1] = min(dist[i][1], x[i] - x[0]);
	}
 	for(int i = 0; i < n; i++)
		for(int j = 0; j <= 1; j++)
			for(int q = i + 1; q <= n; q++)
				for(int w = 0; w <= 1; w++)
				{
					double x1, y1, x2, y2;
					x1 = x[i];
					y1 = y[i] + H * j;
					x2 = x[q];
					y2 = y[q] + H * w;
					if(valid(x1, y1, x2, y2, i + 1, q - 1))
						dist[q][w] = min(dist[q][w], dist[i][j] + gd(x1, y1, x2, y2));
				}
	double ans = 1000000000;
	for(int i = 0; i <= n; i++)
	{
		if(check(i + 1, n, y[i]))
			ans = min(ans, dist[i][0] + x[n] - x[i]);
		if(check(i + 1, n, y[i] + H))
			ans = min(ans, dist[i][1] + x[n] - x[i]);
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}

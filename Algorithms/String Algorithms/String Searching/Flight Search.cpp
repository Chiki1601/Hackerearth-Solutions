#include<bits/stdc++.h> 
using namespace std;
string source, destination;
vector<pair<string, int>> masterRoutes;
 
void routes(string current, string pathTillNow, int costTillNow, unordered_map<string, vector<pair<string, int>>> &mpp, unordered_set<string> pathsTaken) 
{
	if(pathsTaken.find(current) != pathsTaken.end()) 
		return ;
	pathsTaken.insert(current);
 	if(current == destination) 
	{
		pathTillNow = pathTillNow;
		masterRoutes.push_back({pathTillNow, costTillNow});
		return;
	}
	for(auto x: mpp[current]) 
		routes(x.first, pathTillNow + " " + x.first, costTillNow + x.second, mpp, pathsTaken);
}
 
static bool comparator(pair<string, int> &p1, pair<string, int> &p2) 
{
	if(p1.second != p2.second) 
		return p1.second < p2.second; 
	int space1 = count(p1.first.begin(), p1.first.end(), ' '), space2 = count(p2.first.begin(), p2.first.end(), ' ');
	if(space1 != space2) 
		return space1 < space2; 
	return p1.first < p2.first;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> source >> destination;
 	string tempSource, tempDest;
	int cost;
   	unordered_map<string, vector<pair<string, int>>> mpp;
 	while(cin >> tempSource >> tempDest >> cost) 
	{
		if(mpp.find(tempSource) == mpp.end())
			mpp[tempSource] = vector<pair<string, int>> ({{tempDest, cost}});
		else
			mpp[tempSource].push_back({tempDest, cost});
	}
 	routes(source, source, 0, mpp, unordered_set<string> ());
 	sort(masterRoutes.begin(), masterRoutes.end(), comparator);
 	for(auto x : masterRoutes) 
		cout << x.first << " " << x.second << endl;
	if(masterRoutes.empty()) 
		cout << "No Flights" << endl;
}

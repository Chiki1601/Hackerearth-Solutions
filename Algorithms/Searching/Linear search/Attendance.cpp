#include <bits/stdc++.h>
using namespace std;
 
int timeToInt(string s) 
{
	int ans = 0;
	ans += stoi(s.substr(0, 2)) * 60 * 60;
	ans += stoi(s.substr(3, 5)) * 60; 
	ans += stoi(s.substr(6, 8)); 
	return ans;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, startTime, endTime, nStudents[timeToInt("24:00:00")],m, id, minStudents = 9999999, nMin = 0, selfGood = 0;
	string sstartTime, sendTime, s, e;
	cin >> N;   
	cin >> sstartTime >> sendTime;
	startTime = timeToInt(sstartTime);
	endTime = timeToInt(sendTime);
	vector<pair<int, int>> times;
	for(int i = 0; i < N; i++) 
    {
		cin >> id >> m;
		for(int j = 0; j < m; j++) 
        {
			cin >> s >> e;
			if(id == 1) 
				times.push_back(make_pair(timeToInt(s), timeToInt(e)));
			for(int k = timeToInt(s); k < timeToInt(e); k++) 
				nStudents[k] += 1;
		}
	}
	for(int i = startTime; i < endTime; i++) 
    {
		if(nStudents[i] < minStudents) 
        {
			minStudents = nStudents[i];
			nMin = 1;
		} 
        else if(nStudents[i] == minStudents) 
			nMin += 1;
	}
	for(int i = 0; i < times.size(); i++) 
    {
		for(int j = times.at(i).first; j < times.at(i).second; j++) 
        {
			if(nStudents[j] == minStudents) 
				selfGood += 1;
		}
	}
	if(selfGood == 0) 
		cout << "0\n";
	else 
    {
		int g = __gcd(selfGood, nMin);
		cout << (int)(selfGood/g) << "/" << (int)(nMin/g) << "\n";	
	}
}

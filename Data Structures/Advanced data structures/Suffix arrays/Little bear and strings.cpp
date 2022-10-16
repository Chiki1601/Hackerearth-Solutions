#include<bits/stdc++.h> 
using namespace std;
char str[300005], t1[300005], t2[300005];  
int suf[300005], group[300005], sorGroup[300005], groupStart[300005], newSuf[300005], n, Rank[300005], lcp[300005];  
 
void print_suffix(int suf_pos) 
{
    for(int j = suf_pos; j < n - 1; ++j) 
        cout << str[j];
}
 
int lowerBound(char *pat) 
{
    int l = 0 , r = n, len = (int)strlen(pat);
    while(l < r) 
	{
        int mid = (r + l) / 2 + 1;
        int x = strncmp(str + suf[mid], pat, len);
        if(x >= 0) 
			r = mid - 1;
        else 
			l = mid;
    }
    if(strncmp(str + suf[l + 1], pat, len)) 
		return -1;
    return l+1;
}
 
int upperBound(char *pat) 
{
    int l = 0, r = n, len = (int)strlen(pat);
    while (l < r) 
	{
        int mid = (l + r) / 2;
        int x = strncmp(str + suf[mid], pat, len);
        if(x > 0) 
			r = mid;
        else 
			l = mid + 1;
    }
    if(strncmp(str + suf[l - 1], pat, len)) 
		return -1;
    return l - 1;
}
 
int main()
{
	while(scanf("%s%s%s", str, t1, t2) != EOF) 
	{
        n = 0;
		memset(sorGroup, -1, (sizeof sorGroup[0]) * 128);
		for(n = 0; n - 1 < 0 || str[n - 1]; n++)
			newSuf[n] = sorGroup[str[n]], sorGroup[str[n]] = n;
		int numGroup = -1, j = 0, c = 0;
		for(int i = 0; i < 128; i++) 
		{
			if(sorGroup[i] != -1) 
			{
				groupStart[++numGroup] = j;
				int cur = sorGroup[i];
				while(cur != -1) 
				{
					suf[j++] = cur;
					group[cur] = numGroup;
					cur = newSuf[cur];
				}
			}
		}
		sorGroup[0] = sorGroup[n - 1] = 0;  
		newSuf[0] = suf[0];  
		for(int h = 1; sorGroup[n - 1] != n - 1; h <<= 1) 
		{
			for(int i = 0; i < n; i++) 
			{  
				int j = suf[i] - h;
				if(j < 0)
					continue;
				newSuf[groupStart[group[j]]++] = j;
			}
			for(int i = 1; i < n; i++) 
			{  
				bool newgroup = group[newSuf[i - 1]] < group[newSuf[i]] || (group[newSuf[i - 1]] == group[newSuf[i]] && group[newSuf[i - 1] + h] < group[newSuf[i] + h]);
				sorGroup[i] = sorGroup[i - 1] + newgroup;
				if(newgroup)
					groupStart[sorGroup[i]] = i;
			}
			for(int i = 0; i < n; i++) 
			{  
				suf[i] = newSuf[i];
				group[suf[i]] = sorGroup[i];
			}
		}
		if(false) 
		{
			for(int i = 0; i <= (int)(n - 1); i++)
			{
				printf("%d\t",i);
				print_suffix(suf[i]);
				printf("\t%d\n",suf[i]);
			}
		} 
		for(int i = 0; i - 1 < 0 || str[i - 1]; i++)
        	Rank[suf[i]] = i;  
		for(int i = 0; i - 1 < 0 || str[i - 1]; i++) 
		{
			if(Rank[i]) 
			{  
				int j = suf[Rank[i] - 1];  
				while (str[i + c] == str[j + c])
					c++;  
			}
			lcp[Rank[i]] = c;  
			if(c)
				c--;  
		}
        int l = lowerBound(t2), r = upperBound(t2);
        if(l == -1 || r == -1) 
		{
            cout << "0" << endl;
            continue;
        }
        vector<int> occ;
        for(int i = l; i <= (int)(r); i++)
			occ.push_back(suf[i]);
        sort(occ.begin(), occ.end());
        l = lowerBound(t1), r = upperBound(t1);
        if(l == -1 || r == -1) 
		{
            cout << "0" << endl;
            continue;
        }
        int m1 = (int) strlen(t1), m2  = (int) strlen(t2);
        long long ans = (int)(occ.end() - lower_bound(occ.begin(), occ.end(),suf[l]+max(m1-m2,0)));
        for(int i = l + 1; i <= (int)(r); i++)
		{
            int lc = suf[i] + max(0, max(lcp[i] - m2 + 1 , m1 - m2 - 1));
            ans += (int) (occ.end() - lower_bound(occ.begin(), occ.end(), lc));
        }
        cout << ans << endl;
        memset(suf, 0, sizeof suf); 
		memset(lcp, 0, sizeof lcp); 
		memset(newSuf, 0, sizeof newSuf);
    }
    return 0;
}

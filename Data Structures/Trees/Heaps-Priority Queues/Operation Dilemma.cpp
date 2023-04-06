#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T; 
    cin >> T;
    for(int t = 0; t < T; t++) 
    {
        int N, L, K, pqAsize = 0, pqBsize = 0, l = 0; 
        cin >> N >> L >> K;
        vector<int> a(N), b(N);
        for(int i = 0; i < N; i++) 
            cin >> a[i];
        for(int i = 0; i < N; i++)     
            cin >> b[i];
        priority_queue<vector<int>> pqA, pqB;
        long long sumA = 0, sumB1 = 0, sumB2 = 0, res = 0;
        vector<bool> inPQA(N), inPQB(N);
        fill(begin(inPQA), end(inPQA), false); 
        fill(begin(inPQB), end(inPQB), false); 
        for(int r = 0; r < N; r++) 
        {
            sumA += a[r];
            pqB.push({b[r], r});
            sumB2 += b[r];
            inPQB[r] = true;
            pqBsize++;
            if(l < r - L + 1) 
            {
                sumA -= a[l];
                if(inPQA[l]) 
                {
                    pqAsize--;
                    sumB1 -= b[l];
                } 
                else 
                {
                    pqBsize--;
                    sumB2 -= b[l];
                }
                l++;
            }
            while(pqAsize < K && !pqB.empty() && b[pqB.top()[1]] > 0) 
            {
                int i = pqB.top()[1]; pqB.pop();
                pqA.push({-b[i], i});
                inPQA[i] = true;
                inPQB[i] = false;
                sumB1 += b[i];
                sumB2 -= b[i];
                pqAsize++;
                pqBsize--;
            }
            while(!pqA.empty() && pqA.top()[1] < l) 
                pqA.pop();
            while(!pqB.empty() && pqB.top()[1] < l) 
                pqB.pop();
            while(!pqA.empty() && !pqB.empty() && b[pqA.top()[1]] < b[pqB.top()[1]]) 
            {
                int aToB = pqA.top()[1], bToA = pqB.top()[1];
                pqA.pop(); 
				pqB.pop();
                sumB1 -= b[aToB];
                sumB2 += b[aToB];
                sumB1 += b[bToA];
                sumB2 -= b[bToA];
                inPQA[aToB] = inPQB[bToA] = false;
                inPQB[aToB] = inPQA[bToA] = true;
                pqA.push({-b[bToA], bToA});
                pqB.push({b[aToB], aToB});
                while(!pqA.empty() && pqA.top()[1] < l) 
                    pqA.pop();
                while(!pqB.empty() && pqB.top()[1] < l) 
                    pqB.pop();
            }
            if(r - l + 1 == L) 
                res = max(res, sumA + sumB1 - sumB2);
        }
        cout << res << "\n";
    }  
    return 0;
}

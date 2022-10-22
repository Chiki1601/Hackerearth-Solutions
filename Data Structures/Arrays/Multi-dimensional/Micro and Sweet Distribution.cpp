#include<bits/stdc++.h>
using namespace std;
#define pin(s) {cout<<(s)<<endl;continue;}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, N, M, sx, sy, dx, dy;
    cin >> T;
    while(T--)
    {
        cin >> N >> M >> sx >> sy >> dx >> dy;
        int ox = N + 1 - sx, oy = N % 2 == 0 ? sy : M + 1 - sy;
        if(ox == dx and oy == dy)
            pin("Over")
        if((dx - sx) % 2 == 0 and dy == M + 1 - sy or (dx - sx) % 2 != 0 and dy == sy)
            pin(sx == 1 ? "Back" : "Front")
        if((dx - sx) % 2 == 0)
            pin(sy == 1 ? "Right" : "Left")
        else 
            pin(sy == M ? "Right" : "Left")
    }
}

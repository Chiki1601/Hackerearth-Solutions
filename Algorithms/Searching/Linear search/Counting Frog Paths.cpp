#include <bits/stdc++.h>
 
using namespace std;
 
 
string twodig(int i){
    string res = "";
    while(i>0){
        res = char('0' + i%10) + res;
        i/=10;
    }
    while(res.length() < 2) res = "0"+res;
    return res;
}
int solve(int X, int Y, int s, int T){
    int counter = 0;
    for(int positionX = X; positionX <= X+s; positionX++){
        for(int positionY = Y; positionY <= Y+s; positionY++){
            if(positionY + positionX <= T){
                counter++;
            }
        }
    }
    return counter;
}
void gen(){
    int iters = 50;
    for(int i = 6; i <= iters; i++){
        ofstream fout("in"+twodig(i)+".txt");
        int x = rand()%101, y = rand()%101, s = (1 + rand()%100), t = rand()%401;
        fout << x << " " << y << " "<< s << " " << t << endl;
        fout.close();
    }
}
void solveall(){
    int iters = 50;
    for(int i = 1; i <= iters; i++){
        ifstream fin("in"+twodig(i)+".txt");
        int x,y,s,t;
        fin >> x >> y >> s >> t;
        int ans = solve(x,y,s,t);
        ofstream fout("out"+twodig(i)+".txt");
        fout << ans << endl;
        fout.close();
        fin.close();
    }
}
void validateall(){
    int iters = 50;
    for(int i = 1; i <= iters; i++){
        ifstream fin("in"+twodig(i)+".txt");
        int x,y,s,t;
        fin >> x >> y >> s >> t;
        assert(0<=x);
        assert(x<=100);
        assert(0<=y);
        assert(y<=100);
        assert(1<=s);
        assert(s<=100);
        assert(0<=t);
        assert(t<=400);
    }
}
int main()
{
    int x,y,s,t;
    cin >> x >> y >> s >> t;
    cout << solve(x,y,s,t) << endl;
}

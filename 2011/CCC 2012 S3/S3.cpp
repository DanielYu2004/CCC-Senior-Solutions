#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> base = {
    {"empty", "crystal", "crystal", "crystal", "empty"},
    {"empty", "continue", "crystal", "continue", "empty"},
    {"empty", "empty", "continue", "empty", "empty"},
    {"empty", "empty", "empty", "empty", "empty"},
    {"empty", "empty", "empty", "empty", "empty"}
};

vector<vector<string>> base2 = {
    {"empty", "crystal", "crystal", "crystal", "empty"},
    {"empty", "empty", "crystal", "empty", "empty"},
    {"empty", "empty", "empty", "empty", "empty"},
    {"empty", "empty", "empty", "empty", "empty"},
    {"empty", "empty", "empty", "empty", "empty"}
};

string recur(int x, int y, int cur_mag){
    if (cur_mag == 1){
        return base2[y][x];
    } else{
        int localX = floor(((x)/(double)pow (5, cur_mag - 1))); // 0 - 4
        int localY = floor(((y)/(double)pow (5, cur_mag - 1))); // 0 - 4
        
        if (base[localY][localX] == "crystal"){
            return "crystal";
        } else if (base[localY][localX] == "empty"){
            return "empty";
        } else{
            int newX = x - (localX) * pow(5, cur_mag-1);
            int newY = y - (localY) * pow(5, cur_mag-1);
            return recur(newX, newY, cur_mag - 1);
        }
    }
}

void solve(){
    int m, x ,y;
    cin >> m >> x >> y;
    cout << recur(x,y,m) << "\n";
}

int main(){
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        solve();
    }
}
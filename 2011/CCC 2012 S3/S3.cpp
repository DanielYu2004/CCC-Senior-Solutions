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
    // cout << x << " " << y << "\n";
    if (cur_mag == 1){
        // cout << x << y;
        return base2[y][x];
    } else{
        int localX = floor(((x)/(double)pow (5, cur_mag - 1))); // 0 - 4
        int localY = floor(((y)/(double)pow (5, cur_mag - 1))); // 0 - 4
        
        // cout << localX << " " << localY << "\n";
        if (base[localY][localX] == "crystal"){
            return "crystal";
        } else if (base[localY][localX] == "empty"){
            return "empty";
        } else{
            // if (base[localX][localY] == "empty"){
            //     return "empty";
            // }else if (base[localX][localY] == "crystal"){
            //     return "crystal";
            // } else{
            int newX = x - (localX) * pow(5, cur_mag-1);
            int newY = y - (localY) * pow(5, cur_mag-1);
            // cout << localX << " " << localY << "\n";
            // cout << newX << " " << newY << "\n";
            return recur(newX, newY, cur_mag - 1);
            // }
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
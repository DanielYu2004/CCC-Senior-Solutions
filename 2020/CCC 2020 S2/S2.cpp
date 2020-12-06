#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
set<int> visited;
int endd;
bool key_exists(int key){
    if (mp.find(key) != mp.end()){
        return true;
    }
    return false;
}
string recur(vector<int> keys){
    vector<int> next_keys;
    if (keys.size() == 0){
        return "no";
    }

    for (auto key : keys){
        if (visited.find(key) == visited.end()){
            visited.insert(key);
            if (key == endd){
                return "yes";
            } else{
                if (key_exists(key)){
                    for (auto next_key : mp[key]){
                        next_keys.push_back(next_key);
                    }
                }
            }
        }
    }
    return recur(next_keys);
}
int main(){
    int n, m;
    cin >> m >> n;
    int temp;
    for (int a = 1; a < m+1; a++){
        for (int b = 1; b < n+1; b++){
            cin >> temp;
            
            if (a == 1 && b == 1){
                endd = temp;
            }

            if (key_exists(temp)){
                mp[temp].push_back(a*b);
            } else{
                mp[temp] = {a*b};
            }
        }
    }
    vector<int> start;
    start.push_back(m * n);
    cout << recur(start);
    return 0;
}
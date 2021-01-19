#include <bits/stdc++.h>

using namespace std;

bool compare_str(string pre, string whole){
    if (pre.size() <= whole.size()){
        for (int i = 0; i < pre.size(); i++){
            if (pre[i] != whole[i]){
                return false;
            }
        }
        return true;
    } else{
        return false;
    }
    
}


int main(){


    int n;
    cin >> n;
    string code;
    string sol = "";
    map<string, string> map;

    for (int i = 0; i < n; i++){
        string key;
        string value;
        cin >> key >> value;

        map[key] = value;
    }

    cin >> code;
    while (code.size() != 0){
        for (auto x : map){
            // cout << is_prefix(x.second, code);
            if (code.size() == 0){
                break;
            }
            if (compare_str(x.second, code)){
                code = code.substr(x.second.size());
                sol += x.first;
            }
            // cout << code << "\n";
            
        }
    }
    

    cout << sol;

}
#include <bits/stdc++.h>

using namespace std;

string n;
map<char, int> needle;

bool is_perm(string s){
    map<char, int> cur_needle = {
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0},
    };
    for (int i = 0; i < s.size(); i++){
        cur_needle[s[i]]++;
        if (cur_needle[s[i]] > needle[s[i]]){
            return false;
        }
    }

    if (cur_needle == needle){
        return true;
    } else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    hash<string> hasher;

    string h;

    cin >> n >> h;
    // ifstream myfile ("s3.4-37.txt");
    // if (myfile.is_open())
    // {
    //     getline(myfile, n);
    //     getline(myfile, h);
    //     myfile.close();
    // }

    needle = {
        {'a', 0},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 0},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 0},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 0},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 0},
        {'z', 0},
    };

    // cout << n.size();

    if (n.size() > h.size()){
        cout << 0;
    } else{
            for (int i = 0; i < n.size(); i++){
            needle[n[i]]++;
        }

        set<size_t> visited;
        map<char, int> cur_needle = {
            {'a', 0},
            {'b', 0},
            {'c', 0},
            {'d', 0},
            {'e', 0},
            {'f', 0},
            {'g', 0},
            {'h', 0},
            {'i', 0},
            {'j', 0},
            {'k', 0},
            {'l', 0},
            {'m', 0},
            {'n', 0},
            {'o', 0},
            {'p', 0},
            {'q', 0},
            {'r', 0},
            {'s', 0},
            {'t', 0},
            {'u', 0},
            {'v', 0},
            {'w', 0},
            {'x', 0},
            {'y', 0},
            {'z', 0},
        };
        
        for (int i = 0; i < n.size(); i++){
            cur_needle[h[i]]++;
        }

        if (cur_needle == needle){
            visited.insert(hasher(h.substr(0, n.size())));
        }

        // cout << "a: " << cur_needle['a'] << "b: " << cur_needle['b'] << "c: " << cur_needle['c'] << "\n"; 

        for (int i = 1; i < h.size() - n.size(); i++){
            cur_needle[h[i-1]]--;
            cur_needle[h[i + n.size()-1]]++;
            string window = h.substr(i, n.size());
            // cout << "a: " << cur_needle['a'] << " b: " << cur_needle['b'] << " c: " << cur_needle['c'] << " "; 
            // cout << window << "\n";
            if (cur_needle == needle && visited.find(hasher(window)) == visited.end()){
                visited.insert(hasher(window));
            }
            // cout << h.substr(i, n.size()) << "\n";
            // if (visited.find(h.substr(i, n.size())) == visited.end() && is_perm(h.substr(i, n.size()))){
            //     visited.insert(h.substr(i,n.size()));
            // }
        }
        if (h.size() - n.size() >= 1){
            cur_needle[h[h.size() - n.size() -1]]--;
            cur_needle[h[h.size()-1]]++;
            if (cur_needle == needle && visited.find(hasher(h.substr(h.size() - n.size(), n.size()))) == visited.end()){
                visited.insert(hasher(h.substr(h.size() - n.size(), n.size())));
            }
        }
        

        // for (auto x: visited){
        //     cout << x;
        // }

        cout << visited.size();
    }

    


    return 0;
}
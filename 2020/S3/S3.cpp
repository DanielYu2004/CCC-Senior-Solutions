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

        for (int i = 1; i < h.size() - n.size(); i++){
            cur_needle[h[i-1]]--;
            cur_needle[h[i + n.size()-1]]++;
            string window = h.substr(i, n.size());
            if (cur_needle == needle && visited.find(hasher(window)) == visited.end()){
                visited.insert(hasher(window));
            }
        }
        if (h.size() - n.size() >= 1){
            cur_needle[h[h.size() - n.size() -1]]--;
            cur_needle[h[h.size()-1]]++;
            if (cur_needle == needle && visited.find(hasher(h.substr(h.size() - n.size(), n.size()))) == visited.end()){
                visited.insert(hasher(h.substr(h.size() - n.size(), n.size())));
            }
        }

        cout << visited.size();
    }

    


    return 0;
}
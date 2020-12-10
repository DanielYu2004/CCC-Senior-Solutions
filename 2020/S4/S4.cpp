#include <bits/stdc++.h>

using namespace std;

unordered_set<size_t> visited;
hash<string> hasher;
bool is_happy(string s){
    int counter = 0;
    while(s[s.size()-1] == s[0]){
        counter++;
        char character = s[0];
        s.erase(s.size()-1, 1);
        s.insert(s.begin(), character);
        if (counter > s.size()){
            return true;
        }
    }

    set<char> visited;
    char prev_char = s[0];
    char character = s[0];
    for (int i = 0; i < s.size(); i++){
        if (character == prev_char){
            // continue
            prev_char = s[i];
            character = s[i+1];
        } else if (visited.find(character) == visited.end()){
            visited.insert(character);
            prev_char = s[i];
            character = s[i+1];
        } else{
            return false;
        }
    }

    return true;
}


int recur(queue<string> strings, int steps){
    
    
    queue<string> next_strings;

    // while(!strings.empty()){
	// 	cout<<" "<<strings.front();
	// 	strings.pop();
	// }
    cout << steps;

    while(!strings.empty()){
        string cur_string = strings.front();
        // cout << cur_string << "\n";
        if (visited.find(hasher(cur_string)) == visited.end()){
            cout << "CURRENT: " <<  cur_string << "\n";
            visited.insert(hasher(cur_string));
            if (is_happy(cur_string)){
                // cout << cur_string;
                return steps;
            } else{

                for (int i = 0; i < cur_string.size() - 1; i++){
                    for (int ii = i + 1; ii < cur_string.size(); ii++){
                        if (cur_string[i] != cur_string[ii]){
                            string new_string = cur_string;
                            swap(new_string[i], new_string[ii]);
                            if (visited.find(hasher(new_string)) == visited.end()){
                                // visited.insert(new_string);
                                next_strings.push(new_string);
                                // cout << "PUSHING: " << new_string << "\n";
                            }
                            
                        }
                    }
                }

            }
        }
        strings.pop();
    }



    
    return recur(next_strings, steps+1);

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string s;

    cin >> s;

    queue<string> start;
    start.push(s);

    cout << recur(start, 1) - 1;

    
    return 0;
}
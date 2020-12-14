#include <bits/stdc++.h>

using namespace std;

// vector<int> primes;
set<int> primes;


pair<int,int> solve(int target){
    std::unordered_map<int, int> map;

    target = target * 2;
    // for (int i = 0; i < primes.size(); i++){
    //     int cur = primes[i];
    //     if ( find(primes.begin(), primes.end(), target - cur) != primes.end()){
    //         return make_pair(cur, target-cur);
    //     }
    // }
    for (auto cur: primes){

        if (map.find(cur) != map.end()){
            return make_pair(cur, target-cur);
        } else{
            map[target-cur] = cur;
        }

        // int find = target - cur;
        // if (primes.find(find) != primes.end()){
        //     return make_pair(cur, find);
        // }
    }
    return make_pair(0,0);
}

int main(){

    int length = 1000000;

    int n;
    cin >> n;
    vector<int> sols(n);

    for (int i = 0; i < n; i++){
        cin >> sols[i];
    }

    vector<int> numbers(length + 1, 1);

    for (int i = 2; i < sqrt(length) + 1; i++){
        for (int t = 2*i; t < length + 1; t+=i){
            numbers[t] = 0;
        }
    }



    for (int i = 2; i < numbers.size(); i++){
        if (numbers[i] == 1){
            primes.insert(i);
        }
    }


    for (int i = 0; i < sols.size(); i++){
        pair<int,int> sol = solve(sols[i]);
        cout << sol.first << " " << sol.second << "\n";
    }




    return 0;
}
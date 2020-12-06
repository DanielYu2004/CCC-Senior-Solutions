#include <bits/stdc++.h>

using namespace std;

vector<string> types = {"ON", "OP", "AN", "AP", "BN", "BP", "ABN", "ABP"};
map<string, int> supply;
map<string, int> people;
int max_sol = 0;   

void print_map(map<string, int> map){
    for (auto x : map){
        cout << x.first << " " << x.second << "\n";
    }
}

void give(string type, vector<string> array){
    for (auto x : array){
        if (people[type] > 0){
            int to_give = min(people[type], supply[x]);
            people[type] -= to_give;
            supply[x] -= to_give;
            max_sol += to_give;
        }
    }
}

int main(){

 

    for (int i = 0; i < types.size(); i++){
        supply[types[i]] = 0;
        people[types[i]] = 0;

        cin >> supply[types[i]];
    }
    for (int i = 0; i < types.size(); i++){
        cin >> people[types[i]];
    }

    // O-Negative
    give("ON", {"ON"});

    // A-Negative
    give("AN", {"AN", "ON"});

    // B-Negative
    give("BN", {"BN", "ON"});

    // AB Negative
    give("ABN", {"ABN", "AN", "BN", "ON"});

    // O-Positive
    give("OP", {"OP", "ON"});

    // A-Positive
    // give("AP", {"ON", "OP", "AN", "AP"});
    give("AP", {"AP", "AN", "ON", "OP", });

    // B-Positive
    give("BP", {"BP","BN", "ON", "OP"});

    // AB-Positive
    give("ABP", {"ON", "OP", "AN", "AP", "BN", "BP", "ABN", "ABP"});


    // print_map(people);
    // print_map(supply);

    // // O-Negative
    // if (supply["ON"] >= people["ON"]){
    //     max_sol += people["ON"];
    //     supply["ON"] -= people["ON"];
    //     people["ON"] -= people["ON"];
    // } else{
    //     people["ON"] -= supply["ON"];
    //     supply["ON"] -= supply["ON"];
    //     max_sol += supply["ON"];
    // }
    cout << max_sol;



    // print_map(supply);
    // print_map(people);

    return 0;
}